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

const int MAXN = 300005;

string s[MAXN];

/*----------------CLASSIC SEGMENT TREE----------------*/
#define oper max
const ll NEUT=-1;
struct STree { // [cerrado-abierto)
    vector<ll> st;int n;
    STree(int n): st(4*n+5,NEUT), n(n) {}
    void upd(int k, int s, int e, int p, ll v){
        if(s+1==e){st[k]=v;return;}
        int m=(s+e)/2;
        if(p<m)upd(2*k,s,m,p,v);
        else upd(2*k+1,m,e,p,v);
        st[k]=oper(st[2*k],st[2*k+1]);
    }
    ll query(int k, int s, int e, int a, int b){
        if(s>=b||e<=a)return NEUT;
        if(s>=a&&e<=b)return st[k];
        int m=(s+e)/2;
        return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
    }
    void upd(int p, ll v){upd(1,0,n,p,v);}
    ll query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree st(n);st.upd(i,v);st.query(s,e);

STree st(MAXN),stg(MAXN);

ll ord[MAXN],ub[MAXN],ubt[MAXN];

pair<ll,ll> ran[MAXN];

vector<int> g[MAXN];
int wg[MAXN],dad[MAXN],dep[MAXN]; // weight,father,depth
void dfs1(int x){
	wg[x]=1;
	for(int y:g[x])if(y!=dad[x]){
		dad[y]=x;dep[y]=dep[x]+1;dfs1(y);
		wg[x]+=wg[y];
	}
}
int curpos,posi[MAXN],head[MAXN];
void hld(int x, int c){
	if(c<0)c=x;
	posi[x]=curpos++;head[x]=c;
	int mx=-1;
	for(int y:g[x])if(y!=dad[x]&&(mx<0||wg[mx]<wg[y]))mx=y;
	if(mx>=0)hld(mx,c);
	for(int y:g[x])if(y!=mx&&y!=dad[x])hld(y,-1);
}
void hld_init(){dad[0]=-1;dep[0]=0;dfs1(0);curpos=0;hld(0,-1);}
int query(int x, int y, STree& rmq){
	int r=NEUT;
	while(head[x]!=head[y]){
		if(dep[head[x]]>dep[head[y]])swap(x,y);
		r=oper(r,rmq.query(posi[head[y]],posi[y]+1));
		y=dad[head[y]];
	}
	if(dep[x]>dep[y])swap(x,y); // now x is lca
	r=oper(r,rmq.query(posi[x],posi[y]+1));
	return r;
}
// for updating: rmq.upd(posi[x],v);
// queries on edges: - assign values of edges to "child" node
//                   - change posi[x] to posi[x]+1 in query (line 28)

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,n)cin>>s[i];
	aho_init();
	fore(i,0,n)add_string(s[i],i);
	ll va=0;
	fore(i,0,SZ(t)){
		ran[i].fst=va;
		for(auto j:t[i].leaf){
			ord[va]=j;
			ub[j]=va;
			ubt[va]=i;
			st.upd(va,0);
			va++;
		}
		ran[i].snd=va;
	}
	fore(i,0,SZ(t))get_link(i);
	fore(i,0,SZ(t))g[get_link(i)].pb(i);
	hld_init();
	fore(i,0,SZ(t)){
		if(SZ(t[i].leaf)){
			stg.upd(posi[i],0);
		}
	}
	while(m--){
		ll ty; cin>>ty;
		if(ty==1){
			ll pos,val; cin>>pos>>val; pos--;
			st.upd(ub[pos],val);
			ll no=ubt[ub[pos]];
			stg.upd(posi[no],st.query(ran[no].fst,ran[no].snd));
		}else{
			ll pos=0;
			string q; cin>>q;
			ll res=-1;
			for(auto i:q){
				pos=go(pos,i);
				res=max(res,query(0,pos,stg));
			}
			cout<<res<<"\n";
		}
	}
	
	return 0;
}