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
const int MAXN=300002;
int n,m,t1,t2,f[MAXN],fa[MAXN][20],d[MAXN],u[MAXN],v[MAXN],cnt,t[MAXN],sz[MAXN],tot,cc[MAXN],ans;
vector<int>g[MAXN],c[MAXN];
bool vis[MAXN];
inline void make_tree(int pos){
	vis[pos]=1;ri nxt;
	F(i,0,g[pos].size()-1){
		nxt=g[pos][i];
		if(!vis[nxt]){
			f[nxt]=pos;
			c[pos].push_back(nxt);
			make_tree(nxt);
		}
	}
}
inline void dfs(int pos){
	t[pos]=++tot;
	sz[pos]=1;
	d[pos]=d[f[pos]]+1;
	fa[pos][0]=f[pos];
	F(i,1,19)fa[pos][i]=fa[fa[pos][i-1]][i-1];
	for(int i:c[pos])dfs(i),sz[pos]+=sz[i];
}
inline int findf(int x,int l){
	UF(i,19,0)if(l>>i&1)x=fa[x][i];
	return x;
}
inline int lca(int x,int y){
	if(d[x]>d[y]){
		UF(i,19,0)if(d[x]>=d[y]+(1<<i))x=fa[x][i];
	}
	if(d[y]>d[x]){
		UF(i,19,0)if(d[y]>=d[x]+(1<<i))y=fa[y][i];
	}
	if(x==y)return x;
	UF(i,19,0)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return f[x];
}
vector<pii >qwq;
inline void ins(int x,int y){
	qwq.push_back(make_pair(x,y));
}
inline bool cmp(pii x,pii y){
	return d[x.second]>d[y.second];
}
inline void add(int pos){
	while(pos<=n){
		++cc[pos];
		pos+=(-pos&pos);
	}
}
inline int query(int pos){
	int rt=0;
	while(pos){
		rt+=cc[pos];
		pos-=(-pos&pos);
	}
	return rt;
}
inline int calc(int l,int r){
	return query(r)-query(l-1);
}
inline bool fuck(pii x){
	return calc(t[x.second],t[x.second]+sz[x.second]-1)-calc(t[x.first],t[x.first]+sz[x.first]-1);
}
inline bool fuck2(int x,int y){
	return calc(1,n)-calc(t[x],t[x]+sz[x]-1)-calc(t[y],t[y]+sz[y]-1);
}
int main(){
    cin>>n>>m;
    F(i,2,n){
    	t1=i,t2=read();
    	g[t1].push_back(t2);
    	g[t2].push_back(t1);
	}make_tree(1);
	dfs(1);
	F(i,1,m){
		int x=read(),y=read();
		if(f[x]==y||f[y]==x){
			puts("-1");
			return 0;
		}
		int l=lca(x,y);
		if(l==x){
			ins(y,findf(y,d[y]-d[x]-1));
		}else if(l==y){
			ins(x,findf(x,d[x]-d[y]-1));
		}else{
			if(t[x]>t[y])swap(x,y);
			u[++cnt]=x;
			v[cnt]=y;
		}
	}
	sort(qwq.begin(),qwq.end(),cmp);
	for(auto i:qwq){
		if(!fuck(i)){
			++ans;
			add(t[i.second]);
		}
	}
	F(i,1,cnt){
		if(!fuck2(u[i],v[i])){
			++ans;
			break;
		}
	}
	cout<<ans;
    return 0;
}