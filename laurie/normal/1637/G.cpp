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
	char asdf[50000002];
	int asdfg;
	#define putchar(x) asdf[++asdfg]=(x)
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
	int ANS=0;
	template<class T>
	inline void write(T x ,char ch) {if(ch=='\n')++ANS;
		write(x);
		putchar(ch);
	}
}
#undef putchar
using namespace fastIO;
int n,t;
int res[1000002];
#define abs(x) ((x)>0?(x):-(x))
inline void orz(int x,int y){
	write(x,' ');write(y,'\n');
	write(x+y,' ');write(abs(y-x),'\n');
	--res[x];--res[y];++res[x+x];++res[y+y];
}
inline void play(int x,int y){
	write(x,' ');write(y,'\n');
	--res[x];--res[y];++res[x+y];++res[abs(y-x)];
}
inline void solve(int n,int k){
	if(n<=2)return;
	if(n==(-n&n))--n;
	int x=1;
	while(x<n)x<<=1;
	x>>=1;
	F(i,1,n-x)play((x-i)*k,(x+i)*k);
	solve(n-x,k+k);
	solve(x-(n-x)-1,k);
}
inline void akioi(){
	printf("%d\n",ANS);ANS=0;
	F(i,1,asdfg)putchar(asdf[i]);
	asdfg=0;
}
inline void orzhq(){
	while(!res[0]){
		bool flag=false;
		for(int i=1;i<t;i<<=1){
			if(res[i]>1){
				play(i,i);
				flag=true;
				break;
			}
		}
		if(!flag){
			for(int i=1;i<t;i<<=1)if(res[i]){
				for(int j=i+i;j<t;j<<=1)if(res[j]){
					orz(i,j);
					flag=true;
					break;
				}
			}
		}
		if(!flag)break;
	}
	for(int i=1;i<t;i<<=1){
		while(res[i])orz(0,i);
	}
	while(res[0])play(0,t);
}
#include<assert.h>
int main() {
	F(iakioi,1,read()){
		read(n);
		if(n<=2){
			puts("-1");
			continue;
		}
		t=1;
		while(t<n)t<<=1;
		F(i,0,t)res[i]=0;
		F(i,1,n)res[i]=1;
		solve(n,1);
		orzhq();
		akioi();
	//	F(i,0,t-1)assert(res[i]==0);
	}
	return 0;
}