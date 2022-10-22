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
int n;
vector<int>a[202],in[202];
int p[202],res[202],pp[202];
bool flag,vis[202];
inline void orz(int pos,int x){
	if(!p[pos])p[pos]=x;
	else if(p[pos]!=x)flag=false;
}
inline bool check(){
	F(i,2,n){
		int sz=a[i].size();
		for(int j:a[i])if(pp[j]<=p[i]-sz||pp[j]>p[i])return false;
	}
	return true;
}
int main() {
	F(iakioi,1,read()){
		read(n);
		F(i,1,n)a[i].clear(),in[i].clear();
		F(i,2,n){
			F(j,1,read()){
				int x=read();
				a[i].push_back(x);
				in[x].push_back(i);
			}
		}
		F(i,1,n){
			memset(p,0,sizeof(p));
			memset(pp,0,sizeof(pp));
			memset(vis,0,sizeof(vis));
			F(i,1,n)res[i]=in[i].size();
			flag=true;
			for(int j:in[i])orz(j,a[j].size());
			if(!flag)continue;
			pp[i]=1;
			UF(j,n,2){
				F(k,1,n)if(k!=i&&res[k]==1){
					int pos=0;
					for(int p:in[k])if(!vis[p])pos=p;
					vis[pos]=true;
					for(int p:a[pos]){
						--res[p];
					}
					orz(pos,j);
					pp[k]=j;
					break;
				}
				if(!flag)break;
			}
			if(!flag)continue;
			if(check()){
				F(i,1,n)p[pp[i]]=i;
				F(i,1,n)write(p[i],' ');
				puts("");
				break;
			}
		}
	}
	return 0;
}