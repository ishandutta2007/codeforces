#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 250010
#define MOD 998244353
#define INF (ll)1e+18
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;




int main() {
  int t;
  int n,m;
  int u[N];
  int v[N];
  int w[N];
  int x,sz;
  ll ans,y;
  vector<int>e[N];
  int d[N][3];
  queue<int>q;
  cin>>t;
  rep(tt,t){
    cin>>n>>m;
    rep(i,m){
      cin>>u[i]>>v[i]>>w[i];
      u[i]--;
      v[i]--;
      e[u[i]].pb(v[i]);
      e[v[i]].pb(u[i]);
    }
    rep(i,n){
      d[i][0]=-1;
      d[i][1]=-1;
      d[i][2]=-1;
    }
    d[0][0]=0;
    q.push(0);
    while(!q.empty()){
      x=q.front();
      q.pop();
      sz=e[x].size();
      rep(i,sz){
        if(d[e[x][i]][0]==-1){
          d[e[x][i]][0]=d[x][0]+1;
          q.push(e[x][i]);
        }
      }
    }
    d[n-1][1]=0;
    q.push(n-1);
    while(!q.empty()){
      x=q.front();
      q.pop();
      sz=e[x].size();
      rep(i,sz){
        if(d[e[x][i]][1]==-1){
          d[e[x][i]][1]=d[x][1]+1;
          q.push(e[x][i]);
        }
      }
    }
    rep(i,n){
      if((d[i][0]+d[i][1])==d[0][1]){
        d[i][2]=0;
        q.push(i);
      }
    }
    while(!q.empty()){
      x=q.front();
      q.pop();
      sz=e[x].size();
      rep(i,sz){
        if(d[e[x][i]][2]==-1){
          d[e[x][i]][2]=d[x][2]+1;
          q.push(e[x][i]);
        }
      }
    }
    ans=(ll)1e+18;
    rep(i,m){
      y=min(d[u[i]][0]+d[v[i]][1],d[v[i]][0]+d[u[i]][1])+1;
      y=min(y,(ll)min(d[u[i]][2],d[v[i]][2])+d[0][1]+2);
      y*=w[i];
      ans=min(ans,y);
    }
    cout<<ans<<endl;


    rep(i,n+1)e[i].clear();
  }
    
	return 0;
}