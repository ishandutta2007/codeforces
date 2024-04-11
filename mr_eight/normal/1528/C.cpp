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
int n,a[300002],b[300002],topo[300002],cnt,sz[300002],head[300002],nxt[300002],ans,temp;
int heada[300002],nxta[300002];
ll c[300002];
int d[300002];
inline void dfs(int pos){
	topo[pos]=++cnt;sz[pos]=1;
	for(ri i=heada[pos];i;i=nxta[i])dfs(i),sz[pos]+=sz[i];
}
inline void addc(int pos,ll v){
	while(pos<=n){
		c[pos]+=v;
		pos+=(-pos&pos);
	}
}
inline ll queryc(int pos){
	ll rt=0;
	while(pos){
		rt+=c[pos];
		pos-=(-pos&pos);
	}
	return rt;
}
inline void addd(int pos,int v){
	while(pos<=n){
		d[pos]+=v;
		pos+=(-pos&pos);
	}
}
inline int queryd(int pos){
	int rt=0;
	while(pos){
		rt+=d[pos];
		pos-=(-pos&pos);
	}
	return rt;
}
inline void play(int pos){
	int anc=0;
	if(queryd(topo[pos]+sz[pos]-1)-queryd(topo[pos]-1)==0){
		if(anc=queryc(topo[pos])){
			addc(topo[anc],-anc);
			addc(topo[anc]+sz[anc],anc);
			addd(topo[anc],-1);
			addd(topo[pos],1);
			addc(topo[pos],pos);
			addc(topo[pos]+sz[pos],-pos);
		}else{
			anc=-1;
			addd(topo[pos],1);
			addc(topo[pos],pos);
			addc(topo[pos]+sz[pos],-pos);
			++temp;
		}
	}
	ans=max(ans,temp);
	for(ri i=head[pos];i;i=nxt[i])play(i);
	if(anc>0){
		addc(topo[anc],anc);
		addc(topo[anc]+sz[anc],-anc);
		addd(topo[anc],1);
		addd(topo[pos],-1);
		addc(topo[pos],-pos);
		addc(topo[pos]+sz[pos],pos);
	}else if(anc==-1){
		addd(topo[pos],-1);
		addc(topo[pos],-pos);
		addc(topo[pos]+sz[pos],pos);
		--temp;
	}
}
int main() {
	F(iakioi,1,read()){
		read(n);cnt=0;ans=0;temp=0;
		F(i,2,n)read(b[i]),head[i]=nxt[i]=heada[i]=nxta[i]=0;
		head[1]=nxt[1]=heada[1]=nxta[1]=0;F(i,1,n)sz[i]=0;
		F(i,2,n)read(a[i]);
		F(i,2,n){
			nxta[i]=heada[a[i]];
			heada[a[i]]=i;
		}
		F(i,2,n){
			nxt[i]=head[b[i]];head[b[i]]=i;
		}
		F(i,1,n)c[i]=d[i]=0;
		dfs(1);
		play(1);
		write(ans,'\n');
	}
	return 0;
}