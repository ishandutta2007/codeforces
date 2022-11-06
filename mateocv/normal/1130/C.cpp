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

vector<ll> g[2555];
vector<ll> v[2];
ll vis[2555];
void bfs(ll x,ll y) {
  queue<int>q;
  q.push(x);
  v[y-1].pb(x);
  while(q.size()) {
    int t=q.front();q.pop();
    //cout<<t+1<<" ";
    for(int i:g[t]) {
      if(!vis[i]) {
        vis[i]=y;
        q.push(i);
        v[y-1].pb(i);
      }
    }
  }
}

int main(){FIN;
	ll n; cin>>n;
	ll a[2],b[2]; cin>>a[0]>>a[1]>>b[0]>>b[1];
	a[0]--; a[1]--; b[0]--; b[1]--;
	memset(vis,0,sizeof vis);
	char t[n][n];
	fore(i,0,n){
		fore(j,0,n){
			cin>>t[i][j];
		}
	}
	fore(i,0,n){
		fore(j,0,n){
			if(t[i][j]=='0'){
				if(i>0&&t[i-1][j]=='0')g[50*i+j].pb(50*(i-1)+j);
				if(i<n-1&&t[i+1][j]=='0')g[50*i+j].pb(50*(i+1)+j);
				if(j>0&&t[i][j-1]=='0')g[50*i+j].pb(50*i+j-1);
				if(j<n-1&&t[i][j+1]=='0')g[50*i+j].pb(50*i+j+1);
			}
		}
	}
	ll apos=50*a[0]+a[1];
	ll bpos=50*b[0]+b[1];
	bfs(apos,1);
	if(vis[bpos]==1){
		cout<<0;
	}else{
		bfs(bpos,2);
		ll mini=1ll*1e18;
		fore(i,0,SZ(v[0])){
			fore(j,0,SZ(v[1])){
				ll a=(v[0][i]%50)-(v[1][j]%50);
				ll b=(v[0][i]/50)-(v[1][j]/50);
				mini=min(mini,a*a+b*b);
			}
		}
		cout<<mini;
	}
	
	
	
	
	return 0;
}