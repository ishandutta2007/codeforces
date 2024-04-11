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
		if(x==0) {
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
char c[300002];
int t[300002],n,m,p[300002],sta[300002],cnt,tl[300002],tr[300002],l[300002],r[300002],tot,dfn[300002],sz[300002];
ll sum[320002],a[320002],res[300002],tt;
ll ans[300002],to[300002],orz[300002],fa[300002];
const int B=400;
vector<int>temp,vec[300002];
vector<int>upd[300002],q[300002];
bool vis[300002];
inline ll f(ll x) {
	if(x<0)return 0;
	return x*(x+1)>>1;
}
inline void add(int x,ll v) {
	if(x<0)return;
	sum[x>>8]+=v;
	a[x]+=v;
}
inline ll query(int x) {
	ll rt=0;
	while(x&255)rt+=a[x++];
	F(i,x>>8,tot)rt+=sum[i];
	return rt;
}
inline void dfs(int pos) {
	int qwq=pos;
	dfn[pos]=++tt;sz[pos]=1;
	pos++;
	while(c[pos]=='('&&p[pos]) {
		vis[pos]=true;
		dfs(pos);
		sz[qwq]+=sz[pos];
		pos=p[pos]+1;
	}
}
int main() {
	cin>>n>>m;
	tot=(n-1)>>8;
	++tot;
	scanf("%s",c+1);
	F(i,1,m) {
		read(t[i]),read(l[i]),read(r[i]);
		if(t[i]==2)q[r[i]].push_back(i);
	}
	F(i,1,n) {
		if(c[i]=='(')sta[++cnt]=i;
		else {
			if(cnt)p[sta[cnt--]]=i,p[i]=sta[cnt+1];
		}
	}
	F(i,1,n) {
		if(p[i]&&c[i]=='('&&!vis[i])dfs(i);
	}
	memset(vis,0,sizeof(vis));
	F(i,1,n)if(!vis[i]&&c[i]=='(') {
		int pos=i,now=0;
		temp.clear();
		while(c[pos]=='('&&p[pos]) {
			vis[pos]=true;
			if(p[i-1]&&c[i-1]=='(')fa[pos]=i-1;
			temp.push_back(pos);
			to[pos]=to[p[pos]]=i;
			orz[pos]=orz[p[pos]]=++now;
			pos=p[pos]+1;
		}
		vec[i]=temp;
		if(p[i-1]&&c[i-1]=='('){
			res[i-1]=temp.size();
			add(dfn[i-1],f(temp.size()));
		}
	}
	F(i,1,m){
		if(t[i]==1){
			add(dfn[fa[l[i]]],-(res[fa[l[i]]]--));
			vec[to[l[i]]].erase(lower_bound(vec[to[l[i]]].begin(),vec[to[l[i]]].end(),l[i]));
		}else{
			int pp=to[l[i]];
			ll ans=f(lower_bound(vec[pp].begin(),vec[pp].end(),r[i])-lower_bound(vec[pp].begin(),vec[pp].end(),l[i]));
			write(ans+query(dfn[l[i]])-query(dfn[p[r[i]]]+sz[p[r[i]]]),'\n');
		}
	}
	return 0;
}
/*
6 6
((()))
2 1 6
1 3 4
2 1 6
1 2 5
2 1 6
2 1 6
*/