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
const int sq=2300;
namespace ds{
	int cnt[100002],lst[100002],nxt[100002];
	inline void insert(int x){
		++cnt[x];
		if(cnt[x]==1){
			nxt[x]=100001;
			lst[x]=lst[100001];
			lst[100001]=x;
			nxt[lst[x]]=x;
		}
	}
	inline void erase(int x){
		--cnt[x];
		if(cnt[x]==0){
			nxt[lst[x]]=nxt[x];
			lst[nxt[x]]=lst[x];
		}
	}
};
using ds::insert;
using ds::erase;
int t1,cnt,nxt[100002],lst[100002],p[100002],ans[100002],
x,y,z,n,m,now,a[100002],b[100002],ak[100002];
struct query{
	int pos,l,r,orz,k;
}q[100002];
inline bool cmp(const query &x,const query &y){
	if(x.pos/sq!=y.pos/sq){
		return x.pos<y.pos;
	}
	if((x.l-1)/sq!=(y.l-1)/sq){
		return x.l<y.l;
	}
	if(x.r!=y.r)return x.r<y.r;
	return x.orz<y.orz;
}
inline void upd(int pos){
	a[p[pos]]=nxt[pos];
	if(y<=p[pos]&&z>=p[pos]){
		++ak[nxt[pos]];
		insert(ak[nxt[pos]]);
		erase(ak[nxt[pos]]-1);
		--ak[lst[pos]];
		insert(ak[lst[pos]]);
		erase(ak[lst[pos]]+1);
	}
}
inline void dpd(int pos){
	a[p[pos]]=lst[pos];
	if(y<=p[pos]&&z>=p[pos]){
		--ak[nxt[pos]];
		insert(ak[nxt[pos]]);
		erase(ak[nxt[pos]]+1);
		++ak[lst[pos]];
		insert(ak[lst[pos]]);
		erase(ak[lst[pos]]-1);
	}
}
inline void add(int pos){
	++ak[a[pos]];
	insert(ak[a[pos]]);
	erase(ak[a[pos]]-1);
}
inline void mns(int pos){
	--ak[a[pos]];
	insert(ak[a[pos]]);
	erase(ak[a[pos]]+1);
}
namespace getans{
	int a[100002],b[100002],cnt;
	inline int query(int k){
		cnt=0;
		for(ri i=ds::nxt[0];i<=100000;i=ds::nxt[i]){
			a[++cnt]=i;
		}
		sort(a+1,a+cnt+1);
		F(i,1,cnt)b[i]=ds::cnt[a[i]];
		b[cnt+1]=1e9;
		int ans=1e9,now=0,r=0;
		F(l,1,cnt){
			now-=b[l-1];
			while(now<k){
				now+=b[++r];
			}if(r>cnt)break;
			ans=min(ans,a[r]-a[l]);
		}
		return ans;
	}
}
int main() {
	ds::nxt[0]=100001;
	ds::lst[100001]=0;
	y=1;
	cin>>n>>m;
	F(i,1,n){
		read(a[i]);
		b[i]=a[i];
	}
	F(i,1,m){
		if(read()==1){
			++cnt;
			ri o=read(),r=read(),zhq=read();
			q[cnt]=(query){t1,o,r,cnt,zhq};
		}else{
			++t1;
			ri o=read(),r=read();
			p[t1]=o;
			nxt[t1]=r;
			lst[t1]=b[o];
			b[o]=r;
		}
	}
	sort(q+1,q+cnt+1,cmp);
	F(i,1,cnt){
		while(x<q[i].pos)upd(++x);
		while(x>q[i].pos)dpd(x--);
		while(y>q[i].l)add(--y);
		while(z<q[i].r)add(++z);
		while(y<q[i].l)mns(y++);
		while(z>q[i].r)mns(z--);
		ans[q[i].orz]=getans::query(q[i].k);
	}
	F(i,1,cnt){
		if(ans[i]<1e6)write(ans[i],'\n');
		else puts("-1");
	}
	return 0;
}