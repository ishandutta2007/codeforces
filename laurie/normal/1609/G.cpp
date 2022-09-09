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
#define N 102
#define M 100002
int n,m,q,cnt,l[M],r[M],in[M],tl[M];
ll a[N],b[M],tag1[M],tag2[M],sumb;
#define sq 300
inline void remake(int x){
	F(i,l[x],r[x])b[i]+=(i-l[x])*tag1[x]+tag2[x];
	tag1[x]=tag2[x]=0;
}
inline ll v(int x){
	return b[x]+(x-tl[x])*tag1[in[x]]+tag2[in[x]];
}
inline void modify(int pos,ll d){
	sumb+=d*(m-pos+1)*(m-pos+2)/2;
	int x=in[pos];
	remake(x);
	F(i,pos,r[x])b[i]+=d*(i-pos+1);
	F(i,x+1,cnt){
		tag1[i]+=d;
		tag2[i]+=d*(l[i]-pos+1);//cerr<<cnt<<' '<<i<<"k"<<tag1[i]<<" "<<tag2[i]<<endl;
	}
}
inline ll query(){
	ll rt=sumb;
	int now=1;
	F(i,1,n){
		int lst=now-1;
		for(int j=(1<<16);j;j>>=1)if(now+j<=m&&a[i]+v(now+j)<a[i+1]+v(now+j-1)){
			now+=j;
		}
		rt+=a[i]*(now-lst)+v(now);
	}
	return rt-v(m);
}
int main(){
	cin>>n>>m>>q;
	F(i,1,n)read(a[i]);
	F(i,1,m)read(b[i]),sumb+=b[i];
	a[n+1]=b[m+1]=2e18;
	cnt=(m+sq-1)/sq;
	F(i,1,cnt){
		l[i]=r[i-1]+1;
		r[i]=r[i-1]+sq;
		r[i]=min(r[i],m);
		F(j,l[i],r[i])in[j]=i,tl[j]=l[i];
	}
	F(i,1,q){
		if(read()==1){
			int pos=read();
			ll d=read();
			F(j,1,pos)a[n-pos+j]+=d*j;
		}else{
			int pos=read();
			ll d=read();
			modify(m-pos+1,d);
		}
	//	F(j,1,n)cerr<<a[j]<<" ";cerr<<endl;
	//	F(j,1,m)cerr<<v(j)<<' ';cerr<<endl;
		write(query(),'\n');
	}
    return 0;
}