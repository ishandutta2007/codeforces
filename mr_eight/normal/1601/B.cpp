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
#include <random>
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
int n,dis[300002],l[300002],r[300002],b[300002],pre[300002],pa[300002];
set<int>res;
queue<int>q;
inline void solve(int pos) {
	if(pre[pos]!=n)solve(pre[pos]);
	write(pa[pos],' ');
}
int main() {
	cin>>n;
	F(i,1,n) {
		l[i]=i-read();
		
		r[i]=i;
	}F(i,1,n)b[i]=read();
	memset(dis,0x3f,sizeof(dis));
	dis[n]=0;
	q.push(n);
	F(i,0,n-1)res.insert(i);
	while(!q.empty()) {
		int pos=q.front();
		q.pop();
		auto R=res.upper_bound(r[pos]);
		for(auto i=res.lower_bound(l[pos]); i!=R;) {
			int j=*i;
			if(dis[j+b[j]]>dis[pos]+1) {
				dis[j+b[j]]=dis[pos]+1;
				pre[j+b[j]]=pos;
				q.push(j+b[j]);
				pa[j+b[j]]=j;
			}
			res.erase(i++);
		}
	}
	if(dis[0]<100000000) {
		write(dis[0],'\n');
		solve(0);
	} else puts("-1");
	return 0;
}