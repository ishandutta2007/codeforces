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

int A[4][4];

signed main(){
    rep(i,4)rep(j,4)cin>>A[i][j];
    bool ng=false;
    ng|=A[0][3]&&(A[1][0]||A[2][1]||A[3][2]||A[0][0]||A[0][1]||A[0][2]);
    ng|=A[1][3]&&(A[2][0]||A[3][1]||A[0][2]||A[1][0]||A[1][1]||A[1][2]);
    ng|=A[2][3]&&(A[3][0]||A[0][1]||A[1][2]||A[2][0]||A[2][1]||A[2][2]);
    ng|=A[3][3]&&(A[0][0]||A[1][1]||A[2][2]||A[3][0]||A[3][1]||A[3][2]);

    if(ng)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}