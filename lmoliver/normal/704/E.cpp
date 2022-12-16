#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100100;
const int INF=10*N;
const double eps=1e-9;
struct F{
	double value;
	F(){}
	F(int value):value((double)value){}
	F(double value):value(value){}
	F operator+(const F o)const{
		return {value+o.value};
	}
	F operator-(const F o)const{
		return {value-o.value};
	}
	F operator-()const{
		return {-value};
	}
	F operator*(const F o)const{
		return {value*o.value};
	}
	F operator/(const F o)const{
		return {value/o.value};
	}
	bool operator==(const F o)const{
		return abs(value-o.value)<eps;
	}
	bool operator<(const F o)const{
		return value+eps<o.value;
	}
	bool operator>(const F o)const{
		return o.value+eps<value;
	}
	double toD(){
		return value;
	}
	// LL a,b;
	// F(){}
	// F(LL _a,LL _b=1){
	// 	a=_a;
	// 	b=_b;
	// 	if(b<0){
	// 		a=-a;
	// 		b=-b;
	// 	}
	// 	LL g=__gcd(a>=0?a:-a,b);
	// 	a/=g;
	// 	b/=g;
	// }
	// bool operator<(const F o)const{
	// 	return a*o.b<o.a*b;
	// }
	// bool operator>(const F o)const{
	// 	return a*o.b>o.a*b;
	// }
	// bool operator==(const F o)const{
	// 	return a==o.a&&b==o.b;
	// }
	// F operator+(const F o)const{
	// 	return F(a*o.b+b*o.a,b*o.b);
	// }
	// F operator-(const F o)const{
	// 	return F(a*o.b-b*o.a,b*o.b);
	// }
	// F operator*(const F o)const{
	// 	return F(a*o.a,b*o.b);
	// }
	// F operator/(const F o)const{
	// 	return F(a*o.b,b*o.a);
	// }
	// F operator-()const{
	// 	return F(-a,b);
	// }
	// double toD()const{
	// 	return (double)a/b;
	// }
};
ostream &operator<<(ostream &out,F o){
	return out<<o.value<<endl;
	// out<<o.a;
	// return o.b!=1?(out<<"/"<<o.b):out;
}
struct P{
	F x,y;
	P(){}
	P(F x,F y):x(x),y(y){}
	bool operator<(const P o)const{
		return y<o.y;
	}
	bool operator>(const P o)const{
		return y>o.y;
	}
	bool operator==(const P o)const{
		return x==o.x&&y==o.y;
	}
	P operator+(const P o)const{
		return P(x+o.x,y+o.y);
	}
	P operator-(const P o)const{
		return P(x-o.x,y-o.y);
	}
	P operator*(const F r)const{
		return P(x*r,y*r);
	}
};
ostream &operator<<(ostream &out,P o){
	return out<<"("<<o.x<<", "<<o.y<<")";
}
pair<F,F> solve(F a,F b,F c,F d,F e,F f){
	// cerr<<"solve "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
	if(a==0){
		swap(a,d);
		swap(b,e);
		swap(c,f);
	}
	if(a==0){
		if(b==0){
			swap(b,e);
			swap(c,f);
		}
		if(b==0){
			if(c==0&&f==0){
				return {0,0};
			}
			else{
				return {-1,-1};
			}
		}
		F x=-e/b;
		f=f+x*c;
		if(f==0){
			return {0,-c/b};
		}
		else{
			return {-1,-1};
		}
	}
	F x=-d/a;
	e=e+x*b;
	f=f+x*c;
	if(e==0){
		if(f==0){
			return {0,0};
		}
		else{
			return {-1,-1};
		}
	}
	else{
		f=f/e;
		c=(c-b*f)/a;
		return {-c,-f};
	}
}
struct L;
ostream &operator<<(ostream &out,L o);
struct L{
	P a,b;
	L(P _a,P _b){
		if(_a<_b){
			a=_a;
			b=_b;
		}
		else{
			a=_b;
			b=_a;
		}
	}
	F ins(const L o)const{
		// cerr<<"ins "<<*this<<" "<<o<<endl;
		if(b<o.a||o.b<a){
			return INF;
		}
		P x=b-a;
		P y=o.a-o.b;
		P z=a-o.a;
		// cerr<<x<<" "<<y<<" "<<z<<endl;
		pair<F,F> s=solve(x.x,y.x,z.x,x.y,y.y,z.y);
		// cerr<<s.first<<" "<<s.second<<endl;
		if(s.first<0||s.first>1
			||s.second<0||s.second>1){
				return INF;
			}
		else{
			return max(a+x*s.first,o.a-y*s.second).y;
		}
	}
	F get(F y)const{
		if(b.y==a.y){
			return a.x;
		}
		else{
			F k=(b.x-a.x)/(b.y-a.y);
			return a.x+k*(y-a.y);
		}
	}
};
ostream &operator<<(ostream &out,L o){
	return out<<o.a<<" - "<<o.b;
}
struct LS{
	struct E{
		P pos;
		int id;
		int tp;
		E(P pos,int id,int tp):pos(pos),id(id),tp(tp){}
		bool operator<(const E o)const{
			if(pos<o.pos){
				return true;
			}
			else if(o.pos<pos){
				return false;
			}
			else{
				return tp>o.tp;
			}
		}
	};
	vector<L> ls;
	vector<E> es;
	LS(){}
	void ins(L l){
		// cerr<<"ins "<<l<<endl;
		int id=ls.size();
		ls.push_back(l);
		es.push_back(E(l.a,id,1));
		es.push_back(E(l.b,id,-1));
	}
	F solve(){
		static F now=0;
		now=0;
		struct Cmp{
			bool operator()(const L a,const L b)const{
				return a.get(now)<b.get(now);
			}
		};
		typedef multiset<L,Cmp>::iterator MSLIT;
		multiset<L,Cmp> cl;
		map<int,MSLIT> clh;
		sort(es.begin(),es.end());
		F ans=INF;
		for(vector<E>::iterator it=es.begin();it!=es.end();it++){
			now=it->pos.y;
			// cerr<<now<<" "<<it->tp<<" "<<it->id<<endl;
			if(!(now<ans)){
				// cerr<<"go~"<<endl;
				break;
			}
			if(it->tp==1){
				// cerr<<ls[it->id]<<endl;
				// cerr<<"before insert"<<endl;
				MSLIT nw=cl.insert(ls[it->id]);
				// cerr<<"after insert"<<endl;
				// cerr<<"insert "<<*nw<<endl;
				clh[it->id]=nw;
				if(nw!=cl.begin()){
					MSLIT o=nw;
					o--;
					ans=min(ans,nw->ins(*o));
				}
				if(++nw!=cl.end()){
					MSLIT o=nw;
					o--;
					ans=min(ans,nw->ins(*o));
				}
				// cerr<<"OK"<<endl;
			}
			else if(it->tp==-1){
				MSLIT nw=clh[it->id];
				// cerr<<"delete "<<*nw<<endl;
				clh.erase(it->id);
				MSLIT o=cl.erase(nw);
				if(o!=cl.end()&&o!=cl.begin()){
					MSLIT v=o;
					v--;
					ans=min(ans,v->ins(*o));
				}
			}
		}
		return ans;
	}
};
int n;
typedef vector<int> VI;
VI es[N];
void ae(int u,int v){
	es[u].push_back(v);
}
#define FS(x) for(VI::iterator it=es[x].begin();it!=es[x].end();it++)
int sz[N];
int f[N];
bool h[N]={false};
int dep[N]={0};
void dfs1(int x=1,int fa=-1){
	f[x]=fa;
	// cerr<<"f["<<x<<"] = "<<fa<<endl;
	sz[x]=1;
	int msz=-1;
	FS(x){
		if(*it!=fa){
			dep[*it]=dep[x]+1;
			dfs1(*it,x);
			sz[x]+=sz[*it];
			if(msz==-1||sz[*it]>sz[msz]){
				msz=*it;
			}
		}
	}
	if(msz!=-1){
		h[msz]=true;
	}
}
int dfn[N];
int top[N];
int dft=0;
void dfs2(int x=1,int fa=-1){
	dfn[x]=++dft;
	top[x]=h[x]?top[fa]:x;
	FS(x){
		if(*it!=fa&&h[*it]){
			dfs2(*it,x);
		}
	}
	FS(x){
		if(*it!=fa&&!h[*it]){
			dfs2(*it,x);
		}
	}
}
const int LE=17;
int fas[N][LE];
void init(){
	for(int i=1;i<=n;i++){
		fas[i][0]=f[i];
	}
	for(int j=1;j<LE;j++){
		for(int i=1;i<=n;i++){
			int p=fas[i][j-1];
			fas[i][j]=p==-1?-1:fas[p][j-1];
		}
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v]){
		swap(u,v);
	}
	for(int i=LE-1;i>=0;i--){
		if(dep[u]-(1<<i)>=dep[v]){
			u=fas[u][i];
		}
	}
	if(u==v){
		return u;
	}
	else{
		for(int i=LE-1;i>=0;i--){
			if(fas[u][i]!=fas[v][i]){
				u=fas[u][i];
				v=fas[v][i];
			}
		}
		return f[u];
	}
}
int dis(int u,int v){
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
LS lfa[N];
LS g;
void ins(F t,int u,int v,F speed){
	int a=0;
	int b=dis(u,v);
	while(top[u]!=top[v]){
		// cerr<<u<<" "<<v<<endl;
		int tu=top[u];
		int tv=top[v];
		if(dep[tu]>dep[tv]){
			int dt=dep[u]-dep[tu];
#define TM(a) (t+(F)(a)/speed)
			g.ins({{dfn[u],TM(a)},{dfn[tu],TM(a+dt)}});
			u=tu;
			a+=dt;
			lfa[u].ins({{0,TM(a)},{1,TM(a+1)}});
			a++;
			u=f[u];
		}
		else{
			int dt=dep[tv]-dep[v];
			g.ins({{dfn[v],TM(b)},{dfn[tv],TM(b+dt)}});
			v=tv;
			b+=dt;
			lfa[v].ins({{0,TM(b)},{1,TM(b-1)}});
			b--;
			v=f[v];
		}
	}
	g.ins({{dfn[u],TM(a)},{dfn[v],TM(b)}});
}
F solve(){
	F ans=g.solve();
	for(int i=2;i<=n;i++){
		if(!h[i]){
			ans=min(ans,lfa[i].solve());
		}
	}
	return ans;
}
int m;
int main(){
	// scanf("%d",&n);
	// while(n--){
	// 	LL a,b,c,d;
	// 	cin>>a>>b>>c>>d;
	// 	g.ins({{a,b},{c,d}});
	// }
	// cout<<g.solve()<<endl;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		ae(u,v);
		ae(v,u);
	}
	dfs1();
	dfs2();
	init();
	while(m--){
		int t,c,v,u;
		scanf("%d%d%d%d",&t,&c,&v,&u);
		ins(t,v,u,c);
	}
	F ans=solve();
	if(ans<INF){
		printf("%.10f\n",ans.toD());
	}
	else{
		puts("-1");
	}
	return 0;
}