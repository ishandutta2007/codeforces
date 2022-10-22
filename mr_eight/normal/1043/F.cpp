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
#ifndef LOCAL
	inline char gc() {
		static char buf[1048576], *p1, *p2;
		return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1048576, stdin),
		                    p1 == p2) ? EOF : *p1++;
	}
	inline int read() {
		char ch = gc();
		int r = 0, w = 1;
		for (; ch < '0' || ch > '9'; ch = gc()) if (ch == '-') w = -1;
		for (; '0' <= ch && ch <= '9'; ch = gc()) r = r * 10 + (ch - '0');
		return r * w;
	}
#else
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
#endif
	char _n_u_m_[40];
	template<class T>
	inline void write(T x ) {
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
const int N=4000000;
int n,a[4000002],cnt,x[4000002],g;
int d[4000002];
bool vis[4000002],tag[4000002];
signed char mu[4000002];
signed char dp[4000002];
int main() {//freopen("ex_a2.in","r",stdin);
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	n=read();
	F(i,1,n)g=__gcd(g,x[i]=read());
	if(g>1){
		cout<<-1;return 0;
	}
	F(i,1,n)x[i]/=g;//cerr<<g<<endl;
	int pos;
	F(i,1,n) {
		pos=x[i];
		if(pos!=1) {
			++a[pos];
		}else{
			++cnt;
		}
	}
	if(cnt){
		cout<<1;
		return 0;
	}
	F(i,1,N)mu[i]=d[i]=1;
	F(i,2,N) {
		if(!vis[i]) {
			mu[i]=-1;
			d[i]=i;
			UF(j,N/i,2) {
				a[j]+=a[j*i];
				d[j*i]*=i;
				vis[j*i]=true;
				mu[i*j]=-mu[i*j];
			}
			UF(j,N/i/i,1)mu[j*i*i]=0;
		}
	}
	F(i,1,n)dp[d[x[i]]]=1;
	a[1]=n;
	F(i,1,N)d[i]=n;
//	F(i,1,100)cerr<<(int)mu[i]<<" ";
	F(i,2,N)if(mu[i]) {
		if(mu[i]==1)for(int j=i; j<=N; j+=i)d[j]+=a[i];
		else for(int j=i; j<=N; j+=i)d[j]-=a[i];
	}
	F(i,1,N)tag[i]=(d[i]!=0&&mu[i]);
	UF(i,N,1){
		if(mu[i]){
			for(int j=i+i,k=2;j<=N;j+=i,++k)if(tag[k]&&mu[j])dp[i]=min((int)dp[i],dp[j]+1);
		}
	}
	cout<<(int)dp[1];
	return 0;
}