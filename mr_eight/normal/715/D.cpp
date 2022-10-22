#include<bits/stdc++.h>

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
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
#define int long long
#define y1 fuck_ccf
#define pii pair<int,int>
#define mp make_pair
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
const int N=2e6+5;
const int M=70;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
set<pair< pii,pii > > S;
void add(int x1,int y1,int x2,int y2) {
	if (x1<1 || y1<1 || x2<1 || y2<1) return;
	if (x1+y1>x2+y2) swap(x1,x2),swap(y1,y2);
	S.insert(mp(mp(x1,y1),mp(x2,y2)));
}
int X,Y;
void change(int k) {
	add(X-2,X+3,X-1,X+3);
	add(X-1,X+1,X,X+1);
	add(X,X+2,X,X+3);
	add(X,X+4,X+1,X+4);
	add(X+1,X+2,X+1,X+3);
	add(X+2,X,X+3,X);
	add(X+2,X+1,X+3,X+1);
	add(X+3,X-2,X+3,X-1);
	add(X+4,X,X+4,X+1);
	if(k%3==0) add(X-1,X+2,X,X+2);
	if(k%3!=2) add(X+2,X-1,X+2,X);
	if(k<3) add(X+1,X-1,X+1,X);
	X+=2;
	Y+=2;
}
int T;
int a[N],t,sz;
signed main() {
	cin>>T;
	add(1,2,2,2);
	add(2,1,2,2);
	X=Y=2;
	while (T) a[++t]=T%6,T/=6;
	for (int i=t; i>=1; i--) change(a[i]);
	cout<<X<<" "<<Y<<endl;
	for (pair< pii,pii > p:S) if (p.first.first>X || p.second.second>X || p.first.second>X || p.second.first>X) sz++;
	cout<<S.size()-sz<<endl;
	for (pair< pii,pii > p:S) {
		if (p.first.first>X || p.second.second>X || p.first.second>X || p.second.first>X) continue;
		cout<<p.first.first<<" "<<p.first.second<<" "<<p.second.first<<" "<<p.second.second<<"\n";
	}

}