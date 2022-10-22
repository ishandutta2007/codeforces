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
int n,a[200002],num[200002],mmax,pre[200002],lst[200002],nxt[200002];
int *l,buf[400004],ans;
vector<int>p[200002];
const int sq=300;
inline void AK(int x){
	l[0]=0;
	F(i,0,num[x]-1){
		int qwq=(i?p[x][i-1]:0),now=p[x][i];
		for(int j=lst[now],cnt=0;cnt<=num[x]&&j>qwq;j=lst[j],++cnt){
			l[pre[j]-i]=min(l[pre[j]-i],j);
		}
		l[pre[qwq]-i]=min(l[pre[qwq]-i],qwq);
	}
	F(i,0,num[x]-1){//if(x==360)cerr<<i<<endl;
		int qaq=(i+1==num[x]?n+1:p[x][i+1]),now=p[x][i];
		ans=max(ans,min(nxt[now],qaq)-1-l[pre[now]-i-1]);
		for(int j=nxt[now],cnt=0;cnt<=num[x]&&j<qaq;j=nxt[j],++cnt){//if(x==360)cerr<<j<<' '<<pre[j]<<' '<<i<<endl;
			ans=max(ans,min(nxt[j],qaq)-1-l[pre[j]-i-1]);
		}
	}
	F(i,0,num[x]-1){
		int qwq=(i?p[x][i-1]:0),now=p[x][i];
		for(int j=lst[now],cnt=0;cnt<=num[x]&&j>qwq;j=lst[j],++cnt){
			l[pre[j]-i]=1000000000;
		}
		l[pre[qwq]-i]=1000000000;
	}
}
inline void IOI(int x){
	int now=0;
	l[0]=0;
	F(i,1,n){
		now+=(a[i]==mmax?1:(a[i]==x?-1:0));
		if(l[now]<100000000)ans=max(ans,i-l[now]);
		else l[now]=i;
	}
	memset(buf,0x3f,sizeof(buf));
}
int main(){
//	freopen("data.txt","r",stdin);
	l=buf+200002;
	memset(buf,0x3f,sizeof(buf));
	cin>>n;
	F(i,1,n){
		read(a[i]);
		++num[a[i]];
		p[a[i]].push_back(i);
	}
	mmax=max_element(num+1,num+n+1)-num;cerr<<mmax<<"   "<<num[360]<<endl;
	F(i,1,n+1)pre[i]=pre[i-1]+(a[i]==mmax);
	a[n+1]=mmax;
	F(i,1,n)lst[i]=(a[i-1]==mmax?i-1:lst[i-1]);
	UF(i,n,1)nxt[i]=(a[i+1]==mmax?i+1:nxt[i+1]);
	F(i,1,n)if(num[i]&&i!=mmax){
		if(num[i]<=sq)AK(i);else IOI(i);
	}
	cout<<ans;
    return 0;
}
/*
10
1 1 1 5 4 1 3 1 2 2
*/