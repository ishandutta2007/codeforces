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

    int a,b,n;cin>>n>>a>>b;
    for(int i=min(a,b);i>0;i--){
        int tmp=a/i+b/i;
        if(tmp>=n){
            cout<<i<<endl;
            return 0;
        }
    }
}