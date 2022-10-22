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
char c[300002];
int n,m,p[300002],sta[300002],cnt,tl[300002],tr[300002],l[300002],r[300002],tot;
int sum[320002],a[320002];ll ans[300002];
const int B=400;
vector<pii>temp,vec[300002];
vector<int>upd[300002],q[300002];
bool vis[300002];
inline ll f(ll x){
	if(x<0)return 0;
	return x*(x+1)>>1;
}
inline void add(int x){
	++sum[x>>8];
	++a[x];
}
inline int query(int x){
	int rt=0;
	while(x&255)rt+=a[x++];
	F(i,x>>8,tot)rt+=sum[i];
	return rt;
}
int main() {
	cin>>n>>m;tot=(n-1)>>8;++tot;
	scanf("%s",c+1);
	F(i,1,m)read(),read(l[i]),read(r[i]),q[r[i]].push_back(i);
	F(i,1,n){
		if(c[i]=='(')sta[++cnt]=i;
		else{
			if(cnt)p[sta[cnt--]]=i;
		}
	}
	F(i,1,n)if(!vis[i]&&c[i]=='('){
		int pos=i;temp.clear();
		while(c[pos]=='('&&p[pos]){
			vis[pos]=true;
			temp.push_back(make_pair(pos,p[pos]));
			pos=p[pos]+1;
		}
		if(temp.size()<=B){
			vec[i]=temp;
			F(j,0,temp.size()-1){
				upd[temp[j].second].push_back(i);
			}
		}else{
			memset(tl,0,sizeof(tl));
			memset(tr,0,sizeof(tr));
			for(pii x:temp){
				tl[x.first+1]++;
				tr[x.second-1]++;
			}
			F(i,1,n)tl[i]+=tl[i-1];UF(i,n,1)tr[i]+=tr[i+1];
			F(i,1,m)ans[i]+=f(temp.size()-tl[l[i]]-tr[r[i]]);
		}
	}
	F(i,1,n){
		for(int j:upd[i]){
			for(pii k:vec[j]){
				if(k.first>i)break;
				add(k.first);
			}
		}
		for(int j:q[i]){
			ans[j]+=query(l[j]);
		}
	}
	F(i,1,m)write(ans[i],'\n');
	return 0;
}