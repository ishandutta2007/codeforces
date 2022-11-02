#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}
const int mod=1000000007;
typedef vector<int>vec;
typedef vector<vec>mat;


int mod_pow(int n,int m){
    int ret=1;
    while(m){
        if(m&1)ret=ret*n%mod;
        n=n*n%mod;
        m>>=1;
    }
    return ret;
}

mat mul(const mat &A,const mat &B){
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<A.size();i++){
        for(int j=0;j<B[0].size();j++){
            for(int k=0;k<A[0].size();k++){
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%mod;
            }
        }
    }
    return C;
}

mat mat_pow(mat A,int m){
    mat B(A.size(),vec(A.size()));
    for(int i=0;i<A.size();i++)B[i][i]=1;
    while(m){
        if(m&1)B=mul(B,A);
        A=mul(A,A);
        m>>=1;
    }
    return B;
}

signed main(){
    int N,K;
    cin>>N>>K;

    vint A(N),B(N),C(N);
    rep(i,N)cin>>A[i]>>B[i]>>C[i];

    vint X(16);
    X[0]=1;

    for(int i=0;i<N;i++){
        chmin(B[i],K);
        mat a(C[i]+1,vec(C[i]+1));
        mat x(C[i]+1,vec(1));
        for(int j=0;j<=C[i];j++)x[j][0]=X[j];
        for(int j=0;j<=C[i];j++){
            for(int k=-1;k<=1;k++){
                if(j+k>=0&&j+k<=C[i])a[j][j+k]=1;
            }
        }

        x=mul(mat_pow(a,B[i]-A[i]),x);

        fill(all(X),0);
        for(int j=0;j<=C[i];j++)X[j]=x[j][0];
    }

    cout<<X[0]<<endl;
    return 0;
}