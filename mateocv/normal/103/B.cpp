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

vector<ll> g[102];
ll vis[102];

void bfs(ll x) {
  //ll va=0;
  queue<int>q;
  q.push(x);
  vis[x]=1;//va; va++;
  while(q.size()) {
    int t=q.front();q.pop();
    //cout<<t+1<<" ";
    
    for(int i:g[t]) {
      if(!vis[i]) {
        vis[i]=1;
        q.push(i);
      }
    }
  }
}

int main(){FIN;
	ll n,m; cin>>n>>m;
    ll a,b;
    fore(i,0,m){
        cin>>a>>b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    memset(vis,0,sizeof vis);
    if(m==n){
        bfs(0);
        ll sum=0;
        fore(i,0,n){
            sum+=vis[i];
        }
        if(sum==n){cout<<"FHTAGN!";}else{cout<<"NO";}
    }else{
        cout<<"NO";
    }
	
	
	
	
	
	return 0;
}