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
//#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
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
namespace T{
	int mmin[500002],num[500002],tag[500002],upd[500002];
	ll sum[500002];
	#define mid ((l+r)>>1)
	inline void pushup(int x){
		if(mmin[x<<1]<mmin[x<<1|1])mmin[x]=mmin[x<<1],num[x]=num[x<<1];
		else if(mmin[x<<1]>mmin[x<<1|1])mmin[x]=mmin[x<<1|1],num[x]=num[x<<1|1];
		else mmin[x]=mmin[x<<1],num[x]=num[x<<1]+num[x<<1|1];
	}
	inline void pushdown(int x){
		if(tag[x]){
			mmin[x<<1]+=tag[x];
			mmin[x<<1|1]+=tag[x];
			tag[x<<1]+=tag[x];
			tag[x<<1|1]+=tag[x];
			tag[x]=0;
		}
		if(upd[x]){
			if(mmin[x]==mmin[x<<1]){
				upd[x<<1]+=upd[x];
				sum[x<<1]+=1ll*upd[x]*num[x<<1];
			}
			if(mmin[x]==mmin[x<<1|1]){
				upd[x<<1|1]+=upd[x];
				sum[x<<1|1]+=1ll*upd[x]*num[x<<1|1];
			}
			upd[x]=0;
		}
	}
	inline void build(int pos,int l,int r){
		num[pos]=r-l+1;
		mmin[pos]=1;
		if(l!=r)build(pos<<1,l,mid),build(pos<<1|1,mid+1,r);
	}
	inline void add(int pos,int l,int r,int ql,int qr,int v){
		if(ql<=l&&qr>=r){
			mmin[pos]+=v;
			tag[pos]+=v;
			return;
		}
		pushdown(pos);
		if(ql<=mid)add(pos<<1,l,mid,ql,qr,v);
		if(qr>mid)add(pos<<1|1,mid+1,r,ql,qr,v);
		pushup(pos);
	}
	inline void update(){
		if(mmin[1]==0){
			sum[1]+=num[1];
			++upd[1];
		}
	}
	inline ll query(int pos,int l,int r,int ql,int qr){
		if(ql<=l&&qr>=r)return sum[pos];
		pushdown(pos);
		if(ql<=mid&&qr>mid)return query(pos<<1,l,mid,ql,qr)+query(pos<<1|1,mid+1,r,ql,qr);
		if(ql<=mid)return query(pos<<1,l,mid,ql,qr);
		return query(pos<<1|1,mid+1,r,ql,qr);
	}
}
using namespace T;
int n,m,a[120002],orz[120002],sto[120002],qwq,qaq;
ll ans[120002];
vector<pii >q[120002];
int main() {
	cin>>n;
	build(1,1,n);
	F(i,1,n)read(a[i]);
	cin>>m;
	F(i,1,m){
		int l=read(),r=read();
		q[r].push_back(make_pair(l,i));
	}
	F(i,1,n){
		while(qwq&&a[i]>a[orz[qwq]]){
			add(1,1,n,orz[qwq-1]+1,orz[qwq],a[i]-a[orz[qwq]]);
			--qwq;
		}
		while(qaq&&a[i]<a[sto[qaq]]){
			add(1,1,n,sto[qaq-1]+1,sto[qaq],a[sto[qaq]]-a[i]);
			--qaq;
		}
		orz[++qwq]=i;
		sto[++qaq]=i;
		if(i!=1)add(1,1,n,1,i-1,-1);
		add(1,1,n,i,i,-1);
		update();
		for(pii x:q[i]){
			ans[x.second]=query(1,1,n,x.first,i);
		}
	}
	F(i,1,m)write(ans[i],'\n');
	return 0;
}