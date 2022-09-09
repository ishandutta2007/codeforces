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
#define mod 1000000007
int n,a[200002],p[200002],cnt,f[200002],g[200002],t[200002],qwq[200002];
vector<int>vec;ll ans;
struct BIT{
ll c[200002];
inline void add(int pos,int v){
	while(pos<=n){
		c[pos]+=v;
		pos+=(-pos&pos);
	}
}
inline void add(int l,int r,int v){
	add(l,v);
	add(r+1,-v);
}
inline ll query(int pos){
	ll rt=0;
	while(pos){
		rt+=c[pos];
		pos-=(-pos&pos);
	}
	return rt;
}
}A,B;
int main(){
	F(iakioi,1,read()){
		read(n);cnt=ans=0;
		F(i,1,n)read(a[i]),t[i]=a[i],A.c[i]=B.c[i]=0;
		sort(t+1,t+n+1);
		F(i,1,n)++t[a[i]=upper_bound(t+1,t+n+1,a[i])-1-t];
		F(i,1,n)qwq[a[i]]=i;
		F(i,1,n){
			f[i]=(A.query(a[i]-1)+1)%mod;
			A.add(a[i],f[i]);
		}
		UF(i,n,1){
			g[i]=(B.query(n)-B.query(a[i])+1)%mod;
			B.add(a[i],g[i]);
			
		}
		F(i,1,n)B.c[i]=0;
		int mmax=0;
		UF(i,n,1){
			if(a[i]>mmax){
				mmax=a[i];
				p[++cnt]=i;
			}else ans+=1ll*f[i]*g[i]%mod;
		}
		F(i,1,cnt){
			vec.clear();
			F(j,a[p[i-1]]+1,a[p[i]]-1){
				vec.push_back(qwq[j]);
			}
			if(!vec.empty())sort(vec.begin(),vec.end()),reverse(vec.begin(),vec.end());
			for(int k:vec){
				g[k]=(B.query(n)-B.query(a[k])+1)%mod;
				B.add(a[k],g[k]);
				ans-=1ll*f[k]*g[k]%mod;//cerr<<f[k]<<" "<<g[k]<<endl;
			}
			for(int k:vec)B.add(a[k],-g[k]);
		}
		write((ans%mod+mod)%mod,'\n');
	}
    return 0;
}