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
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
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
int k,n;
inline pii operator-(pii x,pii y){
	return {x.first-y.first,x.second-y.second};
}
inline pii cut(pii x){
	int g=__gcd(abs(x.first),abs(x.second));
	x.first/=g;
	x.second/=g;
	return x;
}
pii O;
int p[1002];
pii a[10],b[1002];
inline bool cmp(int x,int y){
	return cut(b[x]-O)==cut(b[y]-O)?abs((b[x]-O).first)+abs((b[x]-O).second)<abs((b[y]-O).first)+abs((b[y]-O).second):cut(b[x]-O)<cut(b[y]-O);
}
vector<int>pre[10][1002];
inline vector<int>merge(vector<int>x,vector<int>y,int era){
	vector<int>res;
	auto a=x.begin(),b=y.begin();
	while(a!=x.end()&&b!=y.end()){
		if(*a<*b){
			if(*a!=era)res.push_back(*a);
			++a;
		}else if(*a>*b){
			res.push_back(*b);
			++b;
		}else{
			res.push_back(*a);
			++a;++b;
		}
	}
	while(a!=x.end()){
		if(*a!=era)res.push_back(*a);
		++a;
	}
	while(b!=y.end()){
		res.push_back(*b);
		++b;
	}
	return res;
}
inline bool check(int res,vector<int>tar){
	if(tar.empty())return true;
	if(__builtin_popcount(res)<tar.size())return false;
	F(i,1,k)if(res>>i&1){
		for(auto j=tar.begin();j!=tar.end();++j){
			if(check(res^(1<<i),merge(tar,pre[i][*j],*j)))return true;
		}//if(tar[0]==3)cerr<<'k';
	}
	return false;
}
int main() {
	cin>>k>>n;
	F(i,1,k)read(a[i].first,a[i].second);
	F(i,1,n)read(b[i].first,b[i].second),p[i]=i;
	F(i,1,k){
		O=a[i];
		sort(p+1,p+n+1,cmp);
		F(j,2,n){
			if(cut(b[p[j]]-O)==cut(b[p[j-1]]-O)){
				pre[i][p[j]]=pre[i][p[j-1]];
				pre[i][p[j]].push_back(p[j-1]);
			}
		}
		F(j,1,n){
			if(pre[i][j].size()>1)sort(pre[i][j].begin(),pre[i][j].end());
		}
	}
	int ans=0;
	F(i,1,n)ans+=check((1<<k)-1<<1,{i});
	cout<<ans;
	//cerr<<endl;for(auto i:pre[1][3])cerr<<i<<" ";
	return 0;
}