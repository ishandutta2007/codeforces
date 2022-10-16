#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
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
ll query(pii a,ll b){
    cout<<"? "<<a.S-a.F+1<<" "<<1<<"\n";
    for(int i=a.F;i<=a.S;i++){
        cout<<i<<" ";
    }
    cout<<"\n";
    cout<<b<<"\n";
    cout.flush();
    ll ret = 0;
    cin>>ret;
    return ret;
}
void solve(){
    ll n;cin>>n;
    ll a = 0;
    for(int i=2;i<=n;i++){
        auto l = query({1,i-1},i);
        if(l==0){
            continue;
        }else{
            a = i;
            break;
        }
    }
    vector<ll>ans;
    ll start = 1;
    ll end = a-1;
    ll mid;
    while(end!=start){
        mid = (start+end+1)/2;
        ll b = query({start,mid-1},a);
        if(b==0){
            for(int i=start;i<mid;i++){
                ans.push_back(i);
            }
            start=mid;
        }else{
            for(int i=mid;i<=end;i++){
                ans.push_back(i);
            }
            end=mid-1;
        }
    }
    for(int i=a+1;i<=n;i++){
        auto l = query({i,i},a);
        if(l==0){
            ans.pb(i);
        }
    }
    cout<<"! "<<ans.size()<<" ";
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
    cout.flush();
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