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
int n,c[200002],o[200002],temp[200002],t[200002];
vector<int>p[800002];
vector<ll>prec[800002],prer[800002];
#define mid ((l+r)>>1)
inline bool cmp(int x,int y){
	return t[x]<t[y];
}
inline ll calc(int pos,int t){
	int x=lower_bound(p[pos].begin(),p[pos].end(),t)-p[pos].begin();
	return (prer[pos].back()-prer[pos][x])*t+prec[pos][x];
}
inline void build(int pos,int l,int r){
	F(i,l,r)temp[i]=i;
	sort(temp+l,temp+r+1,cmp);
	prec[pos].push_back(0);
	prer[pos].push_back(0);
	F(ii,l,r){
		int i=temp[ii];
		p[pos].push_back(t[i]);
		prec[pos].push_back(prec[pos].back()+c[i]);
		prer[pos].push_back(prer[pos].back()+o[i]);
	}
	if(l!=r)build(pos<<1,l,mid),build(pos<<1|1,mid+1,r);
}
ll lst,k;
inline void solve(int pos,int l,int r,int ql,int qr,int t,ll &h){
	if(!h)return;
	if(ql<=l&&qr>=r){
		ll temp=calc(pos,t);
		if(temp<h)h-=temp;
		else{
			if(l==r){
				lst=l;
				k=temp-h;
				h=0;
				return;
			}
			solve(pos<<1,l,mid,ql,qr,t,h);
			if(h)solve(pos<<1|1,mid+1,r,ql,qr,t,h);
		}
		return;
	}
	if(ql<=mid)solve(pos<<1,l,mid,ql,qr,t,h);
	if(h&&qr>mid)solve(pos<<1|1,mid+1,r,ql,qr,t,h);
}
struct S{
	int l,r;
	ll lst,rm;
};
vector<S>sta;
ll ans;
inline void play(int t,ll h){
	lst=k=0;
	while(sta.size()>1){
		S temp=sta.back();sta.pop_back();
		if(temp.rm){
			ll v=1ll*(t-temp.lst)*o[temp.l]+temp.rm;
			v=min(v,(ll)c[temp.l]);
			if(v>=h){
				sta.push_back({temp.l,temp.l,t,v-h});
				h=0;
				break;
			}
			h-=v;
		}else{
			solve(1,1,n,temp.l,temp.r,t-temp.lst,h);
			if(lst){
				if(lst!=temp.r)sta.push_back({lst+1,temp.r,temp.lst,0});
				sta.push_back({lst,lst,t,k});
				break;
			}
		}
	}//cerr<<h<<endl;
	ans+=h;
}
int main() {
	cin>>n;
	F(i,1,n)read(c[i],o[i]),t[i]=c[i]/o[i];
	build(1,1,n);//cerr<<calc(1,2)<<endl;
	sta.push_back({n+1,0,0,0});
	sta.push_back({1,n,-1000000000,0});
	F(i,1,read()){
		ll t=read(),h;
		read(h);
		play(t,h);
		if(sta.back().l!=1)sta.push_back({1,sta.back().l-1,t,0});
	//	for(auto i:sta)cerr<<i.l<<" "<<i.r<<" "<<i.lst<<" "<<i.rm<<endl;cerr<<endl;
	}
	cout<<ans;
	return 0;
}