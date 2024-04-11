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
struct bcj{
	int fa[500002],sz[500002],sta[500002],cnt;
	bool w[500002];
	bcj(){
		F(i,1,500000)sz[i]=1,fa[i]=i;
	}
	inline void findf(int &x,bool &v){
		while(fa[x]!=x)v^=w[x],x=fa[x];
		return;
	}
	inline void merge(int x,int y){
		bool v=true;
		findf(x,v);findf(y,v);
		if(x==y){
			sta[++cnt]=0;
			return;
		}
		if(sz[x]>sz[y])swap(x,y);
		fa[x]=y;
		sta[++cnt]=x;
		sz[y]+=sz[x];
		w[x]=v;
	}
	inline bool check(int x,int y){
		bool v=false;
		findf(x,v);findf(y,v);
		return x!=y||v;
	}
	inline void pop(){
		int x=sta[cnt--];
		if(!x)return;
		w[x]=false;
		sz[fa[x]]-=sz[x];
		fa[x]=x;
	}
}b[51];
int temp;
vector<int>upd[2000002];
int n,m,x[500002],y[500002],k,q,lst[500002],p[500002],v[500002],ed[500002];
#define mid ((l+r)>>1)
inline void add(int pos,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){//if(v[temp]==2)cerr<<l<<" "<<r<<endl;
		upd[pos].push_back(temp);
		return;
	}
	if(ql<=mid)add(pos<<1,l,mid,ql,qr);
	if(qr>mid)add(pos<<1|1,mid+1,r,ql,qr);
}
inline void solve(int pos,int l,int r){
	for(int i:upd[pos])b[v[i]].merge(x[p[i]],y[p[i]]);
	//for(int i:upd[pos])if(v[i]==2)cerr<<l<<" "<<r<<endl;
	if(l==r){
		bool ck=b[v[l]].check(x[p[l]],y[p[l]]);
		if(ck){putchar('Y');putchar('E');putchar('S');putchar('\n');}
		else{putchar('N');putchar('O');putchar('\n');}
		if(ck){
			lst[p[l]]=l;
			if(ed[l]>l){
				temp=l;
				add(1,1,q,l+1,ed[l]);
			}
		}else{
			if(ed[l]>l){
				temp=lst[p[l]];
				add(1,1,q,l+1,ed[l]);
			}
		}
	}else{
		solve(pos<<1,l,mid);
		solve(pos<<1|1,mid+1,r);
	}
	for(int i:upd[pos])b[v[i]].pop();
}
int main() {
	cin>>n>>m>>k>>q;
	F(i,1,m){
		read(x[i]);read(y[i]);
		lst[i]=q+1;
	}
	F(i,1,q){
		read(p[i]);read(v[i]);
	}
	UF(i,q,1){
		ed[i]=lst[p[i]]-1;
		lst[p[i]]=i;
	}
	memset(lst,0,sizeof(lst));
	//F(i,1,q)cerr<<ed[i]<<endl;
	solve(1,1,q);
	//F(j,1,2)F(i,1,n)cerr<<b[j].fa[i]<<" "<<b[j].sz[i]<<' '<<b[j].w[i]<<endl;
	return 0;
}
/*
4 5 2 6
1 2
2 3
1 3
1 4
3 4
1 1
2 1
4 2
5 2
3 1
3 2
*/