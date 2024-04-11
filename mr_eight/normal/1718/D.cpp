//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
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
#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
using namespace std;
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
	inline void write(T x) {
		if(x==0){
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		int cnt = 0 ;
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
int n,q,p[300002],lc[300002],rc[300002],sta[300002],fa[300002],cnt,a[300002],u[300002],d[300002],k,s[300002];
pii r[300002];
int R[300002];
inline void dfs(int pos){
	u[pos]=u[fa[pos]];
	if(a[pos])u[pos]=min(u[pos],a[pos]);
	if(lc[pos])dfs(lc[pos]),d[pos]=max(d[pos],d[lc[pos]]);
	if(rc[pos])dfs(rc[pos]),d[pos]=max(d[pos],d[rc[pos]]);
	if(a[pos])d[pos]=max(d[pos],a[pos]);
}
int mmin[1200002],sum[1200002];
#define mid ((l+r)>>1)
inline void pushup(int pos){
	mmin[pos]=min(mmin[pos<<1],mmin[pos<<1|1]+sum[pos<<1]);
	sum[pos]=sum[pos<<1]+sum[pos<<1|1];
}
inline void add(int pos,int l,int r,int q,int v){//if(pos==1)cerr<<"add "<<q<<" "<<v<<endl;
	if(l==r){
		sum[pos]+=v;
		mmin[pos]+=v;
		return;
	}
	if(q<=mid)add(pos<<1,l,mid,q,v);
	else add(pos<<1|1,mid+1,r,q,v);
	pushup(pos);
}
inline int query(int pos,int l,int r){
	if(l==r)return l;
	if(mmin[pos<<1]<=sum[pos<<1]+mmin[pos<<1|1])return query(pos<<1,l,mid);
	return query(pos<<1|1,mid+1,r);
}
int main() {
	a[0]=u[0]=1000002;
	F(dasf,1,read()){
		read(n,q);
		F(i,1,n)read(p[i]),lc[i]=rc[i]=sta[i]=fa[i]=u[i]=d[i]=cnt=0;
		F(i,1,n<<2)mmin[i]=sum[i]=0;
		F(i,1,n){
			bool flag=false;
			while(cnt&&p[i]>p[sta[cnt]]){
				--cnt;flag=true;
			}
			if(flag)lc[i]=sta[cnt+1];
			if(cnt)rc[sta[cnt]]=i;
			sta[++cnt]=i;
		}
		F(i,1,n)fa[lc[i]]=fa[rc[i]]=i;
		F(i,1,n)read(a[i]);
		dfs(sta[1]);
		bool flag=true;
		F(i,1,n)if(a[i]&&(a[i]>u[i]||a[i]<d[i]))flag=false;
		k=0;
		F(i,1,n){
			if(!a[i]){
				r[++k]={d[i],u[i]};
				if(d[i]>u[i])flag=false;
			}
		}
		if(!flag){
			F(orz,1,k+q-1)read();
			F(orz,1,q)puts("NO");
			continue;
		}
		sort(r+1,r+k+1);
		F(i,1,n)R[i]=r[i].second;
		sort(R+1,R+k+1);
		F(i,1,k-1)read(s[i]);
		sort(s+1,s+k);
		int now=k-1;
		int qwq=0,qaq=INT_MAX;
		UF(i,k,1){
			while(now&&s[now]>=r[i].first){
				if(s[now]<=R[k])add(1,1,k,lower_bound(R+1,R+k+1,s[now--])-R,1);
				else --now;
			}
			add(1,1,k,lower_bound(R+1,R+k+1,r[i].second)-R,-1);
			if(mmin[1]<0){
				if(mmin[1]<-1){
					flag=false;
					break;
				}
				qwq=max(qwq,r[i].first);
				qaq=min(qaq,R[query(1,1,k)]);
			}
		}
		if(!flag){
			F(orz,1,q)read();
			F(orz,1,q)puts("NO");
			continue;
		}
		F(i,1,q){
			int v=read();
			if(v>=qwq&&v<=qaq)puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
/*
1
10 11
9 5 6 3 8 10 2 1 4 7 
900 500 600 300 0 1000 200 0 400 700 
1030 
50
150
250
350
450
550
650
750
850
950
1050
*/