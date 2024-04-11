#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
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
ll n,m,k;
ll val = 1e10;
ll arr[100000];
bool check(ll a){
    int ans = 0;
    ll last = -1e10;
    for(int i=0;i<n;i++){
        if(arr[i]-last+1<=a){
            continue;
        }else{
            last=arr[i];
            ans++;
        }
    }
    if(ans<=k){
        val = min(ans*a,val);
        cout<<a<<" "<<ans<<"\n";
    }
    return ans<=k;
}
void solve(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll ans = n;
    sort(arr,arr+n);
    multiset<ll>m;
    for(int i=0;i<n-1;i++){
        m.insert(arr[i+1]-arr[i]-1);
    }
    ll val = n;
    while(val>k){
        val--;
        ans+=*m.begin();
        m.erase(m.begin());
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}