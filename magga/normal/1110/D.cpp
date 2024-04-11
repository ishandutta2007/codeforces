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
typedef int ll;
using namespace std;
void pre(){}
map<tuple<int,int,int>,int> dp[1000003];
void solve(){
    ll n,m,d;cin>>n>>m;
    map<ll,ll>oo,op;
    for(int i=0;i<n;i++){
        cin>>d;
        op[d]++;
    }
    oo=op;
    ll ans = 0;
    int j,k,l;
    dp[0][{0,oo[1],oo[2]}]=ans;
    for(int i=0;i<=m+1;i++){
       for(auto o1:dp[i]){
            j = get<0>(o1.F); 
            k = get<1>(o1.F); 
            l = get<2>(o1.F); 
            d = min(min(j,min(k,l)),2);
            while(d>=0){
                dp[i+1][{k-d,l-d,oo[i+3]}]=max(dp[i+1][{k-d,l-d,oo[i+3]}],o1.S+(j-d)/3+d);
                d--;
            }
        }
    }
    for(auto i:dp[m+1]){
        ans=max(ans,i.S);
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}