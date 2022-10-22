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
struct node{
	ll a,c;
	int p;
}pos[100002];
int n,orz,cnt,sta[100002],qwq[100002];
ll dp,now;
inline bool cmp(node x,node y){
	return x.a<y.a;
}
inline ll query(int x,int y){
	return max(pos[y].a-pos[x].c,0ll);
}
int main() {
	cin>>n;
	F(i,1,n){
		pos[i].a=read();
		pos[i].c=pos[i].a+read();
		pos[i].p=i;
	}sort(pos+1,pos+n+1,cmp);
	F(i,1,n)if(pos[i].p==1)orz=i;now=1;
	sta[cnt=1]=1;
	F(i,2,n){
		if(pos[i].c>=pos[sta[cnt]].c)sta[++cnt]=i;
		qwq[i]=cnt;
	}if(sta[cnt]!=n)sta[++cnt]=n;
	while(now<n){
		ri nxt=qwq[now];
		while(nxt<cnt&&query(now,sta[nxt+1])==0)++nxt;
		if(now>=sta[nxt])nxt++;
		nxt=sta[nxt];
		dp+=query(now,nxt);
		now=nxt;
	}F(i,1,n)dp+=pos[i].c-pos[i].a;
	write(dp);
	return 0;
}