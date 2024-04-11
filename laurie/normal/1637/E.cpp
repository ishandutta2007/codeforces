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
		if(x==0) {
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
int n,t[300002],num,m;
vector<int>res[300002];
map<int,int>cnt;
pii ban[600002];
ll ans;
int main() {
	F(iakioi,1,read()) {
		read(n);
		ans=0;
		read(m);
		F(I,1,n)res[I].clear();
		cnt.clear();
		F(i,1,n)++cnt[read()];
		for(auto i:cnt)res[i.second].push_back(i.first);
		num=0;
		F(i,1,n)if(!res[i].empty())reverse(res[i].begin(),res[i].end()),t[++num]=i;
		F(i,1,m) {
			int x=read(),y=read();
			ban[i]=make_pair(x,y);
			ban[i+m]=make_pair(y,x);
		}
		sort(ban+1,ban+m+m+1);
		F(ii,1,num) {
			F(jj,ii+1,num) {
				int x=t[ii],y=t[jj],L=res[y].size()-1;
				ll temp=0;
				F(i,0,res[x].size()-1) {
					F(j,0,L) {
						if(!binary_search(ban+1,ban+m+m+1,make_pair(res[x][i],res[y][j]))) {
							temp=max(temp,(ll)res[x][i]+res[y][j]);
							L=j-1;
							break;
						}
					}
					if(L<0)break;
				}
				ans=max(ans,(x+y)*temp);//cerr<<x<<" "<<y<<" "<<ans<<endl;
			}
		}
		F(x,1,n)if(!res[x].empty()) {
#define y x
			int L=res[y].size()-1;
			ll temp=0;
			F(i,0,res[x].size()-1) {
				F(j,0,L) {
					if(i!=j&&!binary_search(ban+1,ban+m+m+1,make_pair(res[x][i],res[y][j]))) {
						temp=max(temp,(ll)res[x][i]+res[y][j]);
						L=j-1;
						break;
					}
				}
				if(L<0)break;
			}ans=max(ans,(x+x)*temp);
		}
		write(ans,'\n');
	}
	return 0;
}