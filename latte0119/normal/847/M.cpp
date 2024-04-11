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

signed main(){
    int N;cin>>N;
    vint A(N);
    rep(i,N)cin>>A[i];

    int d=A[1]-A[0];
    rep(i,N-1){
        if(A[i+1]-A[i]!=d){
            cout<<A[N-1]<<endl;
            return 0;
        }
    }
    cout<<A[N-1]+d<<endl;
    return 0;
}