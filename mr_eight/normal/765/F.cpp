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
#define vi vector<int>
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
int n,a[100002],b[100002],c[100002],sq,l[100002],r[100002],in[100002],cnt;
int orz[330][330],num[330],t[100002],ps[100002][330],ss[330][330],pre[330][330][330],suf[330][330][330];
int temp[100002],t1[100002],anspre[330][330],anssuf[330][330],anss[330];
bool vis[330];
#define abs $$$
inline int abs(int x){
	return x>0?x:-x;
}
inline int solve(int n,int m,int *a,int *b,int mmin){
	int i=1,j=1,ans=mmin;
	while(i<=n&&j<=m){
		if(a[i]<b[j]){
			ans=min(ans,b[j]-a[i]);
			++i;
		}else{
			ans=min(ans,a[i]-b[j]);
			++j;
		}
	}
	return ans;
}
inline int bf(int x,int L,int R){
	memset(vis,0,sizeof(vis));
	F(i,L,R){
		if(vis[c[i]])return 0;
		vis[c[i]]=true;
	}
	int lst=-1000000000,ans=INT_MAX;
	F(i,1,r[x]-l[x]+1){
		if(vis[i]){
			ans=min(ans,orz[x][i]-lst);
			lst=orz[x][i];
		}
	}
	return ans;
}
int main() {
	memset(ps,0x3f,sizeof(ps));
	memset(ss,0x3f,sizeof(ss));
	cin>>n;
	F(i,1,n)read(a[i]),t[i]=a[i];
	sort(t+1,t+n+1);
	F(i,1,n)b[i]=lower_bound(t+1,t+n+1,a[i])-t;
	sq=sqrt(n);
	cnt=(n+sq-1)/sq;
	F(i,1,cnt){
		anspre[i][0]=anssuf[i][0]=INT_MAX;
		l[i]=r[i-1]+1;
		r[i]=min(n,r[i-1]+sq);
		F(j,l[i],r[i])in[j]=i,orz[i][++num[i]]=a[j];
		sort(orz[i]+1,orz[i]+num[i]+1);
		F(j,l[i],r[i])c[j]=lower_bound(orz[i]+1,orz[i]+num[i]+1,a[j])-orz[i];
		F(j,1,r[i]-l[i]+1){
			memcpy(pre[i][j],pre[i][j-1],sizeof(pre[i][j]));
			pre[i][j][j]=a[l[i]+j-1];
			int k=j;
			for(;pre[i][j][k]<pre[i][j][k-1];--k)swap(pre[i][j][k],pre[i][j][k-1]);
			anspre[i][j]=anspre[i][j-1];
			if(k!=1)anspre[i][j]=min(anspre[i][j],pre[i][j][k]-pre[i][j][k-1]);
			if(k!=j)anspre[i][j]=min(anspre[i][j],pre[i][j][k+1]-pre[i][j][k]);
		}
		anss[i]=anspre[i][r[i]-l[i]+1];
		F(j,1,r[i]-l[i]+1){
			#define pre suf
			#define anspre anssuf
			memcpy(pre[i][j],pre[i][j-1],sizeof(pre[i][j]));
			pre[i][j][j]=a[r[i]-j+1];
			int k=j;
			for(;pre[i][j][k]<pre[i][j][k-1];--k)swap(pre[i][j][k],pre[i][j][k-1]);
			anspre[i][j]=anspre[i][j-1];
			if(k!=1)anspre[i][j]=min(anspre[i][j],pre[i][j][k]-pre[i][j][k-1]);
			if(k!=j)anspre[i][j]=min(anspre[i][j],pre[i][j][k+1]-pre[i][j][k]);
			#undef pre
			#undef anspre
		}
		memset(temp,0,sizeof(temp));
		memset(t1,0,sizeof(t1));
		F(j,l[i],r[i]){
			temp[b[j]]=b[j];
		}
		#define i j
		UF(i,n,1)t1[i]=(temp[i]?temp[i]:t1[i+1]);
		F(i,2,n)if(!temp[i])temp[i]=temp[i-1];
		#undef i
		F(j,1,n){
			if(t1[b[j]])ps[j][i]=t[t1[b[j]]]-a[j];
			if(temp[b[j]])ps[j][i]=min(ps[j][i],a[j]-t[temp[b[j]]]);
		}
	}
	l[cnt+1]=n+1;
	F(i,1,cnt){
		ss[i][i]=anss[i];
		F(j,i+1,cnt){
			ss[i][j]=min(ss[i][j-1],solve(r[i]-l[i]+1,r[j]-l[j]+1,orz[i],orz[j],min(anss[i],anss[j])));
		}
	}
	F(j,1,cnt){
		UF(i,j-1,1)ss[i][j]=min(ss[i][j],ss[i+1][j]);
	}
	F(i,1,n){
		UF(j,in[i]-2,1)ps[i][j]=min(ps[i][j],ps[i][j+1]);
		F(j,in[i]+2,cnt)ps[i][j]=min(ps[i][j],ps[i][j-1]);
	}
	F(q,1,read()){
		int L,R;
		read(L,R);
		if(in[L]==in[R])write(bf(in[L],L,R),'\n');
		else{
			int sl=in[L]+1,sr=in[R]-1,ans=ss[sl][sr];
			if(sl<=sr){
				F(i,L,r[in[L]])ans=min(ans,ps[i][sr]);
				UF(i,R,l[in[R]])ans=min(ans,ps[i][sl]);
			}
			ans=min(ans,min(anssuf[sl-1][l[sl]-L],anspre[sr+1][R-r[sr]]));
			write(solve(l[sl]-L,R-r[sr],suf[sl-1][l[sl]-L],pre[sr+1][R-r[sr]],ans),'\n');
		}
	}
	return 0;
}