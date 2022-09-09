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
struct node{
	int a,b,c,ab,bc,abc;
};
inline node merge(node x,node y){
	node rt;
	rt.abc=x.abc+y.abc;
	int temp=min(x.a,y.bc);
	rt.abc+=temp;
	x.a-=temp;
	y.bc-=temp;
	temp=min(x.ab,y.c);
	rt.abc+=temp;
	x.ab-=temp;
	y.c-=temp;
	temp=min(x.ab,y.bc);
	x.ab-=temp;
	y.bc-=temp;
	rt.abc+=temp;
	rt.b+=temp;
	temp=min(x.a,y.b);
	rt.ab+=temp;
	x.a-=temp;
	y.b-=temp;
	temp=min(x.b,y.c);
	rt.bc+=temp;
	x.b-=temp;
	y.c-=temp;
	rt.a+=x.a+y.a;
	rt.b+=x.b+y.b;
	rt.c+=x.c+y.c;
	rt.ab+=x.ab+y.ab;
	rt.bc+=x.bc+y.bc;
	return rt;
}
node v[400002];
char s[100002];
int n;
#define mid ((l+r)>>1)
inline void build(int pos,int l,int r){
	if(l==r){
		if(s[l]=='a')v[pos]={1,0,0,0,0,0};
		else if(s[l]=='b')v[pos]={0,1,0,0,0,0};
		else v[pos]={0,0,1,0,0,0};
		return;
	}
	build(pos<<1,l,mid);
	build(pos<<1|1,mid+1,r);
	v[pos]=merge(v[pos<<1],v[pos<<1|1]);
}
inline void modify(int pos,int l,int r,int q){
	if(l==r){
		if(s[l]=='a')v[pos]={1,0,0,0,0,0};
		else if(s[l]=='b')v[pos]={0,1,0,0,0,0};
		else v[pos]={0,0,1,0,0,0};
		return;
	}
	if(q<=mid)modify(pos<<1,l,mid,q);
	else modify(pos<<1|1,mid+1,r,q);
	v[pos]=merge(v[pos<<1],v[pos<<1|1]);
}
int q;
char ch[5];
int main() {
	cin>>n>>q;
	scanf("%s",s+1);
	build(1,1,n);
	F(i,1,q){
		int pos=read();
		scanf("%s",ch);
		s[pos]=ch[0];
		modify(1,1,n,pos);
		write(v[1].abc,'\n');
	}
	return 0;
}