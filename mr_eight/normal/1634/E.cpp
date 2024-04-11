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
const int MAXN=1000005,MAXM=2000005;
int head[MAXN],nxt[MAXM],n,m,to[MAXM],x,y,deg[MAXN],sta[MAXM],cnt,num,a[MAXN],b[MAXN],c[MAXN],d[MAXN];
bool vis[MAXM>>1];
string ans[MAXN];
int tp;
inline void dfs1(int pos) {
	for(int &e=head[pos]; e; e=nxt[e]) {
		if(vis[e>>1])continue;
		int temp=e;
		vis[e>>1]=1;
		dfs1(to[e]);
		sta[++cnt]=temp;
	}
}
inline void dfs2(int pos) {
	for(int &e=head[pos]; e; e=nxt[e]) {
		if(vis[e])continue;
		int temp=e;
		vis[e]=1;
		dfs2(to[e]);
		sta[++cnt]=temp;
	}
}
inline void ed(int x,int y,int i) {
	++deg[x],++deg[y];
	to[i<<1]=y;
	nxt[i<<1]=head[x];
	head[x]=(i<<1);
	to[i<<1|1]=x;
	nxt[i<<1|1]=head[y];
	head[y]=(i<<1|1);
}
map<int,pii>id;
pii temp;
int main() {
	// tp==1
	tp=1;
	cin>>n;
	F(i,1,n) {
		int k=read();
		F(j,1,k){
			int x=read();
			if((temp=id[x])!=make_pair(0,0)){
				ed(temp.first,i,++num);
				a[num]=temp.first,b[num]=temp.second,c[num]=i,d[num]=j;
				id[x]=make_pair(0,0);
			}else{
				id[x]=make_pair(i,j);
			}
		}
		ans[i].resize(k);
	}
	for(auto i:id)if(i.second!=make_pair(0,0)){
		puts("NO");
		return 0;
	}
	puts("YES");
	F(i,1,n)dfs1(i);
	F(i,1,cnt){
		if(sta[i]&1){
			sta[i]>>=1;
			ans[a[sta[i]]][b[sta[i]]-1]='L';
			ans[c[sta[i]]][d[sta[i]]-1]='R';
		}else{
			sta[i]>>=1;
			ans[a[sta[i]]][b[sta[i]]-1]='R';
			ans[c[sta[i]]][d[sta[i]]-1]='L';
		}
	}
	F(i,1,n)puts(ans[i].c_str());
	return 0;
}