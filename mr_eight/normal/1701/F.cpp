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
struct M{
	ll a[4][4];
	ll* operator[](int pos){
		return a[pos]; 
	}
}I,ADD,MNS;
inline M operator*(const M &x,const M &y){
	M rt;memset(rt.a,0,sizeof(rt.a));
	F(i,0,3)F(j,i,3)F(k,j,3)rt.a[i][k]+=x.a[i][j]*y.a[j][k];
	return rt;
}
int lst[200002],n,d;
struct S{
	int l,r,v;
};
inline bool cmp(const S &x,const S &y){
	return x.v<y.v;
}
vector<S>q;
M tag[800002];
#define mid ((l+r)>>1)
inline void build(int pos,int l,int r){
	tag[pos]=I;
	if(l==r)return;
	build(pos<<1,l,mid);
	build(pos<<1|1,mid+1,r);
}
inline void puttag(int pos,M w){
	tag[pos]=tag[pos]*w;
}
inline void pushdown(int pos){
	if(memcmp(&tag[pos],&I,16<<3)){
		puttag(pos<<1,tag[pos]);
		puttag(pos<<1|1,tag[pos]);
		tag[pos]=I;
	}
}
inline void add(int pos,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		tag[pos]=tag[pos]*ADD;
		return;
	}
	pushdown(pos);
	if(ql<=mid)add(pos<<1,l,mid,ql,qr);
	if(qr>mid)add(pos<<1|1,mid+1,r,ql,qr);
}
inline void mns(int pos,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		tag[pos]=tag[pos]*MNS;
		return;
	}
	pushdown(pos);
	if(ql<=mid)mns(pos<<1,l,mid,ql,qr);
	if(qr>mid)mns(pos<<1|1,mid+1,r,ql,qr);
}
inline void dfs(int pos,int l,int r){
	if(l==r)write(tag[pos][0][3],'\n');
	else{
		pushdown(pos);
		dfs(pos<<1,l,mid);
		dfs(pos<<1|1,mid+1,r);
	}
}
int main() {
	F(i,0,3)I[i][i]=1;
	ADD=MNS=I;
	ADD[0][1]=ADD[1][2]=ADD[2][3]=1;
	MNS[0][1]=MNS[1][2]=-1,MNS[0][2]=1;
	cin>>n>>d;
	F(i,1,n){
		int x=read();
		if(lst[x]){
			q.push_back({lst[x],i-1,x});
			lst[x]=0;
		}else lst[x]=i;
	}
	F(i,1,200000)if(lst[i])q.push_back({lst[i],n,i});
	sort(q.begin(),q.end(),cmp);
	int l=0;build(1,1,n);
	F(i,0,q.size()-1){
		while(q[i].v-q[l].v>d){
			mns(1,1,n,q[l].l,q[l].r);//cerr<<"mns "<<q[l].l<<" "<<q[l].r<<endl;
			++l;
		}
		add(1,1,n,q[i].l,q[i].r);//cerr<<"add "<<q[i].l<<" "<<q[i].r<<endl;dfs(1,1,n);
	}
	dfs(1,1,n);
	return 0;
}