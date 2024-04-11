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
#define mod 998244353
int n,X,h,pw[1000002];
inline ll B(vector<int>a,vector<int>b,int d){
	if(d==-1||a.empty()||b.empty())return pw[a.size()+b.size()]-1;
	vector<int>x,y,z,w;
	x.clear(),y.clear(),z.clear(),w.clear();
	for(int i:a){if(i>>d&1)x.push_back(i);else y.push_back(i);}
	for(int i:b){if(i>>d&1)z.push_back(i);else w.push_back(i);}
	if(X>>d&1){
		return (1ll*(B(x,w,d-1)+1)*(B(y,z,d-1)+1)+mod-1)%mod;
	}else{
		return ((B(x,z,d-1)+B(y,w,d-1)-pw[x.size()]-pw[y.size()]-pw[z.size()]-pw[w.size()]+4
		+pw[a.size()]+pw[b.size()]-2
		)%mod+mod)%mod;
	}
}
inline int AA(vector<int>a,int d){
	if(d==-1)return pw[a.size()]-1;
	if(a.empty())return 0;//cerr<<d<<endl;
	vector<int>x,y;
	x.clear();y.clear();
	for(int i:a){if(i>>d&1)x.push_back(i);else y.push_back(i);}
	if(X>>d&1){
		return B(x,y,d-1);
	}else{
		return (AA(x,d-1)+AA(y,d-1))%mod;
	}
}
int main() {
	pw[0]=1;
	F(i,1,1000001)pw[i]=(pw[i-1]<<1)%mod;
	cin>>n>>X;
	vector<int>temp;
	temp.resize(n);
	F(i,0,n-1)read(temp[i]);
	cout<<AA(temp,29);
	return 0;
}
/*
5 998244353
1 2 3 4 5
*/