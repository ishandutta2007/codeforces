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
#define mod 1000000007
int n,m,f[200002],ff[200002],s,t,dis[200002],x[200002],cnt;
vector<int>g[200002];
bool vis[200002];
inline void bfs(int pos) {
	queue<int>q;
	q.push(pos);
	vis[pos]=true;
	while(!q.empty()) {
		pos=q.front();
		x[++cnt]=pos;
		q.pop();
		for(auto i:g[pos]) {
			if(!vis[i]) {
				vis[i]=true;
				dis[i]=dis[pos]+1;
				f[i]=f[pos];
				q.push(i);
			}else if(dis[i]==dis[pos]+1)(f[i]+=f[pos])%=mod;
		}
	}
	
}
int main() {
	F(asdf,1,read()) {
		read(n);
		read(m);
		read(s);
		read(t);cnt=0;
		F(i,1,n)g[i].clear(),f[i]=ff[i]=vis[i]=0,dis[i]=1e9;
		dis[s]=0;
		F(i,1,m) {
			int t1=read(),t2=read();
			g[t1].push_back(t2);
			g[t2].push_back(t1);
		}
		f[s]=ff[s]=1;
		bfs(s);
		F(ii,2,cnt){int i=x[ii];
			for(auto j:g[i]){
				if(dis[j]==dis[i]-1)(ff[i]+=ff[j])%=mod;
				else if(dis[j]==dis[i])(ff[i]+=f[j])%=mod;
			}
		}
		write(ff[t],'\n');
	}
	return 0;
}