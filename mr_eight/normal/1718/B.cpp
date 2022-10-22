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
ll n,f[50],c[102],cnt[102];
int main() {
	f[0]=f[1]=1;
	F(i,1,50)f[i]=f[i-1]+f[i-2];
	F(dasf,1,read()){
		memset(c,0,sizeof(c));memset(cnt,0,sizeof(cnt));
		read(n);
		ll sum=0;
		F(i,1,n)read(c[i]),sum+=c[i];
		int len=0;
		while(sum>0)sum-=f[len++];
		--len;
		if(sum!=0)puts("NO");
		else{
			bool flag=false;
			int lst=0;
			UF(i,len,0){
				int pos=max_element(c+1,c+n+1)-c;
				if(pos==lst){
					pos=0;
					F(i,1,n)if(i!=lst&&c[i]>c[pos])pos=i;
				}
				if(c[pos]>=f[i])c[pos]-=f[i],++cnt[pos];
				else{
					puts("NO");flag=true;
					break;
				}lst=pos;
			}if(!flag){
				len=(len+2)>>1;
				F(i,1,n)if(cnt[i]>len){
					puts("NO");flag=true;
					break;
				}
				if(!flag)puts("YES");
			}
		}
	}
	return 0;
}