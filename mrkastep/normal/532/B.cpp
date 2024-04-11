#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define ll long long int


const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;

typedef pair<int,int> point;

vector<vector<int>> g;
vector<vector<int>> ans;
vector<int> c;

pair<ll,ll> dfs(int v){
    vector<pair<ll,ll>> t;
    For(i,g[v].size()){
        t.pb(dfs(g[v][i]));
    }
    if(t.size()==0){
        return mp((ll)0,(ll)c[v]);
    }
    ll ans=0,ans1=0;
    pair<ll,ll> p;
    int chet=0;
    For(i,t.size()){
        if(t[i].x<t[i].y){
            chet=1-chet;
            ans+=t[i].y;
        }
        else{
            ans+=t[i].x;
        }
    }
    For(i,t.size()){
        ans1=max((ll)ans1,ans-abs(t[i].x-t[i].y));
    }
    if(chet==1){
        p.y=ans;
        p.x=ans1;
    }
    else{
        p.x=ans;
        p.y=ans1;
    }
    p.y=max(p.y,c[v]+p.x);
    return p;


}









void solve(ll n){
    g.resize(n);
    int p,a;
    For(i,n){
        scanf("%d%d",&p,&a);
        if(i!=0){
            g[p-1].pb(i);
        }
        c.pb(a);
    }
    pair<ll,ll> ans;
    ans=dfs(0);
    printf("%I64d",max(ans.x,ans.y));




}


int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
    while(scanf("%I64d",&a)==1) solve(a);

    return 0;
}