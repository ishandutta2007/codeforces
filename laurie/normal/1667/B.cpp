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
ll n,a[500002],t[500002];int c[500002],dp[500002],qwq[500002];
inline void add(int pos,int v){++pos;
	while(pos<=n+1){
		c[pos]=max(c[pos],v);
		pos+=(-pos&pos);
	}
}
inline int query(int pos){++pos;
	int rt=-1e9;
	while(pos){
		rt=max(rt,c[pos]);
		pos-=(-pos&pos);
	}
	return rt;
}
int main() {
	F(iakioi,1,read()){
		read(n);a[0]=0;
		F(i,1,n)read(a[i]),a[i]+=a[i-1],t[i]=a[i];
		t[0]=0;
		sort(t,t+n+1);
		F(i,0,n)a[i]=lower_bound(t,t+n+1,a[i])-t;
		F(i,0,n+1)c[i]=qwq[i]=-1e9;
		dp[0]=0;
		add(a[0],dp[0]);
		qwq[a[0]]=0;
		F(i,1,n){
			dp[i]=max(dp[i-1]-1,query(a[i]-1)+i);//cerr<<a[i]<<endl;
			dp[i]=max(dp[i],qwq[a[i]]);
			add(a[i],dp[i]-i);
			qwq[a[i]]=max(qwq[a[i]],dp[i]);
		}
		write(dp[n],'\n');
	}
	return 0;
}
/*
114514
5
-1 -1 5 -1 -1
5
-1 -1 4 -1 -1
5
-1 -1 5 -1 -1
*/