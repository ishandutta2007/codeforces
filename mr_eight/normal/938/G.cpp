//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
//#pra gma G CC opti mize(3)
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
namespace fastIO {
	template<class T>
	inline void read(T &x) {
		x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		if(fu)x=-x;
	}
	inline int read() {
		int x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		return fu?-x:x;
	}
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
	}
	char _n_u_m_[40];
	template<class T>
	inline void write(T x ) {
		if(x==0){
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		register int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
}
using namespace fastIO;
int n,K,t=1,l[400002],r[400002],u[400002],v[400002],w[400002],m;
vector<int>add[1600002];
vector<pii >query[1600002];
namespace xxj{
	struct T{
		int r,v;
	}a[25000002];
	int t,p[30];
	inline void ins(int pos){
		for(int i=29;(~i)&&a[pos].v;--i)if(a[pos].v>>i&1){
			if(a[pos].r>a[p[i]].r)swap(pos,p[i]);
			if(pos)a[pos].v^=a[p[i]].v;
		}
	}
	inline int query(int v,int tt){
		for(int i=29;~i;--i)if((v>>i&1)&&(a[p[i]].r>=tt))v^=a[p[i]].v;
		write(v,'\n');
	}
	inline void solve(){
		//F(i,1,t)cerr<<' '<<a[i].r<<' '<<a[i].v<<endl;
		F(i,1,t){
			if(~a[i].r)ins(i);
			else query(a[i].v,i);
		}
	}
}
namespace bcj{
	int fa[200002],v[200002],d[200002],cnt;
	inline void prework(){
		F(i,1,m)fa[i]=i;
	}
	struct T{
		int x,y,dy,orzhq;
	}sta[1000002];
	inline int findf(int x,int &w){
		while(x!=fa[x])w^=v[x],x=fa[x];
		return x;
	}
	inline void ed(int x,int y,int w){//cerr<<"ed "<<x<<" "<<y<<" "<<w<<endl;
		x=findf(x,w);
		y=findf(y,w);
		if(x==y){
			xxj::a[++xxj::t]={1000000000,w};
			sta[++cnt]={0,0,0,xxj::t};
			return;
		}
		if(d[x]>d[y])swap(x,y);
		sta[++cnt]={x,y,d[y],0};
		fa[x]=y;
		v[x]=w;
		d[y]=max(d[y],d[x]+1);
	}
	inline void pop(){//cerr<<"pop "<<sta[cnt].x<<" "<<sta[cnt].y<<endl;
		fa[sta[cnt].x]=sta[cnt].x;
		v[sta[cnt].x]=0;
		d[sta[cnt].y]=sta[cnt].dy;
		if(sta[cnt].orzhq)xxj::a[sta[cnt].orzhq].r=xxj::t;
		--cnt;
	}
	inline void query(int x,int y){//cerr<<"query "<<x<<" "<<y<<endl;
		int w=0;
		x=findf(x,w);
		y=findf(y,w);
		xxj::a[++xxj::t]={-1,w};
	}
};
#define mid ((l+r)>>1)
inline void ins(int pos,int l,int r,int ql,int qr,int p){
	if(ql<=l&&qr>=r){
		add[pos].push_back(p);
		return;
	}
	if(ql>r||qr<l)return;
	ins(pos<<1,l,mid,ql,qr,p);
	ins(pos<<1|1,mid+1,r,ql,qr,p);
}
inline void dfs(int pos,int l,int r){
	for(int i:add[pos])bcj::ed(u[i],v[i],w[i]);
	if(l==r){
		for(pii fuck:query[l])bcj::query(fuck.first,fuck.second);
	}
	else{
		dfs(pos<<1,l,mid);
		dfs(pos<<1|1,mid+1,r);
	}
	F(i,1,(int)add[pos].size())bcj::pop();
}
map<ll,int>id;
inline ll mp(int x,int y){
	return ((ll)min(x,y))<<30ll|max(x,y);
}
int main(){
	cin>>m>>n;
	bcj::prework();
	F(i,1,n)read(u[i]),read(v[i]),read(w[i]),id[mp(u[i],v[i])]=i;
	F(i,1,n)l[i]=1;
	bool flag=false;
	F(i,1,read()){
		int tp=read();
		if(tp==3){
			if(!flag)++t;
			query[t].push_back(make_pair(read(),read()));
			flag=true;
		}
		else if(tp==2){
			r[id[mp(read(),read())]]=t;
			flag=false;
		}else{
			++n;
			read(u[n]);
			read(v[n]);
			read(w[n]);
			id[mp(u[n],v[n])]=n;
			l[n]=t+1;
			flag=false;
		}
	}
	F(i,1,n)ins(1,1,t,l[i],(r[i]?r[i]:t),i);
	dfs(1,1,t);
	xxj::solve();
    return 0;
}