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
int n,a[200002],c[6000002][2],cnt=1,tot,temp,size[6000002];
bool mark[6000002];
ll ans;
set<int>s;
inline void insert(int pos,int v,int h){
	if(h<0){
		size[pos]++;
		mark[pos]=1;
		return;
	}
	if(!c[pos][v>>h&1])c[pos][v>>h&1]=++cnt;
	insert(c[pos][v>>h&1],v,h-1);
	size[pos]++;
}
inline int play(int x,int y,int deep){
	if(mark[x]){
		return 0;
	}
	ri ans=INT_MAX;
	if((size[c[x][0]]&&size[c[y][0]])||(size[c[x][1]]&&size[c[y][1]])){
		if(size[c[x][0]]&&size[c[y][0]])ans=min(ans,play(c[x][0],c[y][0],deep-1));
		if(size[c[x][1]]&&size[c[y][1]])ans=min(ans,play(c[x][1],c[y][1],deep-1));
	}else{
		if(size[c[x][0]]&&size[c[y][1]])ans=min(ans,play(c[x][0],c[y][1],deep-1)|(1<<deep));
		if(size[c[x][1]]&&size[c[y][0]])ans=min(ans,play(c[x][1],c[y][0],deep-1)|(1<<deep));
	}return ans;
}
inline void dfs(int pos,int deep){
	if(size[c[pos][0]]>1)dfs(c[pos][0],deep-1);
	if(size[c[pos][1]]>1)dfs(c[pos][1],deep-1);
	if(size[c[pos][0]]&&size[c[pos][1]]){
		ans+=play(c[pos][0],c[pos][1],deep-1)|(1<<deep);
	}
}
int main() {
	read(n);
	F(i,1,n){
		read(temp);
		if(!s.count(temp)){
			insert(1,temp,29);
			s.insert(temp);
		}
	}dfs(1,29);
	cout<<ans;
	return 0;
}