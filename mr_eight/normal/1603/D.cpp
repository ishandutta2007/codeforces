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
int n=100000,k=17;
int phi[100002],pri[100002],cnt;
ll orz[100002][333],sto[100002][333],tot[100002],f[20][100002];
ll pre[100002];
bool vis[100002];
inline ll c(int l,int r){
	int p=r/(r/l);
	ll qwq;
	if(1ll*p*p<=r)qwq=orz[r][p];
	else qwq=sto[r][r/p];
	return tot[r]-qwq+(p-l+1)*pre[r/l];
}
inline void solve(int t,int l,int r,int ql,int qr){
	if(l>r)return;
	int mid=(l+r)>>1;
	int p=ql;
	ll mmin=f[t-1][ql]+c(ql+1,mid);
	F(i,ql+1,min(qr,mid-1)){
		ll temp=f[t-1][i]+c(i+1,mid);
		if(temp<mmin){
			mmin=temp;
			p=i;
		}
	}
	f[t][mid]=mmin;
	solve(t,l,mid-1,ql,p);
	solve(t,mid+1,r,p,qr);
}
int main() {
	phi[1]=1;
	F(i,2,n){
		if(!vis[i]){
			phi[i]=i-1;
			pri[++cnt]=i;
		}
		for(int j=1,k=i+i;k<=n;k=i*pri[++j]){
			vis[k]=true;
			if(i%pri[j]){
				phi[k]=phi[i]*(pri[j]-1);
			}else{
				phi[k]=phi[i]*pri[j];
				break;
			}
		}
	}
	F(i,1,n)pre[i]=pre[i-1]+phi[i];
	F(i,1,n){
		ll sum=0;
		for(int l=1,r;l<=i;l=r+1){
			r=i/(i/l);
			sum+=(r-l+1)*(pre[i/l]);
			if(1ll*l*l<=i)orz[i][r]=sum;
			else sto[i][i/r]=sum;
		}
		tot[i]=sum;
	}
	/*
	int l,r;
	while(cin>>l>>r){
		cout<<c(l,r)<<endl;
	}
	*/
	memset(f,0x3f,sizeof(f));
	F(i,1,n)f[1][i]=c(1,i);
	F(i,2,k){
		solve(i,i,n,i-1,n-1);
	}
	F(iakioi,1,read()){
		read(n);
		read(k);
		if(k>17)write(n,'\n');
		else write(f[k][n],'\n');
	}
	return 0;
}