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
int p1,p0,n,now,a,b,c,d;
bool tp[10002],ans[10002];
inline bool check(int x,int y,int z){
	printf("? %d %d %d\n",x,y,z);
	fflush(stdout);
	return read();
}
int main() {
	F(iakioi,1,read()){
		memset(tp,0,sizeof(tp));
		p1=p0=0;
		read(n);
		for(int i=1;i<=n;i+=3){
			tp[i]=check(i,i+1,i+2);
			if(tp[i]==0)p0=i;
			else p1=i;
			if(p0&&p1){
				now=i;
				break;
			}
		}
		if(!check(p0,p0+1,p1)&&!check(p0,p0+1,p1+1)){
			a=p0,b=p0+1;
		}else if(!check(p0,p0+2,p1)&&!check(p0,p0+2,p1+1)){
			a=p0,b=p0+2;
		}else{
			a=p0+1,b=p0+2;
		}
		if(check(a,p1,p1+1)){
			c=p1,d=p1+1;
		}else if(check(a,p1,p1+2)){
			c=p1,d=p1+2;
		}else{
			c=p1+1,d=p1+2;
		}
		ans[a]=ans[b]=0;
		ans[c]=ans[d]=1;
		ans[p0^p0+1^p0+2^a^b]=check(a,p0^p0+1^p0+2^a^b,c);
		ans[p1^p1+1^p1+2^c^d]=check(a,p1^p1+1^p1+2^c^d,c);
		for(int i=1;i<=now;i+=3)if(i!=p0&&i!=p1){
			if(tp[i]){
				if(check(i,i+1,a)){
					ans[i]=ans[i+1]=1;
					ans[i+2]=check(i+2,a,c);
				}else{
					ans[i]=check(i,a,c);
					ans[i+1]=!ans[i];
					ans[i+2]=1;
				}
			}else{
				if(!check(i,i+1,c)){
					ans[i]=ans[i+1]=0;
					ans[i+2]=check(i+2,a,c);
				}else{
					ans[i]=check(i,a,c);
					ans[i+1]=!ans[i];
					ans[i+2]=0;
				}
			}
		}
		F(i,now+3,n)ans[i]=check(i,a,c);
		putchar('!');putchar(' ');
		int tot=0;
		F(i,1,n)if(!ans[i])++tot;
		write(tot,' ');
		F(i,1,n)if(!ans[i])write(i,' ');
		puts("");
		fflush(stdout);
	}
	return 0;
}