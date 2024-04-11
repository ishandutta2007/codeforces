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
#include <random>
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
int n,r[300002],sta[2][300002],cnt[2];
ll a[300003],ans;
map<ll,vector<int> >mp[2];
inline void ins(int *sta,int &cnt,int x){
	while(cnt){
		if(a[x]<=a[sta[cnt]])--cnt;
		else break;
	}
	sta[++cnt]=x;
}
inline bool cmp(int x,int y){
	return a[x]<a[y];
}
int main() {
	F(iakioi,1,read()){
		mp[0].clear();mp[1].clear();
		read(n);cnt[0]=cnt[1]=1;sta[0][1]=sta[1][1]=n+1;a[n+1]=-LLONG_MAX;
		F(i,1,n)read(a[i]);
		F(i,1,n)a[i]-=a[i-1];
		F(i,1,n)mp[!(i&1)][a[i]].push_back(i);//,cerr<<(!(i&1))<<' '<<a[i]<<" "<<i<<endl;
		UF(i,n,1){
			ins(sta[!(i&1)],cnt[!(i&1)],i);a[n+2]=-a[i-1];
		//	F(x,1,cnt[0])cerr<<sta[0][x]<<"k";cerr<<endl;
		//	F(x,1,cnt[1])cerr<<sta[1][x]<<"k";cerr<<endl;
			int p=min(*(lower_bound(sta[i&1]+1,sta[i&1]+cnt[i&1]+1,i-1,cmp)-1),*(lower_bound(sta[!(i&1)]+1,sta[!(i&1)]+cnt[!(i&1)]+1,n+2,cmp)-1));
			--p;//cerr<<i<<' '<<p<<endl;
			auto qwq=mp[i&1][a[i-1]].begin(),qaq=mp[i&1][a[i-1]].end();
			if(qwq!=qaq)ans+=upper_bound(qwq,qaq,p)-lower_bound(qwq,qaq,i);
			qwq=mp[!(i&1)][a[n+2]].begin(),qaq=mp[!(i&1)][a[n+2]].end();
			if(qwq!=qaq)ans+=upper_bound(qwq,qaq,p)-lower_bound(qwq,qaq,i);
			//cerr<<i<<" "<<p<<" "<<ans<<endl;
		}
		write(ans,'\n');ans=0;
	}
	return 0;
}