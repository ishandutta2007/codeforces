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
const int MAXN=2000005,MAXM=4000005;
int head[MAXN],nxt[MAXM],n,m,to[MAXM],x,y,deg[MAXN],sta[MAXM],cnt,b[MAXN],c[MAXN],t[MAXN];
bool vis[MAXM>>1];
inline void dfs(int pos){
	for(int &e=head[pos];e;e=nxt[e]){
		if(vis[e>>1])continue;
		int temp=e;
		vis[e>>1]=1;
		dfs(to[e]);
		sta[++cnt]=to[temp];
	}
}
vector<int>vec;
int main() {
	cin>>n;
	F(i,1,n-1)read(b[i]);
	F(i,1,n-1){
		read(c[i]);
		if(c[i]<b[i]){
			puts("-1");
			return 0;
		}
		t[i]=b[i];
		t[i+n-1]=c[i];
	}
	sort(t+1,t+n+n-1);
	F(i,1,n-1){
		x=lower_bound(t+1,t+n+n-1,b[i])-t;
		y=lower_bound(t+1,t+n+n-1,c[i])-t;
		++deg[x],++deg[y];
		to[i<<1]=y;
		nxt[i<<1]=head[x];
		head[x]=(i<<1);
		to[i<<1|1]=x;
		nxt[i<<1|1]=head[y];
		head[y]=(i<<1|1);
	}
	F(i,1,n+n){
		if(deg[i]&1){
			vec.push_back(i);
		}
	}
	int S;
	if(vec.size()>2){
		puts("-1");return 0;
	}
	else if(vec.size()==2){
		S=vec[0];//cerr<<t[vec[0]]<<" "<<t[vec[1]]<<endl;
		dfs(vec[0]);
	}else{
		F(i,1,n+n-2)if(deg[i]){
			S=i;
			dfs(i);
			break;
		}
	}
	if(cnt!=n-1)cout<<"-1";
	else{
		write(t[S],' ');
		UF(i,n-1,1){
			write(t[sta[i]],' ');
		}
	}
	return 0;
}