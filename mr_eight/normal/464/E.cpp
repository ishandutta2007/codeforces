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
#define mod1 1000000007
#define mod2 1000000123
#define base1 2
#define base2 1331
#define N 100020
struct node{
	int h1,h2;
	bool tag;
	int lst;
}x[20000002];
int lc[20000002],rc[20000002],pw2[1000002],pw1331[1000002],cnt,to[20000002],sta[100002],tot;
inline node merge(const node &x,const node &y,int len){
	return {(1ll*x.h1*pw2[len]+y.h1)%mod1,(1ll*x.h2*pw1331[len]+y.h2)%mod2,false,y.lst?y.lst:x.lst};
}
inline int cpy(int pos){
	++cnt;
	lc[cnt]=lc[pos],rc[cnt]=rc[pos],x[cnt]=x[pos];
	return cnt;
}
#define mid ((l+r)>>1)
inline void pushdown(int pos,int l,int r){
	if(x[pos].tag){
		x[pos].tag=false;
		lc[pos]=cpy(lc[pos]);
		rc[pos]=cpy(rc[pos]);
		x[lc[pos]]={0,0,true,mid};
		x[rc[pos]]={0,0,true,r};
	}
}
inline int update(int pos,int l,int r,int ql,int qr){
	pos=cpy(pos);
	if(ql<=l&&qr>=r){
		x[pos]={0,0,true,r};
		return pos;
	}
	pushdown(pos,l,r);
	if(ql<=mid)lc[pos]=update(lc[pos],l,mid,ql,qr);
	if(qr>mid)rc[pos]=update(rc[pos],mid+1,r,ql,qr);
	x[pos]=merge(x[lc[pos]],x[rc[pos]],r-mid);
	return pos;
}
inline int modify(int pos,int l,int r,int q){
	pos=cpy(pos);
	if(l==r){
		x[pos]={1,1,false,0};
		return pos;
	}
	pushdown(pos,l,r);
	if(q<=mid)lc[pos]=modify(lc[pos],l,mid,q);
	else rc[pos]=modify(rc[pos],mid+1,r,q);
	x[pos]=merge(x[lc[pos]],x[rc[pos]],r-mid);
	return pos;
}
inline int find0(int pos,int l,int r,int q){
	if(x[pos].tag)return q;
	if(l==r)return x[pos].lst;
	if(q<=mid)return find0(lc[pos],l,mid,q);
	int rt=find0(rc[pos],mid+1,r,q);
	return rt?rt:x[lc[pos]].lst;
}
inline int solve(int pos,int q){
	q=N-q;
	int x=find0(pos,1,N,q);
	if(x!=q)pos=update(pos,1,N,x+1,q);
	return modify(pos,1,N,x);
}
inline bool cmp(int a,int b,int l,int r){
	if(l==r)return x[a].lst>x[b].lst;
	if(x[b].tag)return false;
	if(x[a].tag)return x[a].h1!=x[b].h1&&x[a].h2!=x[b].h2;
	if(x[lc[a]].h1==x[lc[b]].h1&&x[lc[a]].h2==x[lc[b]].h2)return cmp(rc[a],rc[b],mid+1,r);
	return cmp(lc[a],lc[b],l,mid);
}
    struct greater_ 
    {
      bool
      operator()(const int& __x, const int& __y) const
      { return cmp(__y,__x,1,N); }
    };
priority_queue<int,vector<int>,greater_>q;
int n,m,t1,t2,t3,s,t,dis[100002],pre[100002];
vector<int>g[100002],c[100002];
bool vis[100002];
inline void build(int pos,int l,int r){
	x[pos].lst=r;
	if(l!=r){
		lc[pos]=++cnt;build(cnt,l,mid);
		rc[pos]=++cnt;build(cnt,mid+1,r);
	}
}
int main(){
	pw2[0]=pw1331[0]=1;
	F(i,1,1000000)pw2[i]=(pw2[i-1]<<1)%mod1,pw1331[i]=pw1331[i-1]*1331ll%mod2;
	cin>>n>>m;
	F(i,1,m){
		read(t1);read(t2);read(t3);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
		c[t1].push_back(t3);
		c[t2].push_back(t3);
	}
	cin>>s>>t;
	if(s==t){
		// 
		cout<<0<<endl<<1<<endl<<s;
		return 0;
	}
	build(0,1,N);
	int inf=modify(0,1,N,1);
	F(i,1,n)if(i!=s){
		dis[i]=cpy(inf);
		to[dis[i]]=i;
	}
	to[0]=s;
	q.push(0);
	while(!q.empty()){
		int pos=to[q.top()];
		q.pop();
		if(vis[pos])continue;
		vis[pos]=true;
		if(pos==t)break;
		F(i,0,g[pos].size()-1)if(!vis[g[pos][i]]){
			int temp=solve(dis[pos],c[pos][i]);
			if(cmp(temp,dis[g[pos][i]],1,N)){
				dis[g[pos][i]]=temp;
				to[temp]=g[pos][i];
				pre[g[pos][i]]=pos;
				q.push(temp);
			}
		}
	}
	if(pre[t]){
		write(x[dis[t]].h1,'\n');
		while(t){
			sta[++tot]=t;
			t=pre[t];
		}
		write(tot,'\n');
		UF(i,tot,1)write(sta[i],' ');
	}else puts("-1");
    return 0;
}