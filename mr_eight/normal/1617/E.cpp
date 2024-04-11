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
inline int orz(int x){
	if(x==(-x&x))return 0;
	return (1<<(32-__builtin_clz(x)))-x;
}
int t[10000002],a[200002],n,cnt,head[10000002],nxt[10000002],ans=-1,len[10000002],fa[10000002],x,y,d[10000002];
bool vis[10000002],tak[10000002];
inline void dfs(int pos){
	len[pos]=-114514;
	if(vis[pos])len[pos]=0,d[pos]=pos;
	for(int i=head[pos];i;i=nxt[i]){
		dfs(i);
		if(ans<len[pos]+len[i]+1){
			ans=len[pos]+len[i]+1;
			x=d[pos];
			y=d[i];
		}
		if(len[pos]<len[i]+1){
			len[pos]=len[i]+1;
			d[pos]=d[i];
		}
	}
}
inline int getorz(int x){
	F(i,1,n)if(a[i]==x)return i;
	return 114514;
}
int main() {
	cin>>n;
	F(x,1,n){
		read(a[x]);
		for(int i=a[x];i;i=orz(i)){
			t[++cnt]=i;
		}
	}
	sort(t+1,t+cnt+1);
	cnt=unique(t+1,t+cnt+1)-t-1;
	if(*min_element(a+1,a+n+1)==0)vis[0]=true;
	F(x,1,n){
		for(int i=a[x];i;i=orz(i)){
			int p=lower_bound(t,t+cnt,i)-t;
			if(tak[p])continue;tak[p]=true;
			if(i==a[x])vis[p]=true;
			fa[p]=lower_bound(t,t+cnt,orz(i))-t;
			nxt[p]=head[fa[p]];
			head[fa[p]]=p;
		}
	}
	dfs(0);
	cout<<getorz(t[x])<<" "<<getorz(t[y])<<" "<<ans;
	return 0;
}