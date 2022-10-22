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
const int B=1000;
int n,k,f[100002],g[100002],head[100002],nxt[100002],t1,t2;
vector<int>gg[100002];
inline void mt(int pos,int fa){
	for(int i:gg[pos])if(i!=fa){
		nxt[i]=head[pos];
		head[pos]=i;
		mt(i,pos);
	}
}
inline void dfs(int pos){
	if(!head[pos]){
		g[pos]=1;
		return;
	}
	int mmax=0,sec=0;
	for(int i=head[pos];i;i=nxt[i]){
		dfs(i);
		f[pos]+=f[i];
		if(g[i]>mmax)sec=mmax,mmax=g[i];
		else if(g[i]>sec)sec=g[i];
	}
	if(mmax+sec+1>=k)++f[pos];
	else g[pos]=mmax+1;
}
inline int getans(int x){
	k=x;
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	dfs(1);
	return f[1];
}
int main() {
	cin>>n;
	F(i,2,n){
		read(t1);read(t2);
		gg[t1].push_back(t2);
		gg[t2].push_back(t1);
	}
	mt(1,0);
	write(n,'\n');
	F(i,2,min(B,n))write(getans(i),'\n');
	if(n>B){
		for(int l=B+1,r;l<=n;l=r+1){
			int temp=getans(l);
			r=l;
			UF(i,20,0)if((n-r)>=(1<<i)&&getans(r+(1<<i))==temp)r+=(1<<i);
			F(i,l,r)write(temp,'\n');
		}
	}
	return 0;
}