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
int n,m,t1,t2,tag[200002],d[200002],fa[200002],p[200002],q;
bool vis[200002];
vector<int>g[200002],c[200002];
inline void dfs(int pos){
	d[pos]=d[fa[pos]]+1;
	vis[pos]=true;
	bool kk=false;
	for(int i:g[pos]){
		if(kk||i!=fa[pos]){
			if(!vis[i]){
				fa[i]=pos;
				c[pos].push_back(i);
				dfs(i);
				tag[pos]+=tag[i];
			}else if(d[i]<d[pos]){
				++tag[pos];
				--tag[i];
			}
		}else kk=true;
	}
}
namespace T{
	int fa[200002][18],x[200002],y[200002],d[200002];
	vector<int>c[200002],root;
	vector<pii>a;
	inline void dfs(int pos){
		d[pos]=d[fa[pos][0]]+1;
		F(i,1,17)fa[pos][i]=fa[fa[pos][i-1]][i-1];
		for(int i:c[pos])dfs(i);
	}
	inline int lca(int x,int y){
		if(d[x]>d[y]){
			int c=d[x]-d[y];
			UF(i,17,0)if(c>>i&1)x=fa[x][i];
		}else if(d[y]>d[x]){
			int c=d[y]-d[x];
			UF(i,17,0)if(c>>i&1)y=fa[y][i];
		}
		if(x==y)return x;
		UF(i,17,0)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
		return fa[x][0];
	}
	inline void orz(int pos){
		for(int i:c[pos]){
			orz(i);
			x[pos]+=x[i];
			y[pos]+=y[i];
		}
		if(x[pos]&&y[pos]){
			puts("No");
			exit(0);
		}
	}
	void solve(){
		F(i,1,q)a.push_back(make_pair(p[read()],p[read()]));
		for(int i:root)dfs(i);
		for(pii i:a){
			int l=lca(i.first,i.second);
			if(!l){
				puts("No");
				return;
			}
			++x[i.first];++y[i.second];--x[l];--y[l];
		}
		for(int i:root)orz(i);
		puts("Yes");
	}
}
inline void solve(int pos){
	if(tag[pos])p[pos]=p[fa[pos]];
	else{
		p[pos]=pos;
		if(fa[pos])T::fa[pos][0]=p[fa[pos]],T::c[p[fa[pos]]].push_back(pos);
	}
	for(int i:c[pos]){
		solve(i);
	}
}
int main(){
	cin>>n>>m>>q;
	F(i,1,m){
		read(t1);read(t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	F(i,1,n)if(!vis[i]){
		T::root.push_back(i);
		dfs(i);
		solve(i);
	}
	T::solve();
    return 0;
}