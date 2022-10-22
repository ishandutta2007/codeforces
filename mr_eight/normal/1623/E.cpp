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
char c[200002];
int n,k,t[200002],cnt,l[200002],r[200002],d[200002],sz[200002],fa[200002],p[200002],dfn[200002],tot;
bool orz[200002],ban[200002];
namespace BIT{
	int c[200002];
	inline void add(int pos,int x){
		while(pos<=n)c[pos]+=x,pos+=(-pos&pos);
	}
	inline int query(int pos){
		int rt=0;while(pos)rt+=c[pos],pos-=(-pos&pos);return rt;
	}
}
using BIT::add;
using BIT::query;
inline void dfs(int i){
	dfn[i]=++tot;
	if(l[i])d[l[i]]=d[i]+1,fa[l[i]]=i,dfs(l[i]);
	t[++cnt]=i;p[i]=cnt;
	if(r[i])d[r[i]]=d[i]+1,fa[r[i]]=i,dfs(r[i]);
	sz[i]=sz[l[i]]+sz[r[i]]+1;
}
inline void kk(int pos){
	if(ban[pos]||orz[pos])return;
	ban[pos]=true;
	kk(l[pos]);kk(r[pos]);
}
inline void tag(int pos){
	if(ban[pos]||k<BIT::query(dfn[pos]))return;
	if(orz[pos])return;
	int cnt=0;int p=pos;
	while(!orz[p])++cnt,p=fa[p];
	k-=cnt;
	F(i,1,cnt)orz[pos]=true,BIT::add(dfn[pos],-1),BIT::add(dfn[pos]+sz[pos],1),pos=fa[pos];
}
inline bool cmp(int x,int y){
	return dfn[t[x]]<dfn[t[y]];
}
int main() {ban[0]=orz[0]=true;
	cin>>n>>k;
	scanf("%s",c+1);
	F(i,1,n)read(l[i],r[i]);
	d[1]=1;
	dfs(1);
	F(i,1,n)BIT::add(dfn[i],d[i]),BIT::add(dfn[i]+1,-d[i]);
	int qwq=1;
	F(i,1,n){
		p[i]=i;
		if(c[t[i]]!=c[t[i+1]]){
			if(c[t[i]]>c[t[i+1]]){
				F(j,qwq,i)kk(t[j]);
			}else{
				sort(p+qwq,p+i+1,cmp);
				F(j,qwq,i)tag(t[p[j]]);
			}
			qwq=i+1;
		}
	}
	F(i,1,n){
		putchar(c[t[i]]);
		if(orz[t[i]])putchar(c[t[i]]);
	}
	return 0;
}