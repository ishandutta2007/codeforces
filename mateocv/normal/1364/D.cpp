#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

vector<ll> g[100005];
vector<ll> gt[100005];

ll vis[100005];
ll c[100005];
ll p[100005];
ll d[100005];


void dfs(ll v){
	//if(vis[v])return;
	vis[v]=1;
	for(auto i:g[v]){
		if(!vis[i]){
			dfs(i);
			gt[v].pb(i);
		}
	}
	
}

void bfs() {
	queue<int>q;
	vis[0]=1;
	q.push(0);
	while(q.size()) {
		int t=q.front(); q.pop();
		//cout<<t+1<<" ";
		for(int i:gt[t]) {
			if(!vis[i]) {
				vis[i]=1;
				q.push(i);
				c[i]=(c[t]+1)%2;
				p[i]=t;
				d[i]=d[t]+1;
			}
		}
	}
}

bool cmp(ll u, ll v){
	return d[u]<d[v];
}

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0);
	mset(vis,0);
	bfs();
	//cout<<"HLAAAAAAA"<<endl;
	vector<ll> ord;
	fore(i,0,n)ord.pb(i);
	sort(ALL(ord),cmp);
	fore(i,0,n){
		for(auto j:g[ord[i]]){
			if(c[ord[i]]==c[j]&&p[ord[i]]!=j){
				//cout<<i<<" "<<j<<"\n";
				deque<ll> de;
				ll a=ord[i],b=j;
				//de.pb(a); de.pb(b);
				while(d[a]>d[b])de.push_front(a),a=p[a];
				while(d[a]<d[b])de.pb(b),b=p[b];
				while(a!=b){
					de.push_front(a),a=p[a];
					de.pb(b),b=p[b];
				}
				de.pb(a);
				if(SZ(de)<=k){
					cout<<2<<"\n"<<SZ(de)<<"\n";
					fore(_,0,SZ(de))cout<<de.back()+1<<" ",de.pop_back();
					return 0;
				}else{
					cout<<1<<"\n";
					//fore(i,0,SZ(de))cout<<de[i]<<" "; cout<<"\n";
					ll tot=0;
					fore(_,0,SZ(de)){
						if(_%2==0)cout<<de.back()+1<<" ",de.pop_back(),tot++;
						else de.pop_back();
						if(tot==(k+1)/2)break;
					}
					return 0;
				}
			}
		}
	}
	vector<ll> v[2];
	fore(i,0,n){
		v[c[i]].pb(i);
	}
	cout<<1<<"\n";
	if(SZ(v[0])>=(k+1)/2){
		fore(i,0,(k+1)/2)cout<<v[0][i]+1<<" ";
	}else{
		fore(i,0,(k+1)/2)cout<<v[1][i]+1<<" ";
	}
	
	return 0;
}