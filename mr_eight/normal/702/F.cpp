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
#define uint unsigned int
namespace getrd{
	uint seed=114514;
	inline uint rd(){
		seed^=(seed<<13);
		seed^=(seed>>17);
		seed^=(seed<<5);
		return seed;
	}
}
using getrd::rd;
uint pri[1000002];
int v[1000002],lc[1000002],rc[1000002],root,cnt,tagv[1000002],tagc[1000002],c[1000002];
inline int new_node(int vv){
	v[++cnt]=vv;
	pri[cnt]=rd();
	return cnt;
}
struct pii{
	int a,b;
};
inline bool cmp(pii x,pii y){
	return x.b==y.b?x.a<y.a:x.b>y.b;
}
inline void addv(int x,int vv){
	tagv[x]+=vv;
	v[x]+=vv;
}
inline void addc(int x,int cc){
	tagc[x]+=cc;
	c[x]+=cc;
}
inline void pushdown(int pos){
	if(tagv[pos]){
		addv(lc[pos],tagv[pos]);
		addv(rc[pos],tagv[pos]);
		tagv[pos]=0;
	}
	if(tagc[pos]){
		addc(lc[pos],tagc[pos]);
		addc(rc[pos],tagc[pos]);
		tagc[pos]=0;
	}
}
inline pii split(int pos,int vv){
	if(!pos)return pii{0,0};
	pushdown(pos);
	if(v[pos]<vv){
		pii temp=split(rc[pos],vv);
		rc[pos]=temp.a;
		return pii{pos,temp.b};
	}else{
		pii temp=split(lc[pos],vv);
		lc[pos]=temp.b;
		return pii{temp.a,pos};
	}
}
inline int merge(int x,int y){
	if(!x||!y)return x|y;
	if(pri[x]>pri[y]){
		pushdown(x);
		rc[x]=merge(rc[x],y);
		return x;
	}else{
		pushdown(y);
		lc[y]=merge(x,lc[y]);
		return y;
	}
}
inline void insert(int x){
	pii temp=split(root,v[x]);
	root=merge(merge(temp.a,x),temp.b);
}
inline void insert(int &rt,int x){
	pii temp=split(rt,v[x]);
	rt=merge(merge(temp.a,x),temp.b);
}
inline int pop(int &rt,int vv){
	int fa=0,pos=rt;
	while(lc[pos]){
		pushdown(pos);
		fa=pos;
		pos=lc[pos];
	}
	pushdown(pos);
	if(v[pos]<=vv){
		if(fa)lc[fa]=rc[pos];
		else rt=rc[pos];
		lc[pos]=rc[pos]=0;
		return pos;
	}
	return 0;
}
int n,m;
pii orz[200002];
inline void dfs(int pos){
	pushdown(pos);
	if(lc[pos])dfs(lc[pos]);
	if(rc[pos])dfs(rc[pos]);
}
int main() {
//	freopen("data.txt","r",stdin);
	cin>>m;
	F(i,1,m)read(orz[i].a),read(orz[i].b);
	sort(orz+1,orz+m+1,cmp);
	cin>>n;
	F(i,1,n)read(v[i]),pri[i]=rd(),insert(i);
	F(i,1,m){
		pii temp=split(root,orz[i].a);//cerr<<orz[i].a<<" "<<v[2]<<" "<<temp.b<<endl;
		addc(temp.b,1);
		addv(temp.b,-orz[i].a);
		int pos;
		while(pos=pop(temp.b,orz[i].a-1)){
			insert(temp.a,pos);
		}
		root=merge(temp.a,temp.b);
	}
	dfs(root);
	F(i,1,n)write(c[i],' ');
	return 0;
}