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
#define int long long
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
#define sum sum1
int a[200002],p[200002],n,q,pre[200002],suf[200002],sta[200002],cnt;
vector<pii >qwq[200002];
vector<pii >add[200002],mns[200002];//bool vis[102][102];
inline void upd(int a,int b,int c,int d){
	if(a>b||c>d)return;//F(x,a,b)F(y,c,d)vis[x][y]=true;
	add[c].push_back({a,b});
	mns[d+1].push_back({a,b});
}
ll sum1[1600002],e[1600002];
int mmin[1600002],num[1600002],tag[1600002];
#define mid ((l+r)>>1)
inline void pushup(int pos){
	sum1[pos]=sum1[pos<<1]+sum1[pos<<1|1];
	if(mmin[pos<<1]<mmin[pos<<1|1])mmin[pos]=mmin[pos<<1],num[pos]=num[pos<<1];
	else if(mmin[pos<<1|1]<mmin[pos<<1])mmin[pos]=mmin[pos<<1|1],num[pos]=num[pos<<1|1];
	else mmin[pos]=mmin[pos<<1],num[pos]=num[pos<<1]+num[pos<<1|1];
}
inline void pushdown(int pos){
	if(tag[pos]){
		mmin[pos<<1]+=tag[pos],mmin[pos<<1|1]+=tag[pos];
		tag[pos<<1]+=tag[pos],tag[pos<<1|1]+=tag[pos];
		tag[pos]=0;
	}
	if(e[pos]){
		if(mmin[pos<<1]==mmin[pos])sum1[pos<<1]+=1ll*e[pos]*num[pos<<1],e[pos<<1]+=e[pos];
		if(mmin[pos<<1|1]==mmin[pos])sum1[pos<<1|1]+=1ll*e[pos]*num[pos<<1|1],e[pos<<1|1]+=e[pos];
		e[pos]=0;
	}
}
inline void orz(int pos,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		++tag[pos];
		++mmin[pos];
		return;
	}
	pushdown(pos);
	if(ql<=mid)orz(pos<<1,l,mid,ql,qr);
	if(qr>mid)orz(pos<<1|1,mid+1,r,ql,qr);
	pushup(pos);
}
inline void sto(int pos,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		--tag[pos];
		--mmin[pos];
		return;
	}
	pushdown(pos);
	if(ql<=mid)sto(pos<<1,l,mid,ql,qr);
	if(qr>mid)sto(pos<<1|1,mid+1,r,ql,qr);
	pushup(pos);
}
inline ll query(int pos,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		return sum1[pos];
	}
	ll ans=0;
	pushdown(pos);
	if(ql<=mid)ans=query(pos<<1,l,mid,ql,qr);
	if(qr>mid)ans+=query(pos<<1|1,mid+1,r,ql,qr);
	return ans;
}
ll ans[1000002];
inline void build(int pos,int l,int r){
	num[pos]=r-l+1;
	if(l==r)return;
	build(pos<<1,l,mid);build(pos<<1|1,mid+1,r);
}
signed main() {//freopen("data.txt","r",stdin);
	cin>>n>>q;
	F(i,1,n)read(a[i]);
	F(i,1,n)p[a[i]]=i;
	F(i,1,q){
		int l=read(),r=read();
		qwq[r].push_back({l,i});
	}
	cnt=0;
	F(i,1,n){
		while(cnt&&a[i]>a[sta[cnt]])--cnt;
		pre[i]=sta[cnt];
		sta[++cnt]=i;
	}
	cnt=0;sta[0]=n+1;
	UF(i,n,1){
		while(cnt&&a[i]>a[sta[cnt]])--cnt;
		suf[i]=sta[cnt];
		sta[++cnt]=i;
	}
	F(i,1,n){
		F(j,i+1,n/i){
			int x=p[i],y=p[j],z=p[i*j];
			if(x>y)swap(x,y);
			if(x<=z&&z<=y)upd(pre[z]+1,x,y,suf[z]-1);
			else if(z<x)upd(pre[z]+1,z,y,suf[z]-1);
			else upd(pre[z]+1,x,z,suf[z]-1);
		}
	}build(1,1,n);
	F(i,1,n){//cerr<<"S";
		for(auto j:add[i])orz(1,1,n,j.first,j.second);//cerr<<"A";
		for(auto j:mns[i])sto(1,1,n,j.first,j.second);//cerr<<"B";
		if(!mmin[1]){
			++e[1];
			sum1[1]+=num[1];	
		}//cerr<<"C";
		for(auto j:qwq[i])ans[j.second]=(i-j.first+1ll)*i-query(1,1,n,j.first,i);//cerr<<"D";
	//	hhh(1,1,n);
	}
	F(i,1,q)write(ans[i],'\n');//F(i,1,10)F(j,1,10)cerr<<vis[i][j]<<" \n"[j==10];
	return 0;
}
/*

*/