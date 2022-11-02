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

int N;
int A[5555];

signed main(){
    cin>>N;
    rep(i,N)cin>>A[i],A[i]--;


    rep(i,N){
        int v=i;
        rep(j,3)v=A[v];
        if(v==i){
            cout<<"YES"<<endl;
        return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}