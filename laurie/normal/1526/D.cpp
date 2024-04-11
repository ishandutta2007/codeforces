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
ll n,res;
char s[114514];
stack<int>sta[200];
int temp[114514];
int c[114514];
string s1,s2,s3,s4,ans;
inline void add(int pos) {
	while(pos<=n) {
		++c[pos];
		pos+=(-pos&pos);
	}
}
inline int query(int pos) {
	int rt=0;
	while(pos) {
		rt+=c[pos];
		pos-=(-pos&pos);
	}
	return rt;
}
inline ll ak() {
	F(i,1,n)c[i]=0;
	ll rt=0;
	UF(i,n,1) {
		rt+=query(temp[i]);
		add(temp[i]);
	}
	return rt;
}
inline ll check(string b) {
	b.insert(0,"#");
	UF(i,n,1) {
		sta[s[i]].push(i);
	}
	F(i,1,n) {
		temp[i]=sta[b[i]].top();
		sta[b[i]].pop();
	}
	return ak();
}
int main() {
	F(fdafdas,1,read()) {
		scanf("%s",s+1);
		n=strlen(s+1);
		res=-1;
		s1.clear();
		s2.clear();
		s3.clear();
		s4.clear();
		F(i,1,n) {
			if(s[i]=='A')s1.push_back('A');
			if(s[i]=='N')s2.push_back('N');
			if(s[i]=='O')s3.push_back('O');
			if(s[i]=='T')s4.push_back('T');
		}
ll sss=check(s1+s2+s3+s4);if(sss>res){res=sss;ans=s1+s2+s3+s4;}
sss=check(s1+s2+s4+s3);if(sss>res){res=sss;ans=s1+s2+s4+s3;}
sss=check(s1+s3+s2+s4);if(sss>res){res=sss;ans=s1+s3+s2+s4;}
sss=check(s1+s3+s4+s2);if(sss>res){res=sss;ans=s1+s3+s4+s2;}
sss=check(s1+s4+s2+s3);if(sss>res){res=sss;ans=s1+s4+s2+s3;}
sss=check(s1+s4+s3+s2);if(sss>res){res=sss;ans=s1+s4+s3+s2;}
sss=check(s2+s1+s3+s4);if(sss>res){res=sss;ans=s2+s1+s3+s4;}
sss=check(s2+s1+s4+s3);if(sss>res){res=sss;ans=s2+s1+s4+s3;}
sss=check(s2+s3+s1+s4);if(sss>res){res=sss;ans=s2+s3+s1+s4;}
sss=check(s2+s3+s4+s1);if(sss>res){res=sss;ans=s2+s3+s4+s1;}
sss=check(s2+s4+s1+s3);if(sss>res){res=sss;ans=s2+s4+s1+s3;}
sss=check(s2+s4+s3+s1);if(sss>res){res=sss;ans=s2+s4+s3+s1;}
sss=check(s3+s1+s2+s4);if(sss>res){res=sss;ans=s3+s1+s2+s4;}
sss=check(s3+s1+s4+s2);if(sss>res){res=sss;ans=s3+s1+s4+s2;}
sss=check(s3+s2+s1+s4);if(sss>res){res=sss;ans=s3+s2+s1+s4;}
sss=check(s3+s2+s4+s1);if(sss>res){res=sss;ans=s3+s2+s4+s1;}
sss=check(s3+s4+s1+s2);if(sss>res){res=sss;ans=s3+s4+s1+s2;}
sss=check(s3+s4+s2+s1);if(sss>res){res=sss;ans=s3+s4+s2+s1;}
sss=check(s4+s1+s2+s3);if(sss>res){res=sss;ans=s4+s1+s2+s3;}
sss=check(s4+s1+s3+s2);if(sss>res){res=sss;ans=s4+s1+s3+s2;}
sss=check(s4+s2+s1+s3);if(sss>res){res=sss;ans=s4+s2+s1+s3;}
sss=check(s4+s2+s3+s1);if(sss>res){res=sss;ans=s4+s2+s3+s1;}
sss=check(s4+s3+s1+s2);if(sss>res){res=sss;ans=s4+s3+s1+s2;}
sss=check(s4+s3+s2+s1);if(sss>res){res=sss;ans=s4+s3+s2+s1;}
		puts(ans.c_str());
	}
	return 0;
}