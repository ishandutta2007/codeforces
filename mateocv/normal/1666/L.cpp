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

const int MAXN=1<<20;
int n,m,st,pa[MAXN],sp[MAXN],vis[MAXN];
vector<int>g[MAXN];
vector<int> build(int v) {
  vector<int>res={v};
  // cout<<"end at "<<v+1<<endl;
  while(v!=st){
    v=pa[v],res.pb(v);
    // cout<<"view: "<<v+1<<endl;
  }
  reverse(ALL(res));
  return res;
}
void output(int x,int y) {
  vector<int>l=build(x);
  vector<int>r=build(y);
  r.pb(x);
  cout<<"Possible\n";
  cout<<SZ(l)<<"\n";
  fore(i,0,SZ(l))cout<<l[i]+1<<" \n"[i==SZ(l)-1];
  cout<<SZ(r)<<"\n";
  fore(i,0,SZ(r))cout<<r[i]+1<<" \n"[i==SZ(r)-1];
  exit(0);
}
void dfs(int v) {
  for(int i:g[v]) {
    if(vis[i]!=vis[v] && vis[i]>=0) {
      // cout<<"final "<<v+1<<" to "<<i+1<<endl;
      output(i,v);
    }
    if(vis[i]<0) {
      vis[i]=vis[v];
      // cout<<v+1<<" to "<<i+1<<endl;
      pa[i]=v;
      dfs(i);
    }
  }
}
int main() {FIN;
  memset(pa,-1,sizeof(pa));
  memset(vis,-1,sizeof(vis));
  cin>>n>>m>>st;st--;
  fore(i,0,m) {
    int x,y;cin>>x>>y;x--,y--;
    if(x==st)vis[y]=y,pa[y]=st,sp[y]=true;
    else if(y==st)continue;
    else {
      g[x].pb(y);
    }
  }
  fore(i,0,n)if(sp[i]){
    // cout<<"Start: "<<i<<endl;
    dfs(i);
  }
  cout<<"Impossible\n";
}