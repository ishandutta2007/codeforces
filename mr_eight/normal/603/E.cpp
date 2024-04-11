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
int n,m,xx[300002],yy[300002],w[300002],t[300002],ans[300002],x[300002],y[300002],id[300002];
map<int,int>mp;
namespace bcj{
	int fa[300002],sta[300002],cnt,sz[300002],ans;
	inline int findf(int x){
		while(fa[x]!=x)x=fa[x];
		return x;
	}
	inline void merge(int x,int y){
		x=findf(x);
		y=findf(y);
		if(sz[x]>sz[y])swap(x,y);//cerr<<"merge "<<x<<" "<<y<<endl;
		if(x==y){
			sta[++cnt]=0;
			return;
		}
		sta[++cnt]=x;
		ans-=(sz[x]&sz[y]&1);
		sz[y]+=sz[x];
		fa[x]=y;
	}
	inline void pop(){
		int x=sta[cnt--],y=fa[x];//cerr<<"pop "<<x<<" "<<y<<endl;
		sz[y]-=sz[x];
		fa[x]=x;
		ans+=(sz[x]&sz[y]&1);
	}
}
inline int solve(int l,int r,int ql,int qr){
	//cerr<<l<<" "<<r<<" "<<ql<<" "<<qr<<endl;
	if(l==r){
		F(i,ql,qr){
			if(id[i]<=l)bcj::merge(x[i],y[i]);
			if(!bcj::ans){//cerr<<"getans "<<l<<" "<<t[i]<<endl;
				ans[l]=i;
				break;
			}
		}
		if(!ans[l])ans[l]=m+1;
		F(i,ql,min(ans[l],m))if(id[i]<=l)bcj::pop();
		return ans[l];
	}
	if(ql==qr){
		F(i,l,r)ans[i]=ql;
		return ql;
	}
	int mid=(l+r)>>1;
	F(i,l+1,mid+1)if(w[i]<ql)bcj::merge(xx[i],yy[i]);
	int k=solve(mid+1,r,ql,qr);
	F(i,l+1,mid+1)if(w[i]<ql)bcj::pop();
	F(i,ql,k-1)if(id[i]<=l)bcj::merge(x[i],y[i]);
	int rt=solve(l,mid,k,qr);
	F(i,ql,k-1)if(id[i]<=l)bcj::pop();
	return rt;
}
int main(){
	cin>>n>>m;
	if(n&1){
		F(i,1,m)puts("-1");
		return 0;
	}
	bcj::ans=n>>1;
	F(i,1,n)bcj::fa[i]=i,bcj::sz[i]=1;
	F(i,1,m)read(xx[i]),read(yy[i]),read(w[i]),t[i]=w[i];
	sort(t+1,t+m+1);
	F(i,1,m)mp[t[i]]=i;
	F(i,1,m)w[i]=mp[w[i]]--,x[w[i]]=xx[i],y[w[i]]=yy[i],id[w[i]]=i;
	solve(1,m,1,m+1);
	F(i,1,m)write((ans[i]<=m?t[ans[i]]:-1),'\n');
    return 0;
}