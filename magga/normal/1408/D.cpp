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
vector<int> dp[1000012];
int h[1000012];
set<pair<pii,pii>>event;
map<int,int>ma;
void solve(){
    int n,m;cin>>n>>m;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(ma.find(a)==ma.end()){
            ma[a]=b;
        }else{
            ma[a] = min(ma[a],b);
        }
    }
    vector<pair<int,int>>v;
    for(auto i:ma){
        v.push_back(i);
    }
    //V HAS ROBBERS
    multiset<int,greater<>>ms;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        ms.insert(b);
        dp[a+1].push_back(b);
    }
    ms.insert(-1);
    for(int i=0;i<=1e6;i++){
        for(auto j:dp[i]){
            ms.erase(ms.find(j));
        }
        h[i]=*ms.begin();
    }
    // h HAS optimum H for all i 
    set<int>s;
    map<int,int>hi;
    for(int i=0;i<=1e6+5;i++){
        if(h[i]!=h[i+1]){
            s.insert(i+1);
            hi[i+1] =  h[i];
        }
    }
    // s has all chamge points
    // hi has corresponding height
    s.insert(1e8);
    multiset<long long int,greater<>>opt;
    for(auto i:v){
        if(*s.lower_bound(i.F)!=1e8){
            if(i.S<=hi[*s.upper_bound(i.F)]){
                //cout<<*s.upper_bound(i.F)-i.F<<" "<<hi[*s.upper_bound(i.F)]-i.S+1<<"\n";
                event.insert({{*s.upper_bound(i.F)-i.F,hi[*s.upper_bound(i.F)]-i.S+1},{i.F,i.S}});
                opt.insert(hi[*s.upper_bound(i.F)]-i.S+1);
            }
        }
    }
    long long int ans = 1e18;
    opt.insert(0);
    for(long long int i=0;i<=1000010;i++){
        while(event.size()>0 && (*event.begin()).F.F==i ){
            auto k = *event.begin();
            event.erase(k);
            opt.erase(opt.find(k.F.S));
            if(*s.upper_bound(i+k.S.F)!=1e8){
                if(k.S.S<=hi[*s.upper_bound(i+k.S.F)]){
                    event.insert({{*s.upper_bound(i+k.S.F)-k.S.F,hi[*s.upper_bound(i+k.S.F)]-k.S.S+1},k.S});
                    opt.insert(hi[*s.upper_bound(i+k.S.F)]-k.S.S+1);
                }
            }
        }
        ans = min(ans,i+*opt.begin());
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}