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
char s[200002],t[200002];
int n;
ll ans;
int c[200002];
stack<int>sta[1002];
inline void add(int pos,int v){
	while(pos<=n){
		c[pos]+=v;
		pos+=(-pos&pos);
	}
}
inline int query(int pos){
	int rt=0;
	while(pos){
		rt+=c[pos];
		pos-=(-pos&pos);
	}
	return rt;
}
int main() {
	F(iakioi,1,read()){
		memset(c,0,sizeof(c));
		F(i,'a','z')sta[i]=stack<int>();
		read(n);ans=LLONG_MAX;
		F(i,1,n)add(i,1);
		scanf("%s",s+1);
		scanf("%s",t+1);bool flag=false;
		F(i,1,n){
			if(s[i]<t[i]){
				flag=true;
				puts("0");
				break;
			}else if(s[i]>t[i])break;
		}
		if(flag)continue;
		ll now=0;
		int pos=0;
		UF(i,n,1){
			sta[s[i]].push(i);
		}
		F(iakioi,1,n){
			int i=998244353;
			F(ii,'a','z')if(!sta[ii].empty())i=min(i,sta[ii].top());
			int qi=++pos;
			if(s[i]<t[pos]){
				ans=min(ans,now);
				break;
			}else if(s[i]==t[pos]){
				F(j,'a',t[pos]-1){
					if(!sta[j].empty())ans=min(ans,now+query(sta[j].top())-qi);
				}
				sta[s[i]].pop();
			}else{
				F(j,'a',t[pos]-1){
					if(!sta[j].empty())ans=min(ans,now+query(sta[j].top())-qi);
				}
				if(sta[t[pos]].empty())break;
				now+=query(sta[t[pos]].top())-qi;
				int xx=sta[t[pos]].top();
				sta[t[pos]].pop();
				add(1,1);
				add(xx,-1);
			}
		}
		if(ans<1e12)write(ans,'\n');
		else puts("-1");
	}
	return 0;
}