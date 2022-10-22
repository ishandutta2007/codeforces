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
int n,k,ans[20][1<<20];
bool cnt[20][1<<20];
inline void ins(int x){
	F(i,0,k)cnt[i][x>>i]=true;
}
inline int getmin(int d,int pos,int v){
	if(!cnt[d][pos])return 1000000000;
	UF(j,d-1,0){
		pos=pos<<1|(v>>j&1);
		if(!cnt[j][pos])pos^=1;
	}
	return (pos^v)&(1<<d)-1;
}
inline int getmax(int d,int pos,int v){
	if(!cnt[d][pos])return -1000000000;
	UF(j,d-1,0){
		pos=(pos<<1|(v>>j&1))^1;
		if(!cnt[j][pos])pos^=1;
	}
	return (pos^v)&(1<<d)-1;
}
inline void dfs(int d,int pos){
	if(d==0)return;
	else{
		F(i,0,(1<<d)-1){
			ans[d][i]=min(ans[d][i],(i>>(d-1)&1)?getmin(d-1,pos<<1,i)-getmax(d-1,pos<<1|1,i)+(1<<d-1):getmin(d-1,pos<<1|1,i)-getmax(d-1,pos<<1,i)+(1<<d-1));
		}
		dfs(d-1,pos<<1);dfs(d-1,pos<<1|1);
	}
}
int main(){
	memset(ans,0x3f,sizeof(ans));
	cin>>n>>k;
	F(i,1,n)ins(read());
	dfs(k,0);
	F(i,1,k)F(j,0,(1<<i)-1)ans[i][j]=min(ans[i][j],ans[i-1][j&(1<<(i-1))-1]);
	F(i,0,(1<<k)-1)write(ans[k][i],' ');
    return 0;
}