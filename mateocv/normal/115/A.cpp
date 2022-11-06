#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

vector<ll> g[2019];
ll vis[2019];

ll bfs(ll x) {
  //ll va=0;
  ll res=1;
  queue<int>q;
  q.push(x);
  vis[x]=1;//va; va++;
  while(q.size()) {
    int t=q.front();q.pop();
    //cout<<t+1<<" ";
    
    for(int i:g[t]) {
      if(!vis[i]) {
        vis[i]=vis[t]+1;
        res=max(res,vis[i]);
        q.push(i);
      }
    }
  }
  return res;
}

int main(){FIN;
	ll n; cin>>n;
    vector<ll> v;
    ll llega;
    fore(i,0,n){
        cin>>llega;
        if(llega==-1){
            v.pb(i);    
        }else{
            g[llega-1].pb(i);
        }
    }
    memset(vis,0,sizeof vis);
    ll maxi=0;
    fore(i,0,SZ(v)){
        maxi=max(maxi,bfs(v[i]));
    }
    cout<<maxi;
	
	
	
	
	
	return 0;
}