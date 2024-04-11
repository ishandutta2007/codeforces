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
#define pdi pair<long double,int>
#define cp complex<double>
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
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
pii mo[100002],mul[100002];
int n,m,k,tp,x,y,cnt,tot,a[100002];
vector<pii >add[100002];
int t[100002];
pdi ak[100002];
bool tag[100002];
inline bool cmp(pii x,pii y){
	return x>y;
}
inline bool cmp2(pdi x,pdi y){
	return x>y;
}
int main() {
	read(n,k,m);
	F(i,1,n)read(a[i]);
	F(i,1,k){
		read(tp,x,y);
		t[i]=tp;
		if(tp==1){
			mo[x]=max(mo[x],make_pair(y,i));
		}else if(tp==2){
			add[x].push_back(make_pair(y,i));
		}else{
			mul[++cnt]=make_pair(y,i);
		}
	}
	F(i,1,n){
		if(mo[i].first>a[i])add[i].push_back(make_pair(mo[i].first-a[i],mo[i].second));
		if(!add[i].empty())sort(add[i].begin(),add[i].end(),cmp);
		long double now=a[i];
		for(pii x:add[i]){
			ak[++tot]=make_pair((now+x.first)/now,x.second);
			now+=x.first;
		}
	}
	F(i,1,cnt)ak[++tot]=make_pair((long double)(mul[i].first),mul[i].second);
	sort(ak+1,ak+tot+1,cmp2);
	write(min(tot,m),'\n');
	F(i,1,min(tot,m))tag[ak[i].second]=1;
	F(i,1,k)if(t[i]==1&&tag[i])write(i,' ');
	F(i,1,k)if(t[i]==2&&tag[i])write(i,' ');
	F(i,1,k)if(t[i]==3&&tag[i])write(i,' ');
	return 0;
}
//iakioi