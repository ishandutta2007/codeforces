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
void solve(){
    ll k,b,n;cin>>k>>b>>n;
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    map<ll,ll>m;
    ll curr = 0;
    ll ans = 0;
    m[0]++;
    if(b==k-1){
        ll cur =0;
        for(int i=0;i<n;i++){
            cur=0;
            while(i<n && arr[i]==0){
                cur++;
                i++;
            }
            if(cur!=0){
                i--;
            }
            ans-=(cur*(cur+1))/2;
        }
    }
    if(b==0){
        ll cur =0;
        for(int i=0;i<n;i++){
            cur=0;
            while(i<n && arr[i]==0){
                cur++;
                i++;
            }
            if(cur!=0){
                i--;
            }
            ans+=(cur*(cur+1))/2;
        }
        cout<<ans<<"\n";
        return;
    }
    b%=(k-1);
    for(int i=0;i<n;i++){
        curr+=arr[i];
        curr%=(k-1);
        ans+=m[(curr-b+k-1)%(k-1)];
        //cout<<(curr-b+k-1)%(k-1)<<"\n";
        m[curr]++;
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}