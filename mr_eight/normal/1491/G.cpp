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
int n,nxt[200002],qwq,ansx[200002],ansy[200002],cnt;
vector<int>loop[200002];
bool vis[200002],tag[200002];
inline void play(int x,int y) {
	qwq++;
	ansx[qwq]=x;
	ansy[qwq]=y;
	swap(nxt[x],nxt[y]);
	tag[x]=!tag[x];
	tag[y]=!tag[y];
	swap(tag[x],tag[y]);
}
inline void solve(int x,int y) {
	play(loop[x][0],loop[y][0]);
	x=loop[x][0];
	y=loop[y][0];
	ri z;
	while(!tag[nxt[x]]) {
		z=nxt[x];
		play(z,x);
	}
	while(!tag[nxt[y]]) {
		z=nxt[y];
		play(z,y);
	}
	play(x,y);
}
inline void orz() {
	ri x=1,y=nxt[1],z=nxt[nxt[1]];
	play(x,y);
	play(y,z);
	while(!tag[nxt[x]]) {
		z=nxt[x];
		play(z,x);
	}
	while(!tag[nxt[y]]) {
		z=nxt[y];
		play(z,y);
	}
	play(x,y);
}
#include<assert.h>
int main() {
	cin>>n;
	F(i,1,n)read(nxt[i]);
	F(i,1,n) {
		if(!vis[i]) {
			ri pos=i;
			loop[++cnt].push_back(i);
			vis[i]=1;
			pos=nxt[pos];
			while(pos!=i) {
				loop[cnt].push_back(pos);
				vis[pos]=1;
				pos=nxt[pos];
			}
		}
	}
	F(i,1,cnt/2) {
		solve(2*i,2*i-1);
	}
	if(cnt&1) {
		if(cnt==1) {
			orz();
		} else {
			solve(cnt,1);
		}
	}

	cout<<qwq<<endl;
	F(i,1,n)assert(!tag[i]);
	F(i,1,qwq) {
		write(ansx[i],' ');
		write(ansy[i],'\n');
	}
	return 0;
}