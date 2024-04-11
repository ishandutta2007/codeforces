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
int len[100002],L,R,root,mmax[100002],sz[100002],fa[100002],a[100002],t[100002],f[100002],big[100002],num,n,m,t1,t2,t3,dp[100002],size[100002],head[100002];
vector<int>g[100002],c[100002],w[100002],ff[100002];
vector<pii >ch[100002];
bool vis[100002];
inline void make_tree(int pos) {
	vis[pos]=1;
	dp[pos]=dp[f[pos]]+1;
	size[pos]=1;
	F(i,0,g[pos].size()-1)
	if(!vis[g[pos][i]]) {
		f[g[pos][i]]=pos;
		c[pos].push_back(g[pos][i]);
		make_tree(g[pos][i]);
		size[pos]+=size[g[pos][i]];
	}
}
inline int lca(int x,int y) {
	while(head[x]!=head[y]) {
		if(dp[head[x]]<dp[head[y]]) {
			y=f[head[y]];
		} else {
			x=f[head[x]];
		}
	}
	if(dp[x]<dp[y])return x;
	else return y;
}
void dfs(int pos,bool isbig) {
	if(isbig)head[pos]=head[f[pos]];
	else head[pos]=pos;
	t[pos]=++num;
	ri mmax=0,mpos=0;
	F(i,0,c[pos].size()-1) {
		if(size[c[pos][i]]>mmax) {
			mpos=c[pos][i];
			mmax=size[c[pos][i]];
		}
	}
	big[pos]=mpos;
	if(c[pos].size())dfs(mpos,1);
	F(i,0,c[pos].size()-1)if(c[pos][i]!=mpos)dfs(c[pos][i],0);
}
inline void getmax(int pos,int fa) {
	sz[pos]=1;
	F(i,0,g[pos].size()-1) {
		if(g[pos][i]!=fa&&!vis[g[pos][i]]) {
			getmax(g[pos][i],pos);
			sz[pos]+=sz[g[pos][i]];
		}
	}
}
inline int findh(int pos,int fa,int tot) {
	ri rt=pos;
	mmax[pos]=tot-sz[pos];
	F(i,0,g[pos].size()-1) {
		if(!vis[g[pos][i]]&&g[pos][i]!=fa)mmax[pos]=max(mmax[pos],sz[g[pos][i]]);
	}
	F(i,0,g[pos].size()-1) {
		if(!vis[g[pos][i]]&&g[pos][i]!=fa) {
			ri nxt=findh(g[pos][i],pos,tot);
			if(mmax[rt]>mmax[nxt])rt=nxt;
		}
	}
	return rt;
}
int orz[200002],sto[200002],q[200002],l,r,P;
inline int dfg(int pos) {
	getmax(pos,0);
	ri h=findh(pos,0,sz[pos]);
	vis[h]=1;
	F(i,0,g[h].size()-1)if(!vis[g[h][i]])ch[h].push_back(make_pair(g[h][i],dfg(g[h][i])));
	return h;
}
inline bool in(int x,int y) {
	return t[x]>=t[y]&&t[x]<t[y]+sz[y];
}
inline int getlen(int x,int lst,int anc) {
	int rt=0;
	for(int i:g[x])if(i!=lst&&in(i,anc))rt=max(rt,getlen(i,x,anc)+1);
	return rt;
}
inline void dfs2(int x) {
	t[x]=++num;
	sz[x]=1;
	for(pii i:ch[x]) {
		dfs2(i.second);
		sz[x]+=sz[i.second];
	}
	len[x]=getlen(x,x,x);
	for(int i:g[x]){
		if(in(i,x))ff[x].push_back(getlen(i,x,x)+1);
		else ff[x].push_back(0);
	}
}
int NOW,K;
inline void fix(int len){
	sto[len]=orz[len];
	if(len<=R-L){
		UF(i,len-1,0)sto[i]=max(orz[i],sto[i+1]);
		return;
	}
	l=r=0;
	q[0]=len;
	UF(i,len-1,len-(R-L)){
		sto[i]=max(orz[i],sto[i+1]);
		while(l<=r&&orz[i]>orz[q[l]])++l;
		q[++r]=i;
	}
	UF(i,len-(R-L)-1,0){
		while(l<=r&&orz[i]>orz[q[l]])++l;
		q[++r]=i;
		if(q[l]==i+(R-L)+1)++l;
		sto[i]=orz[q[l]];
	}
}
inline void fix2(int len){
	sto[len]=orz[len];
	if(len<=R-L){
		UF(i,len-1,0)sto[i]=max(sto[i],max(orz[i],sto[i+1]));
		return;
	}
	l=r=0;
	q[0]=len;
	UF(i,len-1,len-(R-L)){
		sto[i]=max(sto[i],max(orz[i],sto[i+1]));
		while(l<=r&&orz[i]>orz[q[l]])++l;
		q[++r]=i;
	}
	UF(i,len-(R-L)-1,0){
		while(l<=r&&orz[i]>orz[q[l]])++l;
		q[++r]=i;
		if(q[l]==i+(R-L)+1)++l;
		sto[i]=max(sto[i],orz[q[l]]);
	}
}
inline bool play(int pos,int lst,int len,int now,int anc){
	if(!in(pos,anc))return false;
	if(len>R)return false;
	if(L-len<=NOW&&now+sto[L-len]>=0){
		P=pos;
		return true;
	}
	orz[len]=max(orz[len],now);
	F(i,0,g[pos].size()-1)if(g[pos][i]!=lst&&play(g[pos][i],pos,len+1,now+(w[pos][i]>=K?1:-1),anc))return true;
	return false;
}
inline bool check(int k) {K=k;
	F(x,1,n) {//if(k==2)cerr<<x<<"kkk"<<endl;
		F(i,1,len[x]<<1)orz[i]=sto[i]=-114514;
		orz[0]=0;
		NOW=len[x];fix(NOW);
		F(i,0,g[x].size()-1){//if(k==2)cerr<<g[x][i]<<endl;
			if(play(g[x][i],x,1,(w[x][i]>=k?1:-1),x))return true;
			fix2(ff[x][i]);
		}
	}
	return false;
}
inline void getans(int pos,int lst,int len,int now){
	if(len>R)return;
	if(len>=L&&now>=0){
		cout<<P<<" "<<pos<<endl;
		exit(0);
	}
	F(i,0,g[pos].size()-1)if(g[pos][i]!=lst)getans(g[pos][i],pos,len+1,now+(w[pos][i]>=K?1:-1));
}
void dbg(){return;
	F(i,0,n){
		read(orz[i]);
	}fix(n);
	F(i,0,n)write(sto[i],' ');
	exit(0);
}
int main() {
	cin>>n>>L>>R;
	dbg();
	F(i,2,n) {
		t1=read(),t2=read();
		t3=read();
		g[t1].push_back(t2);
		g[t2].push_back(t1);
		w[t1].push_back(t3);
		w[t2].push_back(t3);
	}
	make_tree(1);
	dfs(1,0);
	memset(vis,0,sizeof(vis));
	root=dfg(1);
	num=0;
	dfs2(root);
	int l=0,r=1e9;
	while(l<r) {
		int mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	K=l;//cerr<<l<<" "<<P<<endl;
	if(l==0)check(l);
	getans(P,P,0,0);
	return 0;
}