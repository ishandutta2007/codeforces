#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long ll;
using namespace std;
void pre(){}
void solve(){
    ll n,m,k,d;cin>>n>>m>>k;
    set<int>s;
    ll arr[k];
    for(int i=0;i<n;i++){
        s.insert(i+1);
    }
    for(int i=0;i<k;i++){
        cin>>arr[i];
        s.erase(arr[i]);
    }
    set<pair<int,int>>ans;
    if(s.size()==0){
        cout<<-1<<"\n";
        return;
    }
    int oo = arr[0];
    int bo = *s.begin();
    ans.insert({min(oo,bo),max(oo,bo)});
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(ans.size()==m){
                break;
            }
            if(i!=oo && j!=oo)
                ans.insert({i,j});
        }
    }
    for(auto i:s){
        if(ans.size()<m){
            ans.insert({min(i,oo),max(i,oo)});
        }
    }
    if(ans.size()<m){
        cout<<-1<<"\n";
        return;
    }
    //cout<<ans.size()<<"\n";
    for(auto i:ans){
        cout<<i.first<<" "<<i.second<<"\n"; 
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}