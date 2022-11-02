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
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

typedef vector<int>vec;
typedef vector<vec>mat;
const int mod=1000003;
mat mul(mat A,mat B){
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<C.size();i++){
        for(int j=0;j<C[0].size();j++){
            for(int k=0;k<A[0].size();k++){
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%mod;
            }
        }
    }
    return C;
}

mat mat_pow(mat A,int m){
    mat B(A.size(),vec(A.size()));
    rep(i,B.size())B[i][i]=1;
    while(m){
        if(m&1)B=mul(B,A);
        A=mul(A,A);
        m>>=1;
    }
    return B;
}

int C,W,H;

signed main(){
    cin>>C>>W>>H;
    mat A(W+1,vec(W+1));
    for(int i=0;i<W+1;i++)A[0][i]=1;
    for(int i=1;i<W+1;i++)A[i][i-1]=H;
    mat X(W+1,vec(1));
    X[0][0]=1;
    X=mul(mat_pow(A,C),X);
    int ans=0;
    for(int i=0;i<W+1;i++)ans=(ans+X[i][0])%mod;
    cout<<ans<<endl;
    return 0;
}