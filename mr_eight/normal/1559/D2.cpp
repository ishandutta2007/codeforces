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
struct bcj{
	int fa[100002];
	bcj(){
		F(i,1,100000)fa[i]=i;
	}
	inline int findf(int x){
		return fa[x]==x?x:(fa[x]=findf(fa[x]));
	}
	inline void merge(int x,int y){
		if(findf(x)!=findf(y))fa[fa[x]]=fa[y];
	}
}A,B;
int n,m1,m2;
vector<int>X,Y;
vector<pii >ans;
int main() {
	cin>>n>>m1>>m2;
	F(i,1,m1)A.merge(read(),read());
	F(i,1,m2)B.merge(read(),read());
	F(i,2,n)if(A.findf(i)!=A.findf(1)&&B.findf(i)!=B.findf(1))A.merge(1,i),B.merge(1,i),ans.push_back(make_pair(1,i));
	F(i,2,n){
		if(A.findf(i)==i&&A.findf(1)!=i)X.push_back(i);
		if(B.findf(i)==i&&B.findf(1)!=i)Y.push_back(i);
	}
	write(ans.size()+min(X.size(),Y.size()),'\n');
	F(i,0,(int)min(X.size(),Y.size())-1)write(X[i],' '),write(Y[i],'\n');
	for(pii a:ans)write(a.first,' '),write(a.second,'\n');
	return 0;
}