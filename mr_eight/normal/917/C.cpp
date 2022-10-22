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
int N,n,x,k,q,S[72],pos[114514],h[1919810],c[2333];
pii p[2233];
struct mat{
	ll a[72][72];
	inline ll* operator[](int x){
		return a[x];
	}
	inline mat operator*(const mat &b)const{
		mat rt;
		memset(&rt,0x3f,sizeof(rt));
		F(i,1,N){
			F(j,1,N){
				F(k,1,N){
					rt.a[i][j]=min(rt.a[i][j],a[i][k]+b.a[k][j]);
				}
			}
		}
		return rt;
	}
}I,trans,pw[30];
struct line{
	ll a[72];
	inline ll& operator[](int x){
		return a[x];
	}
	inline line operator*(const mat &b)const{
		line rt;
		memset(&rt,0x3f,sizeof(rt));
		F(j,1,N){
			F(k,1,N){
				rt.a[j]=min(rt.a[j],a[k]+b.a[k][j]);
			}
		}
		return rt;
	}
}base;
inline line up(line base,int p){
	F(i,0,28){
		if(p>>i&1)base=base*pw[i];
	}
	return base;
}
#define power pw
int main() {
	cin>>x>>k>>n>>q;
	F(i,1,k)read(c[i]);
	h[0]=-2;
	F(i,0,(1<<k)-1){
		h[i]=h[i>>1]+1;
		if(__builtin_popcount(i)==x)S[pos[i]=++N]=i;
	}
	memset(&I,0x3f,sizeof(I));
	F(i,1,N)I[i][i]=0;
	memset(&trans,0x3f,sizeof(trans));
	F(i,1,N){
		if(!(S[i]&1)){
			trans[i][pos[S[i]>>1]]=0;
			continue;
		}else{
			F(j,1,k){
				if(!(S[i]>>j&1))trans[i][pos[(S[i]|(1<<j))>>1]]=c[j];
			}
		}
	}
	power[0]=trans;
	F(i,1,28)power[i]=power[i-1]*power[i-1];
	int now=1,tar=n-x+1;
	memset(&base,0x3f,sizeof(base));
	base[pos[(1<<x)-1]]=0;
	F(i,1,q){
		read(p[i].first);
		read(p[i].second);
	}
	sort(p+1,p+q+1);
	F(i,1,q){
		if(p[i].first<=tar){
		base=up(base,p[i].first-now);
		now=p[i].first;
		F(j,1,N){
			if(S[j]&1)base[j]+=p[i].second;
		}	
		}else{
			base=up(base,tar-now);
			now=tar;
			F(j,1,N){
				if(S[j]>>p[i].first-tar&1)base[j]+=p[i].second;
			}
		}
	}
	base=up(base,tar-now);
	cout<<base[pos[(1<<x)-1]];
	return 0;
}
/*
3 5 1376 25
624848633 701400789 389932422 806187242 525400435
1363 86944863
299 54922570
6 186613997
1354 -677343776
737 -18337983
287 743150728
569 646266939
1372 967237841
1359 751569120
576 -626831768
1353 595156719
286 320323539
570 210503069
1373 -561340306
571 -943899931
291 62156343
283 -713926830
296 899501101
573 150929305
1367 -160018792
563 -230032502
1375 127526763
567 -263522014
281 351817002
581 -118695743
*/