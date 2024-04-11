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
struct NODE{
	int len,fa,ch[26];
}node[400002];
char s[200002];
int cnt=1,n,lst=1,now,orz;
vector<int>ch[400002];
int qwq[400002],r[400002],sum[30000002],lc[30000002],rc[30000002],dp[400002],L[400002],R[400002];
ll ans;
inline void insert(int c){
	ri p=lst,np=lst=++cnt;
	qwq[np]=++now;
	node[np].len=node[p].len+1;
	for(;p&&!node[p].ch[c];p=node[p].fa){
		node[p].ch[c]=np;
	}if(!p)node[np].fa=1;
	else{
		ri q=node[p].ch[c];
		if(node[q].len==node[p].len+1){
			node[np].fa=q;
		}else{
			ri nq=++cnt;
			node[nq]=node[q];
			node[nq].len=node[p].len+1;
			node[np].fa=node[q].fa=nq;
			for(;p&&node[p].ch[c]==q;p=node[p].fa)node[p].ch[c]=nq;
		}
	}
}
#define mid ((l+r)>>1)
inline void add(int &pos,int l,int r,int q){
	if(!pos)pos=++orz;
	++sum[pos];
	if(l==r)return;
	if(q<=mid)add(lc[pos],l,mid,q);
	else add(rc[pos],mid+1,r,q);
}
inline int query(int pos,int l,int r,int ql,int qr){
	if(!pos||ql>r||qr<l)return 0;
	if(ql<=l&&qr>=r)return sum[pos];
	return query(lc[pos],l,mid,ql,qr)+query(rc[pos],mid+1,r,ql,qr);
}
inline int merge(int x,int y){
	if(!x||!y)return x|y;
	int r=++orz;
	sum[r]=sum[x]+sum[y];
	lc[r]=merge(lc[x],lc[y]);
	rc[r]=merge(rc[x],rc[y]);
	return r;
}
inline void dfs(int pos){
	if(qwq[pos])add(r[pos],1,n,qwq[pos]),R[pos]=qwq[pos];
	for(int i:ch[pos])dfs(i),r[pos]=merge(r[pos],r[i]),R[pos]=R[i];
	L[pos]=R[pos]-node[pos].len+1;
}
inline void solve(int pos,int mmax){ 
	if(mmax){
		if(query(r[mmax],1,n,L[pos]+node[mmax].len-1,R[pos]-1))dp[pos]=dp[mmax]+1,mmax=pos;
		else dp[pos]=dp[mmax];
	}else mmax=pos;
	for(int i:ch[pos])solve(i,mmax);
}
int main() {
//	freopen("level.in","r",stdin);
//	freopen("level.out","w",stdout);
	cin>>n;
	scanf("%s",s);
	F(i,0,n-1)insert(s[i]-'a');
	F(i,2,cnt)ch[node[i].fa].push_back(i);
	dfs(1);
	solve(1,0);
	cout<<max(1,*max_element(dp+1,dp+cnt+1));
	return 0;
}