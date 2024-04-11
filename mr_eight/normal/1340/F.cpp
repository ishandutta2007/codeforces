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
#define base 131
#define inv 694656574
#define mod 1000000123
struct S{
	int l,r;
	ll lh,rh;
	bool tag;
}v[400002];
ll *pw,buf[400003];
inline ll queryr(int x,int len){
	if(len==0)return 0;
	if(len==v[x].r)return v[x].rh;
	if(v[x<<1|1].r>=len)return queryr(x<<1|1,len);
	return (pw[v[x<<1|1].r-v[x<<1|1].l]*(queryr(x<<1,len-v[x<<1|1].r+v[x<<1|1].l)-v[x<<1|1].lh+mod)+v[x<<1|1].rh)%mod;
}
inline ll queryl(int x,int len){
	if(len==0)return 0;
	if(len==v[x].l)return v[x].lh;
	if(v[x<<1].l>=len)return queryl(x<<1,len);
	return (pw[v[x<<1].l-v[x<<1].r]*(queryl(x<<1|1,len-v[x<<1].l+v[x<<1].r)-v[x<<1].rh+mod)+v[x<<1].lh)%mod;
}
inline S merge(int x,int y){
	if(v[x].tag||v[y].tag)return {0,0,0ll,0ll,true};
	int mmin=min(v[x].r,v[y].l);
	if(queryr(x,mmin)!=queryl(y,mmin))return {0,0,0ll,0ll,true};
	if(v[x].r==v[y].l)return {v[x].l,v[y].r,v[x].lh,v[y].rh,false};
	if(v[x].r<v[y].l)return {v[x].l+v[y].l-v[x].r,v[y].r,(v[x].lh+pw[v[x].l-v[x].r]*(v[y].lh-v[x].rh+mod))%mod,v[y].rh,false};
	else return {v[x].l,v[x].r+v[y].r-v[y].l,v[x].lh,(v[y].rh+pw[v[y].r-v[y].l]*(v[x].rh-v[y].lh+mod))%mod,false};
}
inline void pushup(int x){
	v[x]=merge(x<<1,x<<1|1);
}
#define mid ((l+r)>>1)
inline void build(int pos,int l,int r){
	if(l==r){
		int x=read();
		if(x>0)v[pos]={0,1,0,x,false};
		else v[pos]={1,0,-x,0,false};
	}else{
		build(pos<<1,l,mid);
		build(pos<<1|1,mid+1,r);
		pushup(pos);
	}
}
inline void modify(int pos,int l,int r,int q,int x){
	if(l==r){
		if(x>0)v[pos]={0,1,0,x,false};
		else v[pos]={1,0,-x,0,false};
	}else{
		if(q<=mid)modify(pos<<1,l,mid,q,x);
		else modify(pos<<1|1,mid+1,r,q,x);
		pushup(pos);
	}
}
int sta[1002],cnt,tot;
pii res[1002];
inline void query(int pos,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		sta[++cnt]=pos;
		return;
	}
	if(ql<=mid)query(pos<<1,l,mid,ql,qr);
	if(qr>mid)query(pos<<1|1,mid+1,r,ql,qr);
}
inline bool check(){
	F(i,1,cnt){
		if(v[sta[i]].tag)return false;
		int kk=v[sta[i]].l;
		while(kk&&tot){
			if(res[tot].second>kk){
				if((queryr(res[tot].first,kk+v[res[tot].first].r-res[tot].second)-queryr(res[tot].first,v[res[tot].first].r-res[tot].second)+mod)*pw[-(v[res[tot].first].r-res[tot].second)]%mod
				==(queryl(sta[i],v[sta[i]].l)-queryl(sta[i],v[sta[i]].l-kk)+mod)*pw[-(v[sta[i]].l-kk)]%mod){
					res[tot].second-=kk;
					kk=0;
				}else return false;
			}else{
				if((queryr(res[tot].first,v[res[tot].first].r)-queryr(res[tot].first,v[res[tot].first].r-res[tot].second)+mod)*pw[-(v[res[tot].first].r-res[tot].second)]%mod==
				(queryl(sta[i],v[sta[i]].l-kk+res[tot].second)-queryl(sta[i],v[sta[i]].l-kk)+mod)*pw[-(v[sta[i]].l-kk)]%mod){
					kk-=res[tot].second;
					--tot;
				}else return false;
			}
		}
		if(kk)return false;
		if(v[sta[i]].r)res[++tot]=make_pair(sta[i],v[sta[i]].r);
	}
	return (tot==0);
}
int n,m;
int main(){
	pw=buf+200001;
	pw[0]=1;
	F(i,1,200001)pw[i]=pw[i-1]*base%mod;
	UF(i,-1,-200001)pw[i]=pw[i+1]*inv%mod;
	cin>>n>>m;
	build(1,1,n);
	F(i,1,read()){
		if(read()==1){
			int p=read();
			modify(1,1,n,p,read());
		}else{
			int l=read(),r=read();
			cnt=tot=0;
			query(1,1,n,l,r);
			puts(check()?"Yes":"No");
		}
	}
    return 0;
}
/*
6 2
1 2 -2 -1 1 -1
3
2 1 6
2 1 4
2 2 5
*/