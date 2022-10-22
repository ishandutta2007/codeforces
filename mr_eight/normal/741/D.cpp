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
int fa[500002],tag[500002],n,sz[500002],d[500002],ans[500002],mmax[500002],a[500002];
vector<int>c[500002];
int vis[5000002];
char ch[500002];
inline void dfs(int pos){
	d[pos]=d[fa[pos]]+1;
	if(pos!=1)a[pos]=a[fa[pos]]^(1<<ch[pos]-'a');
	sz[pos]=1;
	if(c[pos].empty())return;
	for(int i:c[pos]){
		dfs(i);
		if(sz[i]>sz[mmax[pos]])mmax[pos]=i;
		sz[pos]+=sz[i];
	}
}
inline int query(int x){
	int rt=vis[x];
	F(i,0,21)rt=max(rt,vis[x^(1<<i)]);
	return rt;
}
inline int play(int x,int anc){
	int rt=query(a[x])+d[x]-(d[anc]<<1);
	for(int i:c[x])rt=max(rt,play(i,anc));
	return rt;
}
inline void ins(int x,int anc){
	vis[a[x]]=max(vis[a[x]],d[x]);
	for(int i:c[x])ins(i,anc);
}
inline void cl(int pos){
	vis[a[pos]]=-1000000000;
	for(int i:c[pos])cl(i);
}
inline void getans(int pos,bool orz){
	if(c[pos].empty()){
		if(orz)vis[a[pos]]=d[pos];
		return;
	}
	for(int i:c[pos])if(mmax[pos]!=i)getans(i,false),ans[pos]=max(ans[pos],ans[i]);
	getans(mmax[pos],true);
	ans[pos]=max(ans[pos],ans[mmax[pos]]);
	ans[pos]=max(ans[pos],query(a[pos])-d[pos]);
	vis[a[pos]]=max(vis[a[pos]],d[pos]);
	for(int i:c[pos])if(i!=mmax[pos]){
		ans[pos]=max(ans[pos],play(i,pos));
		ins(i,pos);
	}
	if(!orz)cl(pos);
}
int main(){
	memset(vis,-0x3f,sizeof(vis));
	cin>>n;
	F(i,2,n){
		read(fa[i]);c[fa[i]].push_back(i);
		while(!isalpha(ch[i]=getchar()));
	}
	dfs(1);
	getans(1,true);
	F(I,1,n)write(ans[I],' ');
    return 0;
}