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

int Q;


void solve(){
    int c,m,x;
    scanf("%lld%lld%lld",&c,&m,&x);
    int lb=0,ub=min(c,m)+1;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        int xx=x+c-mid+m-mid;
        if(xx>=mid)lb=mid;
        else ub=mid;
    }
    cout<<lb<<endl;
}

signed main(){
    scanf("%lld",&Q);
    while(Q--)solve();
    
}