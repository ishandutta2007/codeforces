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
#define mod 1000000007
ll n,m,x[500002],y[500002],p[500002],c1,c2,pw[500002],orz[500002],sto[500002];
ll f[500002],size[500002],ans,tot,ff[500002],qwq[500002],cnt;
bool vis[500002],v2[500002],ok[500002];
inline int findf(int x) {
	return (f[x]==x)?x:(f[x]=findf(f[x]));
}
inline void merge(int x,int y) {
	if(findf(x)==findf(y))return;
	f[f[x]]=f[y];
}
inline int findff(int x) {
	return (ff[x]==x)?x:(ff[x]=findff(ff[x]));
}
inline void mergeff(int x,int y) {
	ok[ff[y]]|=ok[ff[x]];
	ff[ff[x]]=ff[y];

}
int main() {
	pw[0]=1;
	F(i,1,500000)pw[i]=pw[i-1]*2%mod;
	cin>>n>>m;
	F(i,1,m)f[i]=ff[i]=i;
	F(i,1,n) {
		if(read()==1) {
			p[++c1]=read();
			orz[c1]=i;
		} else {
			++c2;
			sto[c2]=i;
			x[c2]=read();
			y[c2]=read();
		}
	}
	F(i,1,c2) {
		merge(x[i],y[i]);
	}
	F(i,1,m) {
		findf(i);
		size[f[i]]++;
	}
	F(i,1,c1) {
		vis[f[p[i]]]=1;
	}
	ans=1;
	F(i,1,m) {
		if(f[i]==i)ans*=pw[size[i]-1]*(1+vis[i])%mod,tot+=size[i]-1+vis[i];
		ans%=mod;
	}
	cout<<ans<<' '<<tot<<endl;
	/*	F(i,1,c2){
			if(f[x[i]]==f[y[i]]&&findff(x[i])!=findff(y[i])){
				mergeff(x[i],y[i]);
				qwq[++cnt]=sto[i];
			}
		}
		F(i,1,m){
			findff(i);
		}F(i,1,c1){
			if(!v2[ff[p[i]]]){
				v2[ff[p[i]]]=1;
				qwq[++cnt]=orz[i];
			}
		}*/
	orz[c1+1]=INT_MAX;
	sto[c2+1]=INT_MAX;
	ri t1=1,t2=1;
	F(i,1,n) {
		if(orz[t1]<sto[t2]) {
			if(!ok[findff(p[t1])]) {
				write(i,' ');
				ok[ff[p[t1]]]=1;
			}
			t1++;
		} else {
			if(findff(x[t2])!=findff(y[t2])) {
				if(!ok[ff[x[t2]]]||!ok[ff[y[t2]]]) {
					write(i,' ');
					mergeff(x[t2],y[t2]);
				}

			}
			t2++;
		}
	}
	return 0;
}
/*
5 3

1 3
1 2
2 2 3
2 2 1
3 3 1

*/