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
int n,m,sq;
int x[200002],y[200002],ak[502][502],tag[200002],sum[200002],lst[200002];
#define max mmax
constexpr int mmax(int x,int y){
	return x>y?x:y;
}
int main() {
	cin>>n>>m;sq=sqrt(m);
	F(i,1,n)read(x[i],y[i]),sum[i]=x[i]+y[i];
	F(i,1,m){
		if(read()==1){
			int pos=read();
			lst[pos]=i;
			if(sum[pos]>sq){
				for(int j=i+x[pos];j<=m;j+=x[pos]){
					++tag[j];
					j+=y[pos];
					if(j<=m)--tag[j];
				}
			}else{
				int now=(i+x[pos])%sum[pos];
				F(iakioi,1,y[pos]){
					++ak[sum[pos]][now];
					++now;
					if(now==sum[pos])now=0;
				}
			}
		}else{
			int pos=read();
			if(sum[pos]>sq){
				for(int j=lst[pos]+x[pos];j<=m;j+=x[pos]){
					--tag[max(i,j)];
					j+=y[pos];
					if(j<=m)++tag[max(i,j)];
				}
			}else{
				int now=(lst[pos]+x[pos])%sum[pos];
				F(iakioi,1,y[pos]){
					--ak[sum[pos]][now];
					++now;
					if(now==sum[pos])now=0;
				}
			}
		}
		tag[i]+=tag[i-1];
		int ans=tag[i];
		F(j,1,sq)ans+=ak[j][i%j];
		write(ans,'\n');
	}
	return 0;
}