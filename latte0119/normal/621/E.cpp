#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

const int mod=1000000007;
typedef vector<vint>mat;
int N,B,K,X;

mat mul(mat A,mat B){
    mat C(A.size(),vint(B[0].size()));
    rep(i,C.size()){
        rep(j,C[0].size()){
            rep(k,B.size()){
                C[i][j]+=A[i][k]*B[k][j];
                C[i][j]%=mod;
            }
        }
    }
    return C;
}

mat mpow(mat A,int m){
    mat ret(A.size(),vint(A.size()));
    rep(i,A.size())ret[i][i]=1;
    while(m){
        if(m&1)ret=mul(ret,A);
        A=mul(A,A);
        m>>=1;
    }
    return ret;
}

signed main(){
    cin>>N>>B>>K>>X;
    int cnt[10]={};
    rep(i,N){
        int a;cin>>a;cnt[a]++;
    }

    mat A(X,vint(X));
    mat p(X,vint(1));p[0][0]=1;

    rep(i,X)rep(j,10){
        int d=(i*10+j)%X;
        A[d][i]+=cnt[j];
    }

    p=mul(mpow(A,B),p);
    cout<<p[K][0]<<endl;
    return 0;
}