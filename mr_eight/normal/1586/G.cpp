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
#define mod 1000000007
int a[200002],b[200002],aa[200002],bb[200002],p[200002],q[200002],nxt[200002],n,m,N;
ll c[400002];
bool vis[200002];
inline bool cmp(int x,int y){
	return aa[x]<aa[y];
}
inline void add(int pos,int v){
	while(pos<=N){
		c[pos]+=v;
		pos+=(-pos&pos);
	}
}
inline int query(int pos){
	ll rt=0;
	while(pos){
		rt+=c[pos];
		pos-=(-pos&pos);
	}
	return rt%mod;
}
int main(){
	cin>>n;N=n<<1|1;
	add(1,1);
	F(i,1,n)read(aa[i],bb[i]),++bb[i],p[i]=i;
	sort(p+1,p+n+1,cmp);
	F(i,1,n)a[i]=aa[p[i]],b[i]=bb[p[i]],q[p[i]]=i;
	cin>>m;
	F(i,1,m)p[i]=q[read()];
	sort(p+1,p+m+1);
	int lst=1;
	UF(i,m,1){
		nxt[p[i]]=lst;
		if(b[p[i]]>lst)vis[p[i]]=true,lst=b[p[i]];
	}
	ll ans=0;
	UF(i,n,1){
		int temp=query(b[i]);
		if(vis[i])ans+=query(nxt[i]-1);
		add(b[i],temp);
	}
	cout<<(ans+query(lst-1))%mod;
	cerr<<endl<<"1ink AK IOI!!!!!";
    return 0;
}