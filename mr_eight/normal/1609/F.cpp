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
int n,buf1[2200002],buf2[2200002],buf3[2200002],buf4[2200002],buf5[2200002],buf6[2200002],*bufp1,*bufp2,*bufp5,*bufp6,*bufp3,*bufp4,ak[64],aa[2000002];
ll a[2000002];
int sta1[2000002],sta2[2000002],t1,t2;
int *pre1[64],*pre2[64];
int *p1[64],*p2[64],*S1[64],*S2[64];
int cnt1[64],cnt2[64],ans;
ll res;
#define bp(x) __builtin_popcountll(x)
inline int calc1(int r,int x) {
	int p=lower_bound(p1[x]+1,p1[x]+cnt1[x]+1,r)-p1[x];
	return (S1[x][p]<=r?pre1[x][p]-(p1[x][p]-r):pre1[x][p-1]);
}
inline int calc2(int r,int x) {
#define p1 p2
#define pre1 pre2
#define cnt1 cnt2
	int p=lower_bound(p1[x]+1,p1[x]+cnt1[x]+1,r)-p1[x];
	return (S2[x][p]<=r?pre1[x][p]-(p1[x][p]-r):pre1[x][p-1]);
#undef p1
#undef cnt1
#undef pre1
}
inline int calc1(int l,int r,int x) {
	return calc1(r,x)-calc1(l-1,x);
}
inline int calc2(int l,int r,int x) {
	return calc2(r,x)-calc2(l-1,x);
}
int main() {//freopen("data.txt","r",stdin);
	bufp1=buf1;
	bufp2=buf2;
	bufp4=buf4;
	bufp3=buf3;
	bufp5=buf5;
	bufp6=buf6;
	cin>>n;
	F(i,1,n)read(a[i]),++ak[aa[i]=bp(a[i])];
	F(i,0,62) {
		pre1[i]=bufp1;
		pre2[i]=bufp2;
		p1[i]=bufp3;
		p2[i]=bufp4;
		S1[i]=bufp5;
		S2[i]=bufp6;
		bufp1+=ak[i]+2;
		bufp2+=ak[i]+2;
		bufp3+=ak[i]+2;
		bufp4+=ak[i]+2;
		bufp5+=ak[i]+2;
		bufp6+=ak[i]+2;
		bufp1+=ak[i]+2;
		bufp2+=ak[i]+2;
		bufp3+=ak[i]+2;
		bufp4+=ak[i]+2;
		bufp5+=ak[i]+2;
		bufp6+=ak[i]+2;
	}
	F(i,1,n) {
		int v=aa[i];
		if(a[i]>=a[i-1]) {
			sta2[++t2]=i;
			p2[v][++cnt2[v]]=i;
			S2[v][cnt2[v]]=i;
			pre2[v][cnt2[v]]=pre2[v][cnt2[v]-1]+1;//if(a[i]==9)cerr<<"K"<<ans<<endl;
			while(t1&&a[i]>a[sta1[t1]]) {//if(a[i]==9)cerr<<"K"<<sta1[t1]<<" "<<sta1[t1-1]<<endl;
				ans-=calc2(sta1[t1],aa[sta1[t1]])-calc2(sta1[t1-1],aa[sta1[t1]]);
				S1[aa[sta1[t1]]][cnt1[aa[sta1[t1]]]]=998244353;
				--cnt1[aa[sta1[t1--]]];//if(a[i]==9)cerr<<"K"<<ans<<endl;
			}
			int lst=sta1[t1];
			sta1[++t1]=i;
			p1[v][++cnt1[v]]=i;
			S1[v][cnt1[v]]=lst+1;
			pre1[aa[i]][cnt1[v]]=pre1[aa[i]][cnt1[v]-1]+i-lst;
			ans+=calc2(i,v)-calc2(lst,v);
		} else {
			sta1[++t1]=i;
			p1[v][++cnt1[v]]=i;
			S1[v][cnt1[v]]=i;
			pre1[v][cnt1[v]]=pre1[v][cnt1[v]-1]+1;
			while(t2&&a[i]<a[sta2[t2]]) {
				ans-=calc1(sta2[t2],aa[sta2[t2]])-calc1(sta2[t2-1],aa[sta2[t2]]);
				//cerr<<sta2[t2]<<"j"<<aa[sta2[t2]]<<'j'<<ans<<' '<<calc1(sta2[t2]-1,aa[sta2[t2]])<<endl;
				S2[aa[sta2[t2]]][cnt2[aa[sta2[t2]]]]=998244353;
				--cnt2[aa[sta2[t2--]]];
			}
			int lst=sta2[t2];
			sta2[++t2]=i;
			p2[v][++cnt2[v]]=i;
			S2[v][cnt2[v]]=lst+1;
			pre2[aa[i]][cnt2[v]]=pre2[aa[i]][cnt2[v]-1]+i-lst;
			ans+=calc1(i,v)-calc1(lst,v);
		}
		res+=ans;//cerr<<ans<<endl;
	}
	cout<<res;
	return 0;
}