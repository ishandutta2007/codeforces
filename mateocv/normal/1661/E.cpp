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

struct Node{
	ll res,ml,mr,cl,cr,b;
};

Node bas(ll m){
	ll c=1;
	if(m==2)c=2;
	if(m==7)c=0;
	return {c,m,m,c,c,m==2};
}

Node NEUT={-1,0,0,0,0,0};

/*----------------DSU------------------*/
const int MAXN=6;
int pa[MAXN],sz[MAXN];
ll find_pa(ll pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(int a, int b) {
	int x=find_pa(a),y=find_pa(b);
	if (x!=y) {
		if(sz[x]>=sz[y]) sz[x]+=sz[y],pa[y]=x;
		else sz[y]+=sz[x],pa[x]=y;
	}
}
void dsu_init(ll n){fore(i,0,n)pa[i]=i,sz[i]=1;}

ll cant_pre[8][8][2][2];

ll cant(ll a, ll b, ll ea, ll eb){
	dsu_init(6);
	vector<ll> ma,mb;
	fore(i,0,3)ma.pb(!(a&(1ll<<i)));
	fore(i,0,3)mb.pb(!(b&(1ll<<i)));
	fore(i,0,3){
		if(ma[i]&&mb[i])join(i,3+i);
	}
	fore(i,0,2){
		if(ma[i]&&ma[i+1])join(i,i+1);
		if(mb[i]&&mb[i+1])join(3+i,3+i+1);
	}
	if(ea)join(0,2);
	if(eb)join(3,5);
	ll res=0;
	fore(i,0,3)if(ma[i])res+=(find_pa(i)==i);
	fore(i,0,3)if(mb[i])res+=(find_pa(3+i)==3+i);
	//cout<<a<<" "<<b<<" "<<ea<<" "<<eb<<" "<<res<<"\n";
	return res;
}

Node oper(Node a, Node b){
	if(a.res==-1)return b;
	if(b.res==-1)return a;
	Node res;
	if(a.b&&b.b){
		res=a;
	}else{
		res.b=0;
		res.ml=a.ml;
		res.mr=b.mr;
		auto c=cant_pre[a.mr][b.ml][a.mr==2&&a.cr==1][b.ml==2&&b.cl==1];
		res.res=a.res+b.res-a.cr-b.cl+c;
		res.cl=a.cl-(a.cl==2&&a.b&&(c==1));
		res.cr=b.cr-(b.cr==2&&b.b&&(c==1));
	}
	//cout<<"oper\n";
	//cout<<a.res<<" "<<a.ml<<" "<<a.mr<<" "<<a.cl<<" "<<a.cr<<" "<<a.b<<"\n";
	//cout<<b.res<<" "<<b.ml<<" "<<b.mr<<" "<<b.cl<<" "<<b.cr<<" "<<b.b<<"\n";
	//cout<<res.res<<" "<<res.ml<<" "<<res.mr<<" "<<res.cl<<" "<<res.cr<<" "<<res.b<<"\n";
	return res;
}

struct STree { // segment tree for min over integers
	vector<Node> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void upd(int k, int s, int e, int p, Node v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	Node query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int p, Node v){upd(1,0,n,p,v);}
	Node query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

STree st(500005);

int main(){FIN;
	ll n; cin>>n;
	string s[3];
	fore(i,0,3)cin>>s[i];
	fore(a,0,8){
		fore(b,0,8){
			fore(ea,0,2){
				fore(eb,0,2){
					cant_pre[a][b][ea][eb]=cant(a,b,ea,eb);
				}
			}
		}
	}
	fore(i,0,n)st.upd(i,bas(('1'-s[0][i])*4+('1'-s[1][i])*2+('1'-s[2][i])*1));
	ll t; cin>>t;
	while(t--){
		ll l,r; cin>>l>>r; l--;
		auto q=st.query(l,r);
		//cout<<q.res<<" "<<q.ml<<" "<<q.mr<<" "<<q.cl<<" "<<q.cr<<" "<<q.b<<"\n";
		cout<<q.res<<"\n";
	}
	
	return 0;
}