

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
// Please write the recurances once :(
void pre(){}
ll helper(vector<pii>ppl,set<ll>x){
    int i = 0;
    ll ans = 0 ;
    ll till = 0;
    map<int,int>count;
    for(auto j:x){
        count.clear();
        till = 0;
        while(i<ppl.size() && ppl[i].F<j){
            count[ppl[i].S]++;
            i++;
            till++;
        }
        ans += (till*(till-1))/2;
        for(auto i:count){
            ans-=(i.S*(i.S-1))/2;
        }
    }
    return ans;
}
void solve(){
    ll n,m,k;cin>>n>>m>>k;
    set<ll>x,y;
    ll d,p;
    for(int i=0;i<n;i++){
        cin>>d;
        x.insert(d);
    }
    for(int i=0;i<m;i++){
        cin>>d;
        y.insert(d);
    }
    vector<pii>pplx;
    vector<pii>pply;
    for(int i=0;i<k;i++){
        cin>>d>>p;
        if(x.find(d)!=x.end() && y.find(p)!=y.end())
            continue;
        else if(x.find(d)!=x.end())
            pplx.push_back({p,d});
        else 
            pply.push_back({d,p});
    }
    sort(pplx.begin(),pplx.end());
    sort(pply.begin(),pply.end());
    cout<<helper(pplx,y)+helper(pply,x)<<"\n";
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