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
#define rep F
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
using namespace std;
template<typename T> void read(T &num) {
	char c=getchar();
	T f=1;
	num=0;
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		num=(num<<3)+(num<<1)+(c^48);
		c=getchar();
	}
	num*=f;
}
template<typename T> void qaq(T x) {
	if(x>9)qaq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x) {
	if(x<0) {
		x=-x;
		putchar('-');
	}
	qaq(x);
	putchar('\n');
}
template<typename T> void chkmax(T &x,T y) {
	x=x>y?x:y;
}
int len1,len2,len3,n,v;
int dp[200010];
int T[200010];
int a[200010];
int A[200010];
long long p1[200010];
long long p2[200010];
long long P1[200010];
long long P2[200010];
pii qwq[200002],V[200002];
namespace cdq {
	namespace T {
		int c[200002];
		inline void add(int pos,int v) {
			while(pos<=n) {
				c[pos]=max(c[pos],v);
				pos+=(-pos&pos);
			}
		}
		inline int query(int pos) {
			int rt=-1e9;
			while(pos) {
				rt=max(rt,c[pos]);
				pos-=(-pos&pos);
			}
			return rt;
		}
		inline void cl(int pos) {
			while(pos<=n)c[pos]=-1e9,pos+=(-pos&pos);
		}
	} using namespace T;
	inline void solve(int l,int r){
		if(l==r){
		//	cerr<<l<<" "<<p1[l]<<" "<<p2[l]<<" "<<a[l]<<" "<<dp[l]<<endl;
			return;
		}
		int mid=(l+r)>>1;
		solve(l,mid);
		memcpy(qwq+l,V+l,(r-l+1)<<3);//if(l==2&&r==3)cerr<<V[3].second<<"K"<<endl;
		sort(qwq+l,qwq+mid+1);
		sort(qwq+mid+1,qwq+r+1);
		int pos=l;
		F(i,mid+1,r){
			while(pos<=mid&&qwq[pos].first<=qwq[i].first)add(p1[qwq[pos].second],dp[qwq[pos].second]),++pos;
			dp[qwq[i].second]=max(dp[qwq[i].second],query(p1[qwq[i].second])+1);
		}
		F(i,l,mid)cl(p1[qwq[i].second]);
		pos=mid;
		UF(i,r,mid+1){
			while(pos>=l&&qwq[pos].first>=qwq[i].first)add(p2[qwq[pos].second],dp[qwq[pos].second]),--pos;
			dp[qwq[i].second]=max(dp[qwq[i].second],query(p2[qwq[i].second])+1);//cerr<<l<<" "<<r<<" "<<i<<" "<<qwq[i].second<<endl;
		}
		F(i,l,mid)cl(p2[qwq[i].second]);
		solve(mid+1,r);
	}
}
int main() {//freopen("L.in","r",stdin);
	read(n);
	read(v);
	rep(i,1,n)read(T[i]);
	rep(i,1,n)read(a[i]);

	len1=0;
	len2=0;
	len3=0;
	rep(i,0,n) {
		p1[i]=a[i]+1ll*v*T[i];
		p2[i]=1ll*v*T[i]-a[i];
		P1[++len1]=p1[i];
		P2[++len2]=p2[i];
		A[++len3]=a[i];
	}
	sort(P1+1,P1+len1+1);
	sort(P2+1,P2+len2+1);
	sort(A+1,A+len3+1);
	len1=unique(P1+1,P1+len1+1)-P1-1;
	len2=unique(P2+1,P2+len2+1)-P2-1;
	len3=unique(A+1,A+len3+1)-A-1;
	rep(i,0,n) {
		p1[i]=lower_bound(P1+1,P1+len1+1,p1[i])-P1;
		p2[i]=lower_bound(P2+1,P2+len2+1,p2[i])-P2;
		a[i]=lower_bound(A+1,A+len3+1,a[i])-A;
	}
	++n;memset(cdq::T::c,-0x3f,sizeof(cdq::T::c));F(i,0,n-1)a[i]=n-a[i]+1;
	dp[0]=0;F(i,0,n-1)qwq[i]={a[i],i};memcpy(V,qwq,sizeof(V));
	F(i,1,n-1)dp[i]=-1e9;
	cdq::solve(0,n-1);
	/*
	rep(i,1,n) {
		rep(j,0,i-1) {
			if(a[i]<=a[j]) {
				if(p1[j]<=p1[i])chkmax(dp[i],dp[j]+1);
			}
			if(a[i]>=a[j]) {***
				if(p2[j]<=p2[i])chkmax(dp[i],dp[j]+1);
			}
		}
	}*/
	int ans=0;
	rep(i,1,n-1)chkmax(ans,dp[i]);
	write(ans);
//	F(i,0,n)cerr<<cdq::T::c[i]<<endl;
	return 0;
}