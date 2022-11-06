#include <bits/stdc++.h>
#include <assert.h>
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
#define all(x) x.begin(),x.end()
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
const ll mn=1<<7;
bool seen[mn];
set<ll> g[mn];
vector<ll> dp[mn];
void ae(ll x, ll y) {
    g[x].insert(y); g[y].insert(x);
}
vector<ll> query(ll x) {
    seen[x]=true;
    if (dp[x].size()>0) return dp[x];
    printf("? %d\n",x);
    fflush(stdout);
    vector<ll> ans;
    ll k; scanf("%d",&k);
    if (k==0) exit(0);
    for (ll i=0;i<k;i++) {
        ll y; scanf("%d",&y);
        ans.PB(y);
        ae(x,y);
    }
    return dp[x]=ans;
}
pll dfs(ll vtx, ll parent) {
    pll best=MP(1,vtx);
    for (auto &neigh:g[vtx]) {
        if (neigh==parent) continue;
        pll got=dfs(neigh,vtx);
        chkmax(best, MP(got.first+1,got.second));
    }
    return best;
}
bool lo[mn];
ll solve() {
    ll h; scanf("%d",&h);
    if (h==0) exit(0);
    memset(seen,0,sizeof seen);
    memset(lo,0,sizeof lo);
    for (ll v=0;v<mn;v++) {g[v].clear(); dp[v].clear();}
    ll x=1;
    ll height=-100;
    while(1) {
        set<ll> lower;
        if (x!=1) {
            ll derivedheight=INF;
            for (auto &y:g[x]) {
                chkmin(derivedheight, dfs(y,x).first);
            }
            height=derivedheight;
            for (auto &y:g[x]) {
                if (dfs(y,x).first==derivedheight) lower.insert(y);
            }
        }
        if (height==h-1) return x;
        vector<ll> ans=query(x);
        if (ans.size()==2) return x;
        if (height==h-2) {
            vll cand; for (auto &neigh:ans) cand.PB(neigh);
            for (ll i=0;i<cand.size()-1;i++) {
                vll res=query(cand[i]);
                if (res.size()==2) return cand[i];
            }
            return cand[cand.size()-1];
        }
        else if (height == h-3) {
            vll inter; for (auto &neigh:ans) if (!lo[neigh]) inter.PB(neigh);
            if (inter.size()>=3) return -12345;
            assert(inter.size()<=2);
            vll cand;
            for (auto &neigh:inter) {
                vll res=query(neigh);
                if (res.size()==2) return neigh;
                for (auto &y:res) {
                    if (y!=x) cand.PB(y);
                }
            }
            if (cand.size()>4) return -123;
            assert(cand.size()<=4);
            for (ll i=0;i<cand.size()-1;i++) {
                vll res=query(cand[i]);
                if (res.size()==2) return cand[i];
            }
            return cand[cand.size()-1];
        }
        ll winner=-1;
        if (ans.size()==1) {winner=ans[0]; lo[x]=true;}
        else if (ans.size()==3){
            vector<ll> cand;
            for (auto &neigh:ans) if (!seen[neigh]) cand.PB(neigh);
            assert(cand.size()!=0);
            if (cand.size()==1) {
                winner=cand[0]; lo[x]=true;
            }
            else if (x!=1) {
                vector<ll> v;
                {
                    ll a=cand[0];
                    while(1) {
                        v.PB(a);
                        vll res = query(a);
                        if (res.size()==1) break;
                        if (res.size() == 2) return a;
                        ll next=-1;
                        for (auto &neigh:res) if (!seen[neigh]) {next=neigh;}
                        assert(next!=-1);
                        a=next;
                    }
                }
                if (v.size()==height) {
                    lo[x]=true;
                    winner=cand[1];
                }
                else {
                    ll e = v.size() - height;
                    e /= 2;
                    winner = v[e - 1];
                    lo[x]=true;
                    for (ll i=0;i<e-1;i++) lo[v[i]]=true;
                }
            }
            else {
                vector<ll> v[2];
                for (ll k=0;k<2;k++) {
                    ll a=cand[k];
                    while(1) {
                        v[k].PB(a);
                        vll res = query(a);
                        if (res.size()==1) break;
                        if (res.size() == 2) return a;
                        ll next=-1;
                        for (auto &neigh:res) if (!seen[neigh]) {next=neigh;}
                        a=next;
                    }
                }
                if (!(v[0].size()<=v[1].size())) {
                    swap(v[0],v[1]); swap(cand[0],cand[1]);
                }
                if (v[0].size()==v[1].size()) {
                    for (auto &y:v[0]) lo[y]=true;
                    for (auto &y:v[1]) lo[y]=true;
                    winner=cand[2];
                }
                else {
                    for (auto &y:v[0]) lo[y]=true;
                    ll e=v[1].size()-v[0].size();
                    e/=2;
                    winner=v[1][e-1];
                }
            }
        }
        else assert(false);
        lo[x]=true;
        x=winner;
    }
}
int main()
{
    ll T; scanf("%d",&T);
    for (ll testnum=0;testnum<T;testnum++) {
        ll final=solve();
        printf("! %d\n",final); fflush(stdout);
    }
}