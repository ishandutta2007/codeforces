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

vector<ll> g[250005];
pair<ll,ll> vis[250005];

void bfs(ll x) {
  //ll va=0;
  queue<int>q;
  q.push(x);
  vis[x].fst=1;//va; va++;
  while(q.size()) {
    int t=q.front();q.pop();
    //cout<<t+1<<" ";
    
    for(int i:g[t]) {
      if(!vis[i].fst) {
        vis[i].fst=vis[t].fst+1;
        q.push(i);
      }
    }
  }
}

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	ll tab[m][n];
	char c;
	memset(vis,0,sizeof vis);
	fore(i,0,n*m){
		vis[i].snd=i;
	}
	ll st=-1,ya=0;
	fore(i,0,n*m){
		cin>>c;
		if(c=='#'){
			tab[i%m][i/m]=0;
		}else{
			tab[i%m][i/m]=1;
			if(!ya){
				st=i;
				ya++;
			}
		}
		
	}
	
	fore(i,0,n*m){
		if(tab[i%m][i/m]){
			if((i%m<m-1)&&tab[(i%m)+1][i/m]){
				g[i].pb(i+1);
			}
			if((i%m>0)&&tab[i%m-1][i/m]){
				g[i].pb(i-1);
			}
			if((i/m<n-1)&&tab[i%m][i/m+1]){
				g[i].pb(i+m);
			}
			if((i/m>0)&&tab[i%m][i/m-1]){
				g[i].pb(i-m);
			}
		}
	}
	bfs(st);
	sort(vis,vis+n*m);
	char res[n*m];
	fore(i,0,n*m){
		if(tab[i%m][i/m]){
			res[i]='.';
		}else{
			res[i]='#';
		}
	}
	
	fore(i,0,k){
		ll j=vis[n*m-1-i].snd;
		res[j]='X';
	}
	
	fore(i,0,n*m){
		cout<<res[i];//<<" ";
		if(i%m==m-1)cout<<"\n";
	}
	
	
	
	
	
	return 0;
}