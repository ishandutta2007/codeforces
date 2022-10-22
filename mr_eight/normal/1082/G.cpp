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
#define int long long
const int MAXN=100002,MAXM=1000002;
int cnt=1,S,T,head[MAXN],deep[MAXN],to[MAXM<<1],v[MAXM<<1],nxt[MAXM<<1],now[MAXN<<1];
inline void clear(){
	cnt=1;
	S=T=0;
	memset(head,0,sizeof(head));
	memset(deep,0,sizeof(deep));
	memset(to,0,sizeof(to));
	memset(v,0,sizeof(v));
	memset(nxt,0,sizeof(nxt));
	memset(now,0,sizeof(now));
}
inline void add(int x,int y,int vv){
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
	v[cnt]=vv;
}inline void ed(int x,int y,int vv){
	add(x,y,vv);
	add(y,x,0);
}
inline bool bfs(){
	memset(deep,0,sizeof(deep));
	deep[S]=1;
	queue<int>q;
	q.push(S);
	ri h;
	while(!q.empty()){
		h=q.front();
		q.pop();
		now[h]=head[h];
		for(ri i=head[h];i;i=nxt[i]){
			if(!deep[to[i]]&&v[i]>0){
				q.push(to[i]);
				deep[to[i]]=deep[h]+1;
			}
		}
	}return deep[T];
}
inline int dfs(int pos,int mmax){
	if(pos==T)return mmax;
	ri rt=0;
	for(ri i=now[pos];i&&mmax;i=nxt[i]){
		now[pos]=i;
		if(deep[to[i]]==deep[pos]+1&&v[i]>0){
			ri k=dfs(to[i],min(mmax,v[i]));			
			if(k==0)deep[to[i]]=INT_MAX-2;
			else{
				rt+=k;
				mmax-=k;
				v[i]-=k;
				v[i^1]+=k;
			}
		}
	}return rt;
}
inline int Dinic(){
	ri rt=0;
	while(bfs()){
		rt+=dfs(S,INT_MAX);
	}return rt;
}
int n,m,temp,ans;
signed main(){
	cin>>n>>m;
	S=0,T=n+m+1;
	F(i,1,n){
		ed(S,i,read());
	}F(i,1,m){
		ed(read(),i+n,1e14);
		ed(read(),i+n,1e14);
		ed(i+n,T,temp=read());
		ans+=temp;
	}cout<<ans-Dinic();
	return 0;
}