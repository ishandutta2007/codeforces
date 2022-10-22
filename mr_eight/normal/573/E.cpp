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
#define pii pair<ll,int>
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
#define sq 330
int n,tl[332],tr[332],ql[332],qr[332],in[100002],p[100002],m;
ll a[100002],b[100002],ta[332],tb[332],ans;
bool ban[100002];
int cnt[332],q[100002];
inline long double X(int x,int y) {
	return (b[x]-b[y])/(long double)(a[y]-a[x]);
}
inline void insert(int x,int pos) {
	if(ql[pos]>qr[pos]) {
		q[++qr[pos]]=x;
		return;
	}
	if(ql[pos]==qr[pos]) {
		if(a[x]!=a[q[ql[pos]]])q[++qr[pos]]=x;
		else if(b[x]>b[q[ql[pos]]])q[ql[pos]]=x;
		return;
	}
	if(a[x]==a[q[qr[pos]]]) {
		if(b[x]>b[q[qr[pos]]])--qr[pos];
		else return;
	}
	while(qr[pos]>ql[pos]) {
		if(X(x,q[qr[pos]])<=X(q[qr[pos]],q[qr[pos]-1]))--qr[pos];
		else break;
	}
	q[++qr[pos]]=x;
}
//int xcnt;
inline void build(int pos) {//++xcnt;
	F(i,tl[pos],tr[pos])b[i]+=ta[pos]*a[i]+tb[pos];
	ta[pos]=tb[pos]=0;
	ql[pos]=tl[pos],qr[pos]=ql[pos]-1;
	F(ii,tl[pos],tr[pos]){
		if(!ban[p[ii]])insert(p[ii],pos);
//		if(xcnt==2)cerr<<'k'<<qr[pos]-ql[pos]+1<<' '<<q[1]<<' '<<q[2]<<endl<<X(18,35)<<endl;
	}
}
inline pii query(int pos){
	while(ql[pos]<qr[pos]&&ta[pos]>=X(q[ql[pos]],q[ql[pos]+1]))++ql[pos];
	return make_pair(a[q[ql[pos]]]*ta[pos]+b[q[ql[pos]]]+tb[pos],q[ql[pos]]);
}
inline pii query(){
	pii ans=make_pair(-LLONG_MAX,-INT_MAX);
	F(i,1,m)if(ql[i]<=qr[i])ans=max(ans,query(i));
	return ans;
}
int xxx=0;
inline bool update(pii xx){
	if(xx.first<=0)return 0;
	ans+=xx.first;
	int x=xx.second;
	ban[x]=1;
	F(i,1,in[x]-1)tb[i]+=a[x];
	F(i,in[x]+1,m)++ta[i];
	F(i,tl[in[x]],x-1)b[i]+=a[x];
	F(i,x+1,tr[in[x]])b[i]+=a[i];
	build(in[x]);//if(x==23)cerr<<a[19]<<' '<<b[19]<<endl<<a[18]<<' '<<b[18]<<endl;
	return 1;
}
int main() {
	cin>>n;
	F(i,1,n) {
		read(a[i]);
		b[i]=a[i];
		p[i]=i;
	}
	m=(n+sq-1)/sq;
	F(i,1,m) {
		tr[i]=min(tr[i-1]+sq,n);
		tl[i]=tr[i-1]+1;
		F(j,tl[i],tr[i])in[j]=i;
		sort(p+tl[i],p+tr[i]+1,[](int x,int y) {
			return a[x]<a[y];
		});
		build(i);
	}
	while(update(query()));//cerr<<ans<<endl;
	cout<<ans;
	return 0;
}