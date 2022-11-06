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

const int MAXN=400005;

ll p[MAXN];
char c[MAXN];

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

vector<pair<ll,string>> q;

vector<ll> g[MAXN];

vector<ll> ord;

ll ub[MAXN][2];

void dfs(ll v){
	ord.pb(v);
	for(auto i:g[v]){
		dfs(i);
	}
	ord.pb(-v-1);
}

#define oper(a,b) a+b
#define NEUT 0
struct STree { // persistent segment tree for min over integers
	vector<int> st, L, R; int n,sz,rt;
	STree(int n): st(1,NEUT),L(1,0),R(1,0),n(n),rt(0),sz(1){}
	int new_node(int v, int l=0, int r=0){
		int ks=SZ(st);
		st.pb(v);L.pb(l);R.pb(r);
		return ks;
	}
	int init(int s, int e, int *a){ // not necessary in most cases
		if(s+1==e)return new_node(a[s]);
		int m=(s+e)/2,l=init(s,m,a),r=init(m,e,a);
		return new_node(oper(st[l],st[r]),l,r);
	}
	int upd(int k, int s, int e, int p, int v){
		int ks=new_node(st[k],L[k],R[k]);
		if(s+1==e){st[ks]+=v;return ks;}
		int m=(s+e)/2,ps;
		if(p<m)ps=upd(L[ks],s,m,p,v),L[ks]=ps;
		else ps=upd(R[ks],m,e,p,v),R[ks]=ps;
		st[ks]=oper(st[L[ks]],st[R[ks]]);
		return ks;
	}
	int query(int k, int s, int e, int a, int b){
		if(e<=a||b<=s)return NEUT;
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
	}
	int init(int *a){return init(0,n,a);}
	int upd(int k, int p, int v){return rt=upd(k,0,n,p,v);}
	int upd(int p, int v){return upd(rt,p,v);} // update on last root
	int query(int k,int a, int b){return query(k,0,n,a,b);};
}; // usage: STree rmq(n);root=rmq.init(x);new_root=rmq.upd(root,i,v);rmq.query(root,s,e);

STree st(2*MAXN);

ll pos[MAXN];
vector<ll> rt;
ll ubt[MAXN];

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n){
		ll ty; cin>>ty;
		if(ty==1){
			cin>>c[i];
			p[i]=-1;
		}else{
			ll pa; cin>>pa; pa--;
			p[i]=pa;
			cin>>c[i];
		}
	}
	ll m; cin>>m;
	fore(i,0,m){
		ll v; cin>>v; v--;
		string s; cin>>s;
		q.pb({v,s});
	}
	//cout<<"q: "<<endl;
	//for(auto i:q)cout<<i.fst<<" "<<i.snd<<endl;
	aho_init();
	fore(i,0,m)add_string(q[i].snd,i);
	fore(i,1,SZ(t))g[get_link(i)].pb(i);
	fore(i,0,SZ(t)){
		for(auto j:t[i].leaf){
			ubt[j]=i;
		}
	}
	dfs(0);
	fore(i,0,SZ(ord)){
		if(ord[i]>=0){
			ub[ord[i]][0]=i;
		}else{
			ub[-ord[i]-1][1]=i;
		}
	}
	rt.pb(st.rt);
	//cout<<"HOLAAAA"<<endl;
	fore(i,0,n){
		//cout<<i<<": "<<endl;
		pos[i+1]=go(pos[p[i]+1],c[i]);
		//cout<<"pos updated: "<<pos[i+1]<<endl;
		rt.pb(st.upd(rt[p[i]+1],ub[pos[i+1]][0],1));
		//cout<<"st updated"<<endl;
	}
	//cout<<"HOLAAAA"<<endl;
	fore(i,0,m){
		cout<<st.query(rt[q[i].fst+1],ub[ubt[i]][0],ub[ubt[i]][1])<<"\n";
	}
	
	return 0;
}