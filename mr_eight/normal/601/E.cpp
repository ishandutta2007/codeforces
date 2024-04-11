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
int n,K,t=1,l[15002],r[15002],v[15002],w[15002],m,qt[15002];
vector<int>add[100002];
#define mid ((l+r)>>1)
inline void ins(int pos,int l,int r,int ql,int qr,int p){
	if(ql<=l&&qr>=r){
		add[pos].push_back(p);
		return;
	}
	if(ql>r||qr<l)return;
	ins(pos<<1,l,mid,ql,qr,p);
	ins(pos<<1|1,mid+1,r,ql,qr,p);
}
#define ak 10000019
#define mod 1000000007
struct S{
	int dp[1002];
	inline void add(int v,int w){
		UF(i,K-w,0)dp[i+w]=max(dp[i+w],dp[i]+v);
	}
	inline int v(){
		ll temp=1,rt=0;
		F(i,1,K){
			rt+=temp*dp[i]%mod;
			temp=temp*ak%mod;
		}
		return rt%mod;
	}
}O;
inline void dfs(int pos,int l,int r,S now){
	for(int i:add[pos])now.add(v[i],w[i]);
	if(l==r)F(iakioi,1,qt[l]){
		int asdf=now.v();
		write(asdf,'\n');
	}
	else{
		dfs(pos<<1,l,mid,now);
		dfs(pos<<1|1,mid+1,r,now);
	}
}
int main(){
	cin>>n>>K;
	F(i,1,n)read(v[i]),read(w[i]);
	F(i,1,n)l[i]=1;
	cin>>m;
	bool flag=false;
	F(i,1,m){
		int tp=read();
		if(tp==3){
			if(!flag)++t;
			++qt[t];
			flag=true;
		}
		else if(tp==2){
			r[read()]=t;
			flag=false;
		}else{
			++n;
			read(v[n]);
			read(w[n]);
			l[n]=t+1;
			flag=false;
		}
	}
	F(i,1,n)ins(1,1,t,l[i],(r[i]?r[i]:t),i);
	dfs(1,1,t,O);
    return 0;
}