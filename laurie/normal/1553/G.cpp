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
int n,q,a[150002],qwq[1000002],qaq[1000002],f[150002],to[1000002];
vector<int>ak[150002],ioi[150002];
bool tag[1000002],pri[1000002];
#include<tr1/unordered_map>
tr1::unordered_map<ll,bool>mp;
inline int findf(int x){
	return (f[x]==x)?x:(f[x]=findf(f[x]));
}
inline void merge(int x,int y){
	if(!y||findf(x)==findf(y))return;
	f[f[x]]=f[y];
}
inline void ins(int x,int y){
	if(x>y)swap(x,y);
	mp[x*1919810ll+y]=1;
}
inline bool query(int x,int y){
	if(x>y)swap(x,y);
	return mp.count(x*1919810ll+y);
}
int main() {
	cin>>n>>q;
	F(i,1,n)f[i]=i;
	F(i,1,n)read(a[i]),qwq[a[i]]=i,qaq[a[i]+1]=i;
	F(i,2,1000001){
		if(!tag[i]){
			pri[i]=1;
			int lst=0;
			for(ri j=i;j<=1000001;j+=i){
				tag[j]=1;
				if(qwq[j]){
					ak[qwq[j]].push_back(i);
					merge(qwq[j],lst);
					to[i]=f[f[qwq[j]]];
					lst=qwq[j];
				}
				if(qaq[j])ioi[qaq[j]].push_back(i);
			}
		}
	}
	F(i,1,n)findf(i);
	F(i,1,n){
		for(auto j:ioi[i])if(to[j])ins(f[to[j]],f[i]);
		F(j,0,ioi[i].size()-1){
			F(k,j+1,ioi[i].size()-1){
				if(to[ioi[i][j]]&&to[ioi[i][k]]){
					ins(f[to[ioi[i][j]]],f[to[ioi[i][k]]]);
				}
			}
		}
	}
	F(i,1,q){
		int s,t;
		read(s);read(t);
		if(f[s]==f[t])puts("0");
		else if(query(f[s],f[t]))puts("1");
		else puts("2");
	}
	return 0;
}