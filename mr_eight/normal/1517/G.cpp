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
#define pii pair<long,long>
#define cp complex<double>
//#pra gma G CC opti mize(3)
#define int long long
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
map<pii,int>mp;
signed main(){
	T=100001;
	int n=read(),t1[1002],t2[1002],t3[1002],tot=0;
	F(i,1,n){
		read(t2[i]);read(t1[i]);read(t3[i]);
		mp[make_pair(t1[i],t2[i])]=i;tot+=t3[i];
		ed(2*i-1,2*i,t3[i]);
	}
	F(i,1,n){
		if((t1[i]&1)&&(t2[i]&1)){cerr<<"0 "<<i<<endl;
			ed(S,2*i-1,1e14);
			if(mp[make_pair(t1[i],t2[i]-1)])ed(2*i,2*mp[make_pair(t1[i],t2[i]-1)]-1,1e14);
			if(mp[make_pair(t1[i],t2[i]+1)])ed(2*i,2*mp[make_pair(t1[i],t2[i]+1)]-1,1e14);
		}else if(t2[i]&1){cerr<<"3 "<<i<<endl;
			ed(2*i,T,1e14);
		}else if(t1[i]&1){cerr<<"1 "<<i<<endl;
			if(mp[make_pair(t1[i]+1,t2[i])])ed(2*i,2*mp[make_pair(t1[i]+1,t2[i])]-1,1e14);
			if(mp[make_pair(t1[i]-1,t2[i])])ed(2*i,2*mp[make_pair(t1[i]-1,t2[i])]-1,1e14);
		}else{cerr<<"2 "<<i<<endl;
			if(mp[make_pair(t1[i],t2[i]-1)])ed(2*i,2*mp[make_pair(t1[i],t2[i]-1)]-1,1e14);
			if(mp[make_pair(t1[i],t2[i]+1)])ed(2*i,2*mp[make_pair(t1[i],t2[i]+1)]-1,1e14);
		}
	}write(tot-Dinic());
	return 0;
}