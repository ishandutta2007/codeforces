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
ll n,k,m,f[202];
vector<string>pre[202],suf[202];
string ans;
int main(){
	cin>>n>>k>>m;
	pre[0].push_back("");pre[0].push_back("0");
	suf[0].push_back("");suf[0].push_back("0");
	pre[1].push_back("");pre[1].push_back("1");
	suf[1].push_back("");suf[1].push_back("1");
	f[0]=f[1]=1;
	F(i,2,n)f[i]=min(1000000000000000000ll,f[i-1]+f[i-2]);
	F(i,2,n){
		pre[i]=pre[i-2];
		while(pre[i].size()<=min(m,f[i]))pre[i].push_back(pre[i-2].back()+pre[i-1][pre[i].size()-f[i-2]]);
		suf[i]=suf[i-1];
		while(suf[i].size()<=min(m,f[i]))suf[i].push_back(suf[i-2][suf[i].size()-f[i-1]]+suf[i-1].back());
	}++k;
	F(i,1,m){
		k-=(suf[n].size()>=i&&suf[n][i-1]==ans);
		if(!k){
			cout<<ans;
			return 0;
		}
		ans.push_back('0');
		f[0]=(ans=="0"),f[1]=(ans=="1");
		F(qwq,2,n){
			f[qwq]=f[qwq-1]+f[qwq-2];
			F(j,1,i-1)f[qwq]+=(suf[qwq-2].size()>j&&pre[qwq-1].size()>i-j&&suf[qwq-2][j]+pre[qwq-1][i-j]==ans);
			f[qwq]=min(1000000000000000001ll,f[qwq]);
		}
		ll temp=f[n];
		if(temp<k)ans.back()='1',k-=temp;
	}
	cout<<ans;
    return 0;
}
/*
01101
*/