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

const int MAXN=100005;

string p[MAXN],s[MAXN];

ll pos[MAXN],vis[MAXN];

bool isc(string s, string t){
	fore(i,0,SZ(s)){
		if(s[i]!=t[i]&&t[i]!='_')return false;
	}
	return true;
}

map<string,ll> comp;

vector<ll> g[MAXN];

vector<string> gen(string t){
	vector<string> res;
	fore(i,0,(1ll<<SZ(t))){
		string va=t;
		fore(j,0,SZ(t)){
			if(i&(1ll<<j))va[j]='_';
		}
		res.pb(va);
	}
	return res;
}

ll visg[MAXN];

vector<ll> res;

void dfs(ll v){
	if(visg[v])return;
	visg[v]=1;
	for(auto i:g[v])dfs(i);
	res.pb(v);
}

ll ub[MAXN];

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	fore(i,0,n)cin>>p[i];
	fore(i,0,m)cin>>s[i]>>pos[i],pos[i]--;
	fore(i,0,m)vis[pos[i]]=1;
	ll br=0;
	fore(i,0,m){
		if(!isc(s[i],p[pos[i]])){
			br++; break;
		}
	}
	if(br){
		cout<<"NO\n";
		return 0;
	}
	fore(i,0,n)if(vis[i])comp[p[i]]=i;
	fore(i,0,m){
		auto ge=gen(s[i]);
		for(auto j:ge){
			if(j!=p[pos[i]]&&comp.count(j)){
				g[pos[i]].pb(comp[j]);
			}
		}
	}
	/*
	fore(i,0,n){
		cout<<"g "<<i<<" :\n";
		for(auto j:g[i])cout<<j<<" ";
		cout<<"\n";
	}
	*/
	fore(i,0,n)if(vis[i])dfs(i);
	reverse(ALL(res));
	fore(i,0,n)if(!vis[i])res.pb(i);
	fore(i,0,SZ(res))ub[res[i]]=i;
	fore(i,0,n){
		for(auto j:g[i]){
			if(ub[j]<ub[i]){
				br++; break;
			}
		}
		if(br)break;
	}
	if(br){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	for(auto i:res)cout<<i+1<<" ";
	cout<<"\n";
	
	return 0;
}