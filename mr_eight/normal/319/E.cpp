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
int fa[100002];
inline int findf(int x){return (fa[x]==x)?x:(fa[x]=findf(fa[x]));}
int t[200002],t1[100002],t2[100002],n,cnt,op[100002],l[100002],r[100002],tot;
vector<int>a[800002];
#define mid ((lqwq+rqwq)>>1)
inline void merge(int pos,int lqwq,int rqwq,int q,int x){
	if(!a[pos].empty()){
		for(int i:a[pos]){
			int j=findf(i);
			l[x]=min(l[x],l[j]);
			r[x]=max(r[x],r[j]);
			fa[j]=x;
		}
		a[pos].clear();
		a[pos].push_back(x);	
	}
	if(lqwq==rqwq)return;
	if(q<=mid)merge(pos<<1,lqwq,mid,q,x);
	else merge(pos<<1|1,mid+1,rqwq,q,x);
}
#undef mid
#define mid ((l+r)>>1)
inline void add(int pos,int l,int r,int ql,int qr,int x){
	if(ql<=l&&qr>=r){
		a[pos].push_back(x);
		return;
	}
	if(ql<=mid)add(pos<<1,l,mid,ql,qr,x);
	if(qr>mid)add(pos<<1|1,mid+1,r,ql,qr,x);
}
int main() {
	cin>>n;
	F(i,1,n){
		read(op[i]);read(t1[i]);read(t2[i]);
		if(op[i]==1){
			++cnt;
			fa[cnt]=cnt;
			l[cnt]=t1[i];
			r[cnt]=t2[i];
			t[++tot]=t1[i];
			t[++tot]=t2[i];
		}
	}
	sort(t+1,t+tot+1);
	tot=unique(t+1,t+tot+1)-t-1;
	F(i,1,cnt)l[i]=lower_bound(t+1,t+tot+1,l[i])-t,r[i]=lower_bound(t+1,t+tot+1,r[i])-t;
	cnt=0;
	F(i,1,n){
		if(op[i]==1){
			++cnt;
			#define i cnt
			int tr=r[i];
			merge(1,1,tot,l[i],cnt);
			merge(1,1,tot,tr,cnt);
			if(l[i]+1<r[i])add(1,1,tot,l[i]+1,r[i]-1,cnt);
			#undef i
		}else{
			t1[i]=findf(t1[i]);
			t2[i]=findf(t2[i]);
			if(t1[i]==t2[i]||(l[t1[i]]>l[t2[i]]&&l[t1[i]]<r[t2[i]])||(r[t1[i]]>l[t2[i]]&&r[t1[i]]<r[t2[i]]))puts("YES");
			else puts("NO");
		}
	}
	return 0;
}