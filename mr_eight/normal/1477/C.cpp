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
#define pii pair<long double,long double>
#define cp complex<double>
//#pra gma G CC opti mize(3)
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
const long double Pi=acos(-1);
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
ll n;
#define first x
struct qwq{
	long double x,y,pos;
};
qwq a[5002];
bool cmp(qwq x,qwq y){
	return x.x<y.x||(x.x==y.x&&x.y<y.y);
}
vector<int> sta;
struct vec{
	long double x,y;
};
inline bool fuck(vec x,vec y){
	return x.x*y.y-x.y*y.x>1e-9;
}
inline bool check(int aa,int b,int c){
	return fuck(vec{-a[b].y+a[aa].y,a[b].x-a[aa].x},vec{a[c].x-a[b].x,a[c].y-a[b].y});
}
int main() {
	cin>>n;
	F(i,1,n)cin>>a[i].x>>a[i].y,a[i].pos=i;
	sort(a+1,a+n+1,cmp);
	sta.push_back(1),sta.push_back(2);
	F(ii,3,n){
		if(check(ii,sta[0],sta[1])){
			sta.insert(sta.begin(),ii);continue;
		}
		if(ii>3)if(check(sta[0],ii,sta[1])&&check(ii,sta[1],sta[2])){
			sta.insert(sta.begin()+1,ii);
			continue;
		}
		if(check(ii,sta.back(),sta[sta.size()-2])){
			sta.push_back(ii);continue;
		}if(ii>3)if(check(sta.back(),ii,sta[sta.size()-2])&&check(ii,sta[sta.size()-2],sta[sta.size()-3])){
			sta.insert(sta.begin()+sta.size()-1,ii);continue;
		}
		F(i,1,sta.size()-3){
			if(check(sta[i-1],sta[i],ii)&&check(sta[i],ii,sta[i+1])&&check(ii,sta[i+1],sta[i+2])){
				sta.insert(sta.begin()+i+1,ii);break;
			}
		}if(sta.size()<ii){
			puts("-1");while(clock()<990);return 0;
		}
	}F(i,0,sta.size()-1)cout<<a[sta[i]].pos<<' ';
	return 0;
}