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
#define vi vector<int>
#define ull unsigned long long
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
int n,k;
int a[10002],o[10002],x[10002],orz,sto=0;
vector<int>res,qwq,qaq;
bool one=1;
int main() {
	cin>>n>>k;
	F(i,2,n){
		printf("and %d %d\n",1,i);
		fflush(stdout);
		read(a[i]);
		printf("or %d %d\n",1,i);
		fflush(stdout);
		read(o[i]);
		x[i]=o[i]-a[i];
		sto|=a[i];
	}
	puts("or 2 3");
	fflush(stdout);
	read(orz);
	F(i,2,n)res.push_back(i);
	UF(i,29,0)if(!(sto>>i&1)){
		qwq.clear();qaq.clear();
		for(auto j:res){
			if(x[j]>>i&1)qaq.push_back(j);
			else qwq.push_back(j);
		}
		if(qwq.size()){
			
		}else if(orz>>i&1){
			
		}else{
			sto|=(1<<i);
		}
	}
	F(i,1,n)a[i]=(x[i]^sto);
	nth_element(a+1,a+k,a+n+1);
	printf("finish %d\n",a[k]);
	F(i,1,n)cerr<<a[i]<<" ";
	fflush(stdout);
	return 0;
}