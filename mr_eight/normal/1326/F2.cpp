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
struct setpoly;//
inline setpoly operator&(setpoly x,setpoly y);//
inline setpoly operator|(setpoly x,setpoly y);//
inline setpoly operator^(setpoly x,setpoly y);//
inline setpoly operator*(setpoly x,setpoly y);//
struct setpoly {
	int n,N;
	vector<ll>a;
	setpoly() {
		n=0;
		a.clear();
		a.push_back(0);
	}
	setpoly(int n_) {
		n=n_;
		N=(1<<n);
		a.resize(N);
	}
	inline void resize(int n_) {
		n=n_;
		N=(1<<n);
		a.resize(N);
	}
	inline long long& operator[](int pos) {
		return a[pos];
	}
	inline vector<long long>::iterator begin() {
		return a.begin();
	}
	inline vector<long long>::iterator end() {
		return a.end();
	}
	inline void FWT_and() {
		for(int i=1; i<N; i<<=1) {
			for(int j=i; j<N; j=(j+1)|i) {
				a[j^i]+=a[j];
			}
		}
	}
	inline void IFWT_and() {
		for(int i=1; i<N; i<<=1) {
			for(int j=i; j<N; j=(j+1)|i) {
				a[j^i]-=a[j];
			}
		}
	}
	inline void FWT_or() {
		for(int i=1; i<N; i<<=1) {
			for(int j=i; j<N; j=(j+1)|i) {
				a[j]+=a[j^i];
			}
		}
	}
	inline void IFWT_or() {
		for(int i=1; i<N; i<<=1) {
			for(int j=i; j<N; j=(j+1)|i) {
				a[j]-=a[j^i];
			}
		}
	}
	// exp
	inline setpoly exp() {
		setpoly temp,lst;
		lst.resize(0);
		lst.a[0]=1;
		for(int i=0; i<n; ++i) {
			temp.resize(i);
			for(int j=(1<<i); j<(2<<i); ++j)temp[j^(1<<i)]=a[j];
			temp=temp*lst;
			++lst.n,lst.N<<=1;
			lst.a.insert(lst.end(),temp.begin(),temp.end());
		}
		return lst;
	}
}f,S[20];
inline setpoly operator&(setpoly x,setpoly y) {
	x.FWT_and();
	y.FWT_and();
	for(int i=0; i<x.N; ++i)x.a[i]=1ll*x.a[i]*y.a[i];
	x.IFWT_and();
	return x;
}
inline setpoly operator|(setpoly x,setpoly y) {
	x.FWT_or();
	y.FWT_or();
	for(int i=0; i<x.N; ++i)x.a[i]=1ll*x.a[i]*y.a[i];
	x.IFWT_or();
	return x;
}
inline setpoly operator*(setpoly x,setpoly y) {
	setpoly a[x.n+1],b[x.n+1],res[x.n+1];
	for(int i=0; i<=x.n; ++i)a[i].resize(x.n),b[i].resize(x.n),res[i].resize(x.n);
	for(int i=0; i<x.N; ++i)a[__builtin_popcount(i)].a[i]=x.a[i],b[__builtin_popcount(i)].a[i]=y.a[i];
	for(int i=0; i<=x.n; ++i)a[i].FWT_or(),b[i].FWT_or();
	for(int i=0; i<=x.n; ++i) {
		for(int j=0; j<=x.n-i; ++j) {
			for(int k=0; k<x.N; ++k)res[i+j].a[k]=res[i+j].a[k]+1ll*a[i].a[k]*b[j].a[k];
		}
	}
	for(int i=0; i<=x.n; ++i)res[i].IFWT_or();
	for(int i=0; i<x.N; ++i)x.a[i]=res[__builtin_popcount(i)].a[i];
	return x;
}
bool ed[20][20];
inline bool orzhq() {
	char ch=getchar();
	while(ch!='0'&&ch!='1')ch=getchar();
	return ch-'0';
}
int n,N,sta[20],cnt,tot;
ll dp[1<<18][20],V,l[20],r[20];
inline void play(int now,int S){
	if(now==cnt){
		f[S]+=V;//cerr<<S<<" "<<V<<endl;
		return;
	}
	F(i,1,tot)if(l[i]<=r[i]){
		S<<=1;
		F(j,1,sta[l[i]]-1)S=S<<1|1;
		++l[i];
		play(now+1,S);
		S>>=sta[--l[i]];
	}
}
inline void dfs(int now,int lst){//cerr<<now<<" "<<lst<<endl;
	if(now==n){
		ll res=0;
		F(i,0,N-1){
			ll temp=1;
			F(j,1,cnt){
				temp*=S[sta[j]][i];
			}
			if((n^__builtin_popcount(i))&1)res-=temp;
			else res+=temp;
		}//F(i,1,cnt)cerr<<sta[i]<<" ";cerr<<endl;cerr<<res<<endl;
		V=res;
		tot=0;
		int lst=1;
		sta[cnt+1]=-114514;
		F(i,2,cnt+1){
			if(sta[i]!=sta[i-1]){
				l[++tot]=lst;
				r[tot]=i-1;
				lst=i;
			}
		}
		play(0,0);
	}else{
		++cnt;
		F(i,1,min(lst,n-now)){
			sta[cnt]=i;
			dfs(now+i,i);
		}
		--cnt;
	}
}
int main() {
	cin>>n;f.resize(n-1);F(i,1,n)S[i].resize(n);
	N=1<<n;
	F(i,0,n-1)F(j,0,n-1)ed[i][j]=orzhq();
	F(i,0,n-1)dp[1<<i][i]=1;
	F(i,3,N-1)if(__builtin_popcount(i)>1)F(j,0,n-1)if(i>>j&1)F(k,0,n-1)if((i>>k&1)&&ed[k][j]) {
		dp[i][j]+=dp[i^(1<<j)][k];
	}
	F(i,1,N-1)F(j,0,n-1)if(i>>j&1)S[__builtin_popcount(i)][i]+=dp[i][j];
	F(i,1,n)S[i].FWT_or();
	//F(i,1,N)F(j,0,n-1)if(i>>j&1)if(dp[i][j])cerr<<i<<" "<<j+1<<" "<<dp[i][j]<<endl;
	dfs(0,114514);
	f.IFWT_and();
	for(auto i:f)write(i,' ');
	return 0;
}