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
typedef long long ll;
using namespace std;
void pre(){}
void solve(){
    ll n,d;cin>>n;
    multiset<int>l;
    ll a[n+1],b[n+1],c[n+1];
    for(int i=0;i<n;i++){
        cin>>d;
        a[d]=i;
    }    
    for(int i=0;i<n;i++){
        cin>>d;
        c[i]=d;
        b[d]=i;
    }  
    for(int i=1;i<=n;i++){
        l.insert(a[i]-b[i]);
    }
    ll ans[n+1];
    for(int i=0;i<n;i++){
        ans[i] = n;
        auto j = l.lower_bound(i);
        if(j!=l.end())
            ans[i] = abs(i-*j);
        if(j!=l.begin()){
            j--;
            ans[i]=min(ans[i],(ll)abs(i-*j));
        }
        l.erase(l.find(a[c[n-i-1]] - b[c[n-i-1]]));
        l.insert((a[c[n-i-1]] + n - b[c[n-i-1]]));
    }    
    ans[n]=ans[0];
    for(int i=n;i>0;i--){
        cout<<ans[i]<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();   
}