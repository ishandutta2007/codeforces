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

string s[200005];
ll cant[200005],cantr[200005],cantp[200005];

ll getval(ll v){
	ll &res=cantp[v];
	if(res>=0)return res;
	if(!v)return res=0;
	res=SZ(t[v].leaf)+getval(get_link(v));
	return res;
}

int main(){FIN;
	string tt; cin>>tt;
	ll n; cin>>n;
	fore(i,0,n)cin>>s[i];
	aho_init();
	fore(i,0,n)add_string(s[i],i);
	mset(cantp,-1);
	fore(i,0,SZ(t)){
		getval(i);
	}
	ll pos=0;
	fore(i,0,SZ(tt)){
		pos=go(pos,tt[i]);
		cant[i]=cantp[pos];
	}
	reverse(ALL(tt));
	fore(i,0,n)reverse(ALL(s[i]));
	aho_init();
	fore(i,0,n)add_string(s[i],i);
	mset(cantp,-1);
	fore(i,0,SZ(t)){
		getval(i);
	}
	pos=0;
	fore(i,0,SZ(tt)){
		pos=go(pos,tt[i]);
		cantr[i]=cantp[pos];
	}
	reverse(cantr,cantr+SZ(tt));
	ll res=0;
	fore(i,0,SZ(tt)-1){
		res+=cant[i]*cantr[i+1];
	}
	cout<<res<<"\n";
	
	return 0;
}