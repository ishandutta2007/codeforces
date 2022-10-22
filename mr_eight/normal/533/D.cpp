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
#define int long long
#define MAXN 100005
int n,x[MAXN],d[MAXN],sta[MAXN],cnt,f[MAXN],g[MAXN],orz[MAXN];
int v[MAXN];
bool ok1[MAXN],ok2[MAXN];
long double ans;
inline void insert(int pos,int vv){
	while(pos<=n){
		v[pos]=max(v[pos],vv);
		pos+=(-pos&pos);
	}
}
inline int query(int pos){
	int rt=-INT_MAX;
	while(pos){
		rt=max(rt,v[pos]);
		pos-=(-pos&pos);
	}return rt;
}
signed main() {
	memset(v,-0x3f,sizeof(v));
	cin>>n;
	F(i,0,n+1)read(x[i]);
	F(i,1,n)read(d[i]);
	d[0]=d[n+1]=INT_MAX;
	F(i,1,n){
		while(cnt&&2*d[sta[cnt]]<x[i]-x[f[sta[cnt]]])--cnt;
		f[i]=sta[cnt];
		sta[++cnt]=i;
	}
	sta[0]=n+1;
	cnt=0;
	g[n+1]=n+1;
	UF(i,n,1){
		while(cnt&&2*d[sta[cnt]]<x[g[sta[cnt]]]-x[i])--cnt;
		g[i]=sta[cnt];
		sta[++cnt]=i;
	}
	F(i,1,n){
		if(2*d[i]>=x[g[i]]-x[f[i]]){
			puts("0");
			return 0;
		}
	}
	ans=x[n+1]/2.0L;
	F(i,1,n){
		ans=min(ans,(x[g[i]]-x[f[i]])/2.0L);
	}
	F(i,1,n){
		if(2*d[i]>x[g[i]]-x[i]){
			ok2[i]=1;
		}
		if(2*d[i]>x[i]-x[f[i]]){
			ok1[i]=1;
		}
	}
	
	// i<j   2*(d[i]+d[j])>=x[g[j]]-x[f[i]]
	// 2*d[j]-x[g[j]]>=-x[f[i]]-2*d[i]
	F(i,1,n)orz[i]=-x[f[i]]-2*d[i];
	sort(orz+1,orz+n+1);
	F(i,1,n){
		if(ok2[i]){
			ans=min(ans,(x[i]-query(upper_bound(orz+1,orz+n+1,2*d[i]-x[g[i]])-orz-1))/2.0L);
		}if(ok1[i]){
			insert(lower_bound(orz+1,orz+n+1,-x[f[i]]-2*d[i])-orz,x[i]);
		}
	}
	F(i,1,n){
		if(2*d[i]>(x[g[i]]-x[i]))ans=min(ans,x[i]/2.0L);
		if(2*d[i]>(x[i]-x[f[i]]))ans=min(ans,(x[n+1]-x[i])/2.0L);
	}
	cout<<fixed<<setprecision(6)<<ans;
	return 0;
}