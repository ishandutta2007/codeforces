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
#include <random>
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
int n,id[3002],sta[3002],cnt,tot,d[3002];
bool ins[3002],orz[3002],flag;
vector<int>g[3002];
long double ans,ans2;
inline void dfs(int pos,int lst){
	if(ins[pos]){
		flag=true;
		orz[pos]=true;
		id[pos]=tot=1;
		while(sta[cnt]!=pos){
			orz[sta[cnt]]=true;
			id[sta[cnt--]]=++tot;
		}
	}
	ins[pos]=true,sta[++cnt]=pos;
	for(int i:g[pos])if(i!=lst){
		if(flag)return;
		dfs(i,pos);
	}
	ins[pos]=false,--cnt;
}
inline void dfs(int pos){
	for(int i:g[pos])if(!id[i]){
		id[i]=id[pos];
		d[i]=d[pos]+1;
		dfs(i);
	}
}
inline void ak(int pos,int lst,int now){
	ans+=1.0L/now;
	for(int i:g[pos])if(id[i]==id[pos]&&i!=lst)ak(i,pos,now+1);
}
int main(){
	cin>>n;
	F(i,1,n){
		int x=read()+1,y=read()+1;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	F(i,1,n)if(orz[i])d[i]=1,dfs(i);
	F(i,1,n)ak(i,0,1);
	F(i,1,n)F(j,1,n)if(id[i]<id[j]){
		ans2+=1.0L/(d[i]+d[j]+id[j]-id[i]-1)+1.0L/(d[i]+d[j]+id[i]-1+tot-id[j])-1.0L/(d[i]+d[j]+tot-2);
	}
	cout<<fixed<<setprecision(15)<<ans+ans2*2;
    return 0;
}