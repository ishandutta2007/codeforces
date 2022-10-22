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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
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
int n,m,k,x,y,z,w,now,dfn,p,p1[200002],p2[200002],p3[200002],p4[200002],t1[200002],t2[200002],t3[200002],t4[200002];
ll sum,ans=LLONG_MAX,orz;
ll ab[200002],a[200002],b[200002],c[200002];
bool vis[800002];
tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> T;
priority_queue<pii,vector<pii>,greater<pii> >q;
inline void ins(ll x){
	T.insert(x<<30ll|(++dfn));
	if(now>=0&&T.order_of_key(x<<30ll|dfn)<now){
		sum+=x;
		sum-=(*T.find_by_order(now)>>30ll);
	}
}
inline void upd(){
	if(now<0)++now;
	else sum+=(*T.find_by_order(now++)>>30ll);
}
inline bool cmpab(int x,int y){
	return ab[x]<ab[y];
}
inline bool cmpa(int x,int y){
	return a[x]<a[y];
}
inline bool cmpb(int x,int y){
	return b[x]<b[y];
}
inline bool cmpc(int x,int y){
	return c[x]<c[y];
}
int main(){
	F(i,1,200000)T.insert(1ll<<61ll|i);
	cin>>n>>m>>k;
	F(i,1,n)a[i]=b[i]=c[i]=ab[i]=2000114514,p1[i]=p2[i]=p3[i]=p4[i]=i;
	F(i,1,n){
		int t=read(),ak=read(),ioi=read();
		if(ak&&ioi)ab[++x]=t,t1[x]=i;
		else if(ak)a[++y]=t,t2[y]=i;
		else if(ioi)b[++z]=t,t3[z]=i;
		else c[++w]=t,t4[w]=i;
	}
	sort(p1+1,p1+x+1,cmpab);
	sort(p2+1,p2+y+1,cmpa);
	sort(p3+1,p3+z+1,cmpb);
	sort(p4+1,p4+w+1,cmpc);
	sort(ab+1,ab+x+1);
	sort(a+1,a+y+1);
	sort(b+1,b+z+1);
	sort(c+1,c+w+1);
	F(i,1,w)ins(c[i]);
	F(i,k+1,x)ins(ab[i]);
	F(i,k+1,y)ins(a[i]);
	F(i,k+1,z)ins(b[i]);
	F(i,1,k)sum+=a[i]+b[i];
	now=m-k-k;
	F(i,0,now-1)sum+=(*T.find_by_order(i)>>30ll);
	if(now>=0){
		if(ans>sum){
			p=0;
			ans=sum;
		}
	}
	F(i,1,k){
		sum+=ab[i];
		sum-=a[k-i+1];
		sum-=b[k-i+1];
		ins(a[k-i+1]);
		ins(b[k-i+1]);
		upd();
		if(now>=0&&ans>sum){
			ans=sum;
			p=i;
		}
	}
	if(ans<=2000000000){
		cout<<ans<<endl;
		F(i,1,p)write(t1[p1[i]],' '),vis[i]=true;
		F(i,1,k-p)write(t2[p2[i]],' '),vis[i+n]=true;
		F(i,1,k-p)write(t3[p3[i]],' '),vis[i+n+n]=true;
		F(i,1,n+n+n+n){
			if(!vis[i]){
				if(i<=n)q.push(make_pair(ab[i],t1[p1[i]]));
				else if(i<=n+n)q.push(make_pair(a[i-n],t2[p2[i-n]]));
				else if(i<=n+n+n)q.push(make_pair(b[i-n-n],t3[p3[i-n-n]]));
				else q.push(make_pair(c[i-n-n-n],t4[p4[i-n-n-n]]));
			}
		}
		F(i,1,m-p-max(0,k-p)-max(0,k-p)){
			write(q.top().second,' ');
			q.pop();
		}
	}
	else cout<<-1;
    return 0;
}