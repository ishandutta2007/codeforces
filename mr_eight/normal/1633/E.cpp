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
//#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
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
int n,m,pos[100002],u[100002],v[100002],w[100002],p[100002][302],x,cnt,k[100002],fa[52];
ll b[100002];
inline int aabs(int x) {
	return x>0?x:-x;
}
inline bool cmp(int a,int b) {
	if(aabs(w[a]-x)!=aabs(w[b]-x))return aabs(w[a]-x)<aabs(w[b]-x);
	else return w[a]>w[b];
}
inline int findf(int x) {
	return x==fa[x]?x:(fa[x]=findf(fa[x]));
}
inline ll query(int x) {
	int p=upper_bound(pos+1,pos+cnt+1,x)-pos-1;
	return b[p]+1ll*k[p]*(x-pos[p]);
}
int main() {
	cin>>n>>m;
	F(i,1,m)read(u[i],v[i],w[i]);
	F(i,1,m)F(j,i,m)pos[++cnt]=(w[i]+w[j]+1)>>1;
	sort(pos+1,pos+cnt+1);
	F(j,1,m)p[0][j]=j;
	x=0;sort(p[0]+1,p[0]+m+1,cmp);
	F(i,1,n)fa[i]=i;
	#define i 0
	F(qwq,1,m) {
		int pos=p[i][qwq];
		if(findf(u[pos])!=findf(v[pos])) {
			if(w[pos]<=x)++k[i],b[i]+=x-w[pos];
			else --k[i],b[i]+=w[pos]-x;
			fa[fa[u[pos]]]=fa[v[pos]];
		}
	}
	#undef i
	F(i,1,cnt) {
		x=pos[i];
		memcpy(p[i],p[i-1],sizeof(p[0]));
		F(ii,2,m) {
			UF(j,ii,2) {
				if(cmp(p[i][j],p[i][j-1]))swap(p[i][j],p[i][j-1]);
				else break;
			}
		}
		F(iii,1,n)fa[iii]=iii;
		F(qwq,1,m) {
			int pos=p[i][qwq];
			if(findf(u[pos])!=findf(v[pos])) {
				if(w[pos]<=x)++k[i],b[i]+=x-w[pos];
				else --k[i],b[i]+=w[pos]-x;
				fa[fa[u[pos]]]=fa[v[pos]];
			}
		}
	}
	ll ans=0,p=read(),k=read(),a=read(),b=read(),c=read(),lst;
	F(i,1,p)ans^=query(lst=read());
	F(i,1,k-p)ans^=query(lst=(lst*a+b)%c);
	cout<<ans;
	return 0;
}