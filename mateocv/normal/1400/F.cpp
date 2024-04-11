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
typedef int ll;

bool valid(string s){
	ll sump[SZ(s)+1];
	sump[0]=0;
	fore(i,0,SZ(s))sump[i+1]=sump[i]+s[i]-'0';
	fore(i,0,SZ(s)){
		fore(j,i+1,SZ(s)+1){
			if(j-i==SZ(s))continue;
			if(sump[SZ(s)]%(sump[j]-sump[i])==0)return false;
		}
	}
	return true;
}

struct vertex {
	map<char,int> next,go;
	int p,link;
	char pch;
	vector<int> leaf;
	vertex(int p=-1, char pch=-1):p(p),pch(pch),link(-1){}
};
vector<vertex> t;
void aho_init(){ //do not forget!!
	t.clear();t.pb(vertex());
}
void add_string(string s, int id){
	int v=0;
	for(char c:s){
		if(!t[v].next.count(c)){
			t[v].next[c]=t.size();
			t.pb(vertex(v,c));
		}
		v=t[v].next[c];
	}
	t[v].leaf.pb(id);
}
int go(int v, char c);
int get_link(int v){
	if(t[v].link<0)
		if(!v||!t[v].p)t[v].link=0;
		else t[v].link=go(get_link(t[v].p),t[v].pch);
	return t[v].link;
}
int go(int v, char c){
	if(!t[v].go.count(c))
		if(t[v].next.count(c))t[v].go[c]=t[v].next[c];
		else t[v].go[c]=v==0?0:go(get_link(v),c);
	return t[v].go[c];
}

ll dp[1010][20002];

string s;

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==SZ(s))return res=0;
	ll ny=go(y,s[x]);
	if(SZ(t[ny].leaf)){
		res=f(x+1,y);
	}else{
		res=max(f(x+1,y),f(x+1,ny)+1);
	}
	return res;
}

vector<string> v[21];

int main(){FIN;
	cin>>s;
	ll x; cin>>x;
	aho_init();
	v[0].pb("");
	v[1].pb("1");
	fore(i,2,x+1){
		fore(j,2,10){
			if(i-j>=0){
				string t;
				t+='0'+j;
				for(auto ii:v[i-j]){
					v[i].pb(ii+t);
				}
			}
		}
	}
	fore(i,0,SZ(v[x])){
		if(valid(v[x][i])){
			add_string(v[x][i],i);
		}
	}
	mset(dp,-1);
	cout<<SZ(s)-f(0,0);
	return 0;
}