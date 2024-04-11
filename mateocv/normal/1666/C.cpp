#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second
#define pb push_back

vector<pair<ll,ll>> ed;

ll w[102],s[102],vis[102];

vector<ll> g[102];

void dfs(ll x){
  vis[x]=1;
  s[x]=w[x];
  for(auto i:g[x]){
    if(vis[i])continue;
    dfs(i);
    s[x]=(s[x]|s[i]);
  }
}

int main() {FIN;
  ll x[3],y[3];
  fore(k,0,3){
    cin>>x[k]>>y[k];
  }
  set<ll> sx,sy;
  fore(k,0,3)sx.insert(x[k]);
  fore(k,0,3)sy.insert(y[k]);
  set<pair<ll,ll>> inp;
  fore(k,0,3)inp.insert({x[k],y[k]});
  vector<pair<ll,ll>> p;
  for(auto i:sx){
    for(auto j:sy){
     p.pb({i,j});
    }
  }
  ll st=-1;
  fore(i,0,SZ(p)){
    if(inp.count(p[i]))w[i]=(1ll<<i),st=i;
  }
  vector<ll> c;
  fore(i,0,SZ(p)){
    fore(j,i+1,SZ(p)){
      if(p[i].fst==p[j].fst||p[i].snd==p[j].snd){
        ed.pb({i,j});
        c.pb(abs(p[i].fst-p[j].fst)+abs(p[i].snd-p[j].snd));
      }
    }
  }
  vector<pair<ll,ll>> res;
  ll mini=1e18;
  fore(i,0,(1ll<<SZ(ed))){
    fore(j,0,SZ(p)){
      g[j].clear();
      vis[j]=0;
      s[j]=0;
    }
    ll va=0;
    vector<pair<ll,ll>> vv;
    fore(j,0,SZ(ed)){
      if((1ll<<j)&i){
        g[ed[j].fst].pb(ed[j].snd);
        g[ed[j].snd].pb(ed[j].fst);
        vv.pb(ed[j]);
        va+=c[j];
      }
    }
    dfs(st);
    if(__builtin_popcount(s[st])==3&&mini>va){
      mini=va;
      res=vv;
    }
  }
  cout<<SZ(res)<<"\n";
  for(auto i:res){
    cout<<p[i.fst].fst<<" "<<p[i.fst].snd<<" ";
    cout<<p[i.snd].fst<<" "<<p[i.snd].snd<<" "<<"\n";
  };
}