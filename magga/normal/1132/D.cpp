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
ll n,k;
pii a[200000];
bool check(ll m){
    vector<pii> arr[k+2];
    for(int i=0;i<n;i++){
        arr[min(k+1,a[i].F/a[i].S+1)].push_back({a[i].S,a[i].F%a[i].S});
    }
    ll curr = 0;
    for(int i=1;i<k;i++){
        if(m==0 && arr[i].size()>0){
            return false;
        }
        curr++;
        for(auto j:arr[i]){
            ll oo = (j.F-j.S+m-1)/m;
            if(oo>curr){
                return false;
            }
            curr-=oo;
            arr[min(i+((j.S+m*oo)/j.F),k+1)].push_back({j.F,(j.S+m*oo)%j.F});
        }
    }
    return true;
}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i].F;
    for(int i=0;i<n;i++) cin>>a[i].S;
    ll start = 0,end = 1e13, mid,ans=-1;
    while(start<=end){
        mid = (start+end+1)/2;
        if(check(mid)){
            end = mid-1;
            ans = mid;
        }else{
            start = mid+1;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}