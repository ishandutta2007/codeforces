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
#define vi vector<int>
#define ull unsigned long long
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
int n,m,orz[300002],x[300002],y[300002],deg[300002];
vector<int>g[300002];
queue<int>q;
inline void fuck_ccf(){
	F(i,1,n)if(!deg[i])q.push(i);
	F(tot,1,n){
		int pos=q.front();
		q.pop();
		if(!q.size())orz[pos]+=n-tot;
		else if(q.size()==1){
			int nxt=q.front();
			for(int i:g[nxt])if(deg[i]==1)goto OvO;
			orz[pos]+=n-tot-1;
			OvO:;
		}
		for(int i:g[pos]){
			--deg[i];
			if(!deg[i])q.push(i);
		}
	}
}
int main() {
	cin>>n>>m;
	F(i,1,m){
		read(x[i],y[i]);
		++deg[y[i]];
		g[x[i]].push_back(y[i]);
	}
	fuck_ccf();
	F(i,1,n)g[i].clear();
	memset(deg,0,sizeof(deg));
	F(i,1,m){
		g[y[i]].push_back(x[i]);
		++deg[x[i]];
	}
	fuck_ccf();
	int iakioi=0;
	F(i,1,n)if(orz[i]>=n-2)++iakioi;
	cout<<iakioi;
	return 0;
}