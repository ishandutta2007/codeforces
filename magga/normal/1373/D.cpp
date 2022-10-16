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
ll curr;
long long int ans1(vector<long long int>v){
    ll ret = max(v[0],0ll);
    ll c = ret;
    for(int i=1;i<v.size();i++){
        c+=v[i];
        c=max(c,0ll);
        ret=max(ret,c);
    }
    return curr+ret;
}
void solve(){
    ll n;cin>>n;
    ll arr[n];
    curr = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i%2==0){
            curr+=arr[i];
            arr[i]*=-1;
        }
    }
    ll ans = curr;
    vector<long long int>v;
    if(n>1){
        for(int i=0;i+1<n;i+=2){
            v.push_back(arr[i]+arr[i+1]);
        }
        ans=max(ans,ans1(v));
    }   
    v.clear();
    if(n>2){
        for(int i=1;i+1<n;i+=2){
            v.push_back(arr[i]+arr[i+1]);
        }
        ans=max(ans,ans1(v));
        v.clear();
    }   
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}