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
int lc[8000002],rc[8000002],root[100002],cnt,s[100002],m[100002],rrr[100002],n;
ll k[8000002],b[8000002];
#define mid ((l+r)>>1)
inline int cpy(int x){
	++cnt;
	lc[cnt]=lc[x];
	rc[cnt]=rc[x];
	k[cnt]=k[x];
	b[cnt]=b[x];
	return cnt;
}
inline void pushup(int pos){
	k[pos]=k[lc[pos]]+k[rc[pos]];
	b[pos]=b[lc[pos]]+b[rc[pos]];
}
inline void add(int &pos,int l,int r,int q,int kk,int bb){
	pos=cpy(pos);
	k[pos]+=kk;
	b[pos]+=bb;
	if(l==r)return;
	if(q<=mid)add(lc[pos],l,mid,q,kk,bb);
	else add(rc[pos],mid+1,r,q,kk,bb);
}
inline ll query(int pos,int l,int r,int ql,int qr,int t){
	if(ql<=l&&qr>=r){
		return k[pos]*t+b[pos];
	}
	if(ql<=mid&&qr>mid)return query(lc[pos],l,mid,ql,qr,t)+query(rc[pos],mid+1,r,ql,qr,t);
	if(ql<=mid)return query(lc[pos],l,mid,ql,qr,t);
	return query(rc[pos],mid+1,r,ql,qr,t);
}
inline void build(int &pos,int l,int r){
	pos=++cnt;
	if(l==r){
		k[pos]=rrr[l];
		return;
	}
	build(lc[pos],l,mid);
	build(rc[pos],mid+1,r);
	pushup(pos);
}
vector<int>upd[100002];
namespace ctl{
	bool vis[100002];
	struct node{
		mutable int l,r,v;
		inline bool operator<(const node &b)const{
			return l<b.l;
		}
	};
	set<node>S;
	#define iter set<node>::iterator
	inline iter split(int x){
		if(x>n)return S.end();
		iter it=--S.upper_bound({x,0,0});
		if(it->l>=x)return it;
		node temp={x,it->r,it->v};
		it->r=x-1;
		S.insert(temp);
		return S.find(temp);
	}
	inline void modify(int l,int r,int t){
		ll ans=0;
		iter x=split(l),y=split(r+1);
		for(iter i=x;i!=y;++i){//cerr<<i->l<<"  "<<i->r<<"  "<<i->v<<endl;
			if(!vis[i->l]){//cerr<<'k'<<endl;
				ans+=min((ll)m[i->l],s[i->l]+1ll*rrr[i->l]*t);
				vis[i->l]=true;
			}
			else ans+=query(root[min(t-i->v,100000)],1,n,i->l,i->r,t-i->v);//cerr<<ans<<endl;
		}
		S.erase(x,y);
		S.insert({l,r,t});
		write(ans,'\n');
	}
}
int main(){
	cin>>n;
	F(i,1,n){
		read(s[i]);read(m[i]);read(rrr[i]);
		if(rrr[i])upd[max(1,(m[i]+rrr[i]-1)/rrr[i])].push_back(i);
	}
	build(root[0],1,n);
	F(i,1,100000){
		root[i]=root[i-1];
		for(int x:upd[i]){
			add(root[i],1,n,x,-rrr[x],m[x]);
		}
	}
	F(i,1,n)ctl::S.insert({i,i,0});
	F(iakioi,1,read()){
		int t=read(),l=read(),r=read();
		ctl::modify(l,r,t);
	}
    return 0;
}