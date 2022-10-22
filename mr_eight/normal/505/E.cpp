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
int n,m,k,p;
ll a[100002],h[100002],res[100002],now[100002],orz[12],ak[5002];
/*
struct cmp{
	inline bool operator()(int x,int y){
		return now[x]>now[y];
	}
};
priority_queue<int,vector<int>,cmp>q;
*/
bool check(ll x){
	//while(!q.empty())q.pop();
	memset(ak,0,sizeof(ak));
	ll sum=0;
	F(i,1,n)res[i]=max(0ll,(h[i]-x+a[i]*m+p-1)/p),sum+=res[i],now[i]=x;
	if(sum>m*k)return 0;
	//F(i,1,n)if(res[i])q.push(i);
	F(i,1,n){
		ll pos=m+1;
		F(j,1,res[i]){
			int lst=pos;
			pos-=(now[i])/a[i];
			pos=max(pos,1ll);
			++ak[pos];
			now[i]-=(now[i])/a[i]*a[i];
			now[i]+=p;
		}
	}
	int qwq=0;
	F(i,1,m){
		if(ak[i]>k){
			ak[i+1]+=ak[i]-k;
			ak[i]=k;
		}
	}
	if(ak[m+1])return 0;
	UF(i,m,1){
		qwq+=ak[i];
		if(qwq>(m-i+1)*k)return 0;
	}
	return 1;
	/*
	F(i,1,m){
		F(iakioi,1,k){
			if(q.empty())return 1;
			int pos=q.top();
			orz[iakioi]=pos;
			q.pop();
			if(now[pos]-i*a[pos]<0)return 0;
			now[pos]+=p;
			--res[pos];
		}
		F(iakioi,1,k)if(res[iakioi])q.push(orz[i]);
	}
	return q.empty();
	*/
}
int main() {
	cin>>n>>m>>k>>p;
	F(i,1,n)read(h[i],a[i]);
	ll l=*max_element(a+1,a+n+1),r=5e12+1e9;
	while(l<r){
		ll mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l;
	return 0;
}