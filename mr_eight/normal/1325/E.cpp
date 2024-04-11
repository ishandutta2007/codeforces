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
int n,a[100002],b[100002],dis[1000002],ans=114514,l,r,q[1000002],fa[1000002];
vector<int>g[1000002];
bool vis[1000002],flag;
inline bool isp(int x){
	F(i,2,sqrt(x))if(x%i==0)return false;return true;
}
inline void solve(int x){
	memset(dis,0x3f,sizeof(dis));
	dis[x]=0;
	l=r=1;
	q[l]=x;
	while(l<=r){
		int pos=q[l++];
		for(int i:g[pos]){
			if(dis[i]>dis[pos]+1){
				fa[i]=pos;
				dis[i]=dis[pos]+1;
				q[++r]=i;
			}
		}
	}
	F(i,1,n){
		if(a[i]!=fa[b[i]]&&b[i]!=fa[a[i]])ans=min(ans,dis[a[i]]+dis[b[i]]+1);
	}
}
inline pii D(int x){
	int ans[2],cnt=0;ans[0]=ans[1]=0;
	for(int i=2;i*i<=x;++i){
		if(x%i==0){
			bool flag=true;
			x/=i;
			while(x%i==0){
				x/=i;
				flag^=1;
			}
			if(flag)ans[cnt++]=i;
		}
	}
	if(x>1)ans[cnt++]=x;
	return make_pair(ans[0],ans[1]);
}
int main() {
	cin>>n;
	F(i,1,n){
		read(a[i]);
		if(a[i]==(int)sqrt(a[i])*(int)sqrt(a[i])){
			puts("1");
			return 0;
		}
		pii temp=D(a[i]);
		a[i]=temp.first,b[i]=temp.second;
		if(!b[i])b[i]=1;
		if(vis[a[i]*b[i]])flag=true;
		vis[a[i]*b[i]]=true;
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}
	if(flag){
		puts("2");
		return 0;
	}
	F(i,1,1000)if(isp(i))solve(i);
	if(ans==114514)puts("-1");
	else write(ans,'\n');
	return 0;
}
/*
6
10 8 75 6 7 35
*/