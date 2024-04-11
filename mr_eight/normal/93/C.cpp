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
struct S{
	int x,y,z,k;
}sta[10],op[10];
int a[10],ans=6,cnt=1,n;
bool orz[256][256];
inline bool check(int pos){
	F(i,1,cnt)if(orz[n][a[i]]){
		sta[pos+1]=S{25,26,i,n/a[i]};
		return 1;
	}
	F(i,1,cnt){
		F(j,1,cnt)if(orz[n-a[j]][a[i]]){
			sta[pos+1]=S{25,j,i,(n-a[j])/a[i]};
			return 1;
		}
	}
	return 0;
}
inline void dfs(int pos){
	if(check(pos)){
		memcpy(op,sta,sizeof(sta));
		ans=pos+1;
		return;
	}
	if(pos>=ans-2)return;
	int lst;bool tag;
	F(x,1,cnt+1)F(y,1,cnt+1)F(z,1,cnt){
		for(register int k=0;k!=4;++k){
			lst=a[x];
			a[x]=a[y]+(a[z]<<k);
			if(a[x]<=n){
				sta[pos+1]=S{x,y,z,1<<k};
				tag=(x>cnt);
				cnt+=tag;
				dfs(pos+1);
				cnt-=tag;
			}
			a[x]=lst;
		}
	}
}
int main() {
	F(i,1,255)F(j,1,255)orz[i][j]=(i==j||i==(j<<1)||i==(j<<2)||i==(j<<3));
	cin>>n;
	if(n==1){
		puts("0");
		return 0;
	}
	a[1]=1;
	dfs(0);
	write(ans,'\n');
	F(i,1,ans){
		printf("lea e%cx, [e%cx + %d*e%cx]\n",char(op[i].x+'a'-1),char(op[i].y+'a'-1),op[i].k,char(op[i].z+'a'-1));
	}
	return 0;
}