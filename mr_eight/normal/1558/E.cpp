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
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define vi vector<int>
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
int n,m,a[1002],b[1002],t1,t2,now,cnt,fa[1002];
vi g[1002];
bool vis[1002];
pii orz; 
inline bool dfs(int pos,int now){
	for(auto i:g[pos])if(i!=fa[pos]&&(!vis[pos]||!vis[i])&&now>=a[i]){
		if(vis[i]||fa[i]){
			orz=make_pair(pos,i);
			return 1;
		}else{
			fa[i]=pos;
			if(dfs(i,min(1000000001,now+b[i])))return 1;
		}
	}
	return 0;
}
inline bool add(){
	F(i,1,n)fa[i]=0;
	F(i,1,n)if(vis[i]){
		if(dfs(i,now)){
			for(int x=orz.first;!vis[x];x=fa[x]){
				++cnt;
				now=min(1000000001,now+b[x]);
				vis[x]=1;
			}
			for(int x=orz.second;!vis[x];x=fa[x]){
				++cnt;
				now=min(1000000001,now+b[x]);
				vis[x]=1;
			}
			return 1;
		}
	}
	return 0;
}
bool check(int x){
	now=x;cnt=1;
	F(i,2,n)vis[i]=0;
	vis[1]=1;
	while(cnt<n){
		if(!add())return 0;
	}
	return 1;
}
int main() {
	F(orzhq,1,read()){
		read(n,m);
		F(i,1,n)g[i].clear();
		F(i,2,n)a[i]=read()+1;
		F(i,2,n)read(b[i]);
		F(i,1,m){
			read(t1,t2);
			g[t1].push_back(t2);
			g[t2].push_back(t1);
		}
		int l=2,r=1000000000;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid))r=mid-1;
			else l=mid+1;
		}
		write(r+1,'\n');
	}
	return 0;
}