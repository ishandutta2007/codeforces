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
int n,m;
bool vis[1002][1002],tag_[1002],tag[1000002];
int x[2000002],y[2000002],v[2000002],ak[1002][1002],temp[2000002];
int fa[500002],tot,mm;
ll ans,orz;
set<int>res;
pii ed[200002];
vector<int>g[200002];
inline int findf(int pos) {
	return (fa[pos]==pos)?pos:(fa[pos]=findf(fa[pos]));
}
inline bool merge(int x,int y) {
	if(findf(x)==findf(y))return 0;
	fa[findf(x)]=findf(y);
	return 1;
}
bool check() {
	F(i,1,n)fa[i]=i;
	if(m<=1ll*n*(n-1)/2-n)return 0;
	F(i,1,m)vis[x[i]][y[i]]=vis[y[i]][x[i]]=1;
	F(i,1,n)F(j,i+1,n)if(!vis[i][j]) {
		if(!merge(i,j))return 0;
	}
	return 1;
}
inline bool cmp(int x,int y) {
	return v[x]<v[y];
}
#define tag tag_
inline void getorz(int pos,int fa) {
	tag[pos]=1;
	F(i,0,g[pos].size()-1) {
		if(g[pos][i]!=fa)getorz(g[pos][i],pos);
	}
}
inline void dfs(int pos,int fa) {
	memset(tag,0,sizeof(tag));
	getorz(pos,fa);
	if(!vis[pos][fa])F(i,1,n)if(tag[i])F(j,1,n)if(!tag[j])if(vis[i][j])orz=min(orz,ans+ak[i][j]);
	F(i,0,g[pos].size()-1)if(g[pos][i]!=fa)dfs(g[pos][i],pos);
}
#undef tag
queue<int>q;
inline void play(int pos) {
	q.push(pos);res.erase(pos);
	while(!q.empty()) {
		pos=q.front();q.pop();
		tag[pos]=1;
		for(set<int>::iterator d=res.begin(),nxt; d!=res.end(); d=nxt) {
			nxt=++d;
			--d;
			ri temp=*d;
			if(!binary_search(ed+1,ed+mm+1,make_pair(pos,temp))&&!binary_search(ed+1,ed+mm+1,make_pair(temp,pos))) {
				
				res.erase(d);
				x[++m]=pos;
				y[m]=temp;
				q.push(temp);
			}
		}
	}

}
int main() {
	cin>>n>>m;
	F(i,1,m)read(x[i]),read(y[i]),read(v[i]),tot^=v[i],ed[i]=make_pair(x[i],y[i]);
	sort(ed+1,ed+m+1);mm=m;
	if(check()) {if(n>1000)while(1);
		F(i,1,m)ak[x[i]][y[i]]=ak[y[i]][x[i]]=v[i];
		m=0;
		F(i,1,n) {
			fa[i]=i;
			F(j,i+1,n) {
				x[++m]=i;
				y[m]=j;
				v[m]=ak[i][j];
			}
		}
		F(i,1,m)temp[i]=i;
		sort(temp+1,temp+m+1,cmp);
		F(ii,1,m) {
			ri i=temp[ii];
			if(merge(x[i],y[i])) {
				g[x[i]].push_back(y[i]);
				g[y[i]].push_back(x[i]);
				ans+=v[i];
			}
		}
		orz=ans+tot;
		dfs(1,0);
		write(orz);return 0;
	} else {
		F(i,1,n)res.insert(i);
		F(i,1,n)if(!tag[i]) {
			play(i);
		}
		F(i,1,n)fa[i]=i;
		F(i,1,m)temp[i]=i;
		sort(temp+1,temp+m+1,cmp);
		F(ii,1,m) {
			ri i=temp[ii];
			if(merge(x[i],y[i])) {
				g[x[i]].push_back(y[i]);
				g[y[i]].push_back(x[i]);
				ans+=v[i];
			}
		}
		write(ans);
	}
	return 0;
}