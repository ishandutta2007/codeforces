#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

struct vertex {
	map<char,ll> next,go;
	ll p,link;
	char pch;
	vector<ll> leaf;
	ll val=-1;
	vertex(ll p=-1, char pch=-1):p(p),pch(pch),link(-1){}
};
vector<vertex> t;
void aho_init(){ //do not forget!!
	t.clear();t.pb(vertex());
}
void add_string(string s, ll id){
	ll v=0;
	for(char c:s){
		if(!t[v].next.count(c)){
			t[v].next[c]=t.size();
			t.pb(vertex(v,c));
		}
		v=t[v].next[c];
	}
	t[v].leaf.pb(id);
}
ll go(ll v, char c);
ll get_link(ll v){
	if(t[v].link<0)
		if(!v||!t[v].p)t[v].link=0;
		else t[v].link=go(get_link(t[v].p),t[v].pch);
	return t[v].link;
}
ll go(ll v, char c){
	if(!t[v].go.count(c))
		if(t[v].next.count(c))t[v].go[c]=t[v].next[c];
		else t[v].go[c]=v==0?0:go(get_link(v),c);
	return t[v].go[c];
}

bool vis[1010];

string s[1010];
ll c[1010];

ll getval(ll v){
	ll &res=t[v].val;
	if(vis[v])return res;
	res=0;
	vis[v]=1;
	if(!v)return res;
	for(auto i:t[v].leaf)res+=c[i];
	res+=getval(get_link(v));
	return res;
}

string ss;
vector<string> p;
vector<ll> sig;

pair<ll,ll> trans[15][1010];
ll g[1010][15];

vector<ll> mask[15];
ll umask[1<<14];

ll NEUT=-9000000000000000000;
ll dp[15][1010][3500];

ll f(ll x, ll y, ll z){
	ll &res=dp[x][y][z];
	if(res!=NEUT)return res;
	if(x==SZ(sig)){
		return res=0;
	}
	ll m=mask[14-x][z];
	fore(i,0,14){
		if((1<<i)&m){
			ll nx=g[y][i];
			res=max(res,t[nx].val+trans[x+1][nx].snd+f(x+1,trans[x+1][nx].fst,umask[m^(1<<i)]));
		}
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	aho_init();
	fore(i,0,n){
		cin>>s[i]>>c[i];
		add_string(s[i],i);
	}
	fore(i,0,SZ(t)){
		fore(j,0,14){
			g[i][j]=go(i,'a'+j);
		}
	}
	fore(i,0,SZ(t))getval(i);
	cin>>ss;
	p.pb("");
	fore(i,0,SZ(ss)){
		if(ss[i]=='?'){
			sig.pb(i);
			p.pb("");
		}else{
			p[SZ(p)-1].pb(ss[i]);
		}
	}
	assert(SZ(p)==SZ(sig)+1);
	fore(i,0,SZ(p)){
		fore(j,0,SZ(t)){
			ll pos=j,va=0;
			for(auto ii:p[i]){
				pos=g[pos][ii-'a'];
				va+=t[pos].val;
			}
			trans[i][j]={pos,va};
		}
	}
	fore(i,0,(1<<14)){
		umask[i]=SZ(mask[__builtin_popcount(i)]);
		mask[__builtin_popcount(i)].pb(i);
	}
	fore(i,0,15){
		fore(j,0,1010){
			fore(jj,0,3500){
				dp[i][j][jj]=NEUT;
			}
		}
	}
	cout<<f(0,trans[0][0].fst,0)+trans[0][0].snd;
	
	return 0;
}