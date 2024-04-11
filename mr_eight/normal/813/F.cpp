//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
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
//#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
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
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
using namespace std;
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
	inline void write(T x) {
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
map<pii,int>id;
int n,m,cnt,l[100002],r[100002],u[100002],v[100002],fa[100002],sta[100002],sz[100002],w[100002];
bool fuck;
inline int findf(int x,int &v){
	while(x!=fa[x])v^=w[x],x=fa[x];
	return x;
}
inline void merge(int x,int y){
	if(fuck){
		sta[++cnt]=0;
		return;
	}
	int ww=true;
	x=findf(x,ww),y=findf(y,ww);
	if(x==y){
		if(ww){
			sta[++cnt]=-1;
			fuck=true;
			return;
		}
		sta[++cnt]=0;
		return;
	}
	if(sz[x]>sz[y])swap(x,y);
	sta[++cnt]=x;
	fa[x]=y;
	w[x]=ww;
	sz[y]+=sz[x];
}
inline void pop(){
	int x=sta[cnt--];
	if(x>0){
		int y=fa[x];
		sz[y]-=sz[x];
		fa[x]=x;
		w[x]=0;
	}else if(x==-1)fuck=false;
}
vector<pii >upd[400002];
#define mid ((l+r)>>1)
inline void add(int pos,int l,int r,int ql,int qr,int u,int v){
	if(ql<=l&&qr>=r){
		upd[pos].push_back(make_pair(u,v));
		return;
	}
	if(ql<=mid){
		add(pos<<1,l,mid,ql,qr,u,v);
	}
	if(qr>mid){
		add(pos<<1|1,mid+1,r,ql,qr,u,v);
	}
}
inline void dfs(int pos,int l,int r){
	for(pii i:upd[pos])merge(i.first,i.second);
	if(l==r)puts(fuck?"NO":"YES");
	else dfs(pos<<1,l,mid),dfs(pos<<1|1,mid+1,r);
	F(i,1,upd[pos].size())pop();
}
int main() {
	cin>>n>>m;
	F(i,1,n)fa[i]=i,sz[i]=1;
	F(i,1,m){
		int x=read(),y=read();
		if(x>y)swap(x,y);
		if(id[make_pair(x,y)]){
			r[id[make_pair(x,y)]]=i-1;
			id.erase(make_pair(x,y));
		}else{
			++cnt;
			l[cnt]=i;
			u[cnt]=x,v[cnt]=y;
			id[make_pair(x,y)]=cnt;
		}
	}
	for(auto x:id)r[x.second]=m;
	F(i,1,cnt)add(1,1,m,l[i],r[i],u[i],v[i]);
	cnt=0;
	dfs(1,1,m);
	return 0;
}