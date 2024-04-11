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
set<int>res,del;
int n,a[100002],now;
inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
inline int nxt(int pos){
	if(del.empty())return 0;
	auto temp=del.lower_bound(pos);
	if(temp!=del.end()){
		return *temp;
	}
	return *del.begin();
}
vector<int>ans;
int main() {
	F(zhqakioi,1,read()){
		read(n);res.clear();del.clear();ans.clear();
		F(i,1,n)read(a[i]);
		F(i,1,n)res.insert(i);
		F(i,2,n)if(gcd(a[i],a[i-1])==1)del.insert(i);
		if(gcd(a[1],a[n])==1)del.insert(1);
		now=2;
		while(!res.empty()&&!del.empty()){
			ri pos=nxt(now);
			res.erase(pos);
			del.erase(pos);
			ans.push_back(pos);
			if(res.empty())break;
			auto temp=res.upper_bound(pos);
			if(temp==res.end())temp=res.begin();
			ri mo=*temp;
			if(temp==res.begin()){
				temp=res.end();
				--temp;
			}else{
				--temp;
			}if(gcd(a[mo],a[*temp])==1){
				del.insert(mo);
			}else{
				if(del.count(mo))del.erase(mo);
			}
			now=mo+1;
		}
		write(ans.size(),' ');
		F(i,0,ans.size()-1)write(ans[i],' ');
		putchar('\n');
	}
	return 0;
}