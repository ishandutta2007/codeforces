#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>

#define pb push_back
#define mp make_pair

using namespace std;

template<typename T>inline void upmin(T &x,T y) { y<x?x=y:0; }
template<typename T>inline void upmax(T &x,T y) { x<y?x=y:0; }

typedef unsigned int u32;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;

const lod pi=acos(-1);
const int oo=1<<30;
const LL OO=1e18;

const int N=1e5+100;

int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}

int w[N];
int p[N];
inline int phi(int n) {
	int ans=n;
	for (int i=2;i<=n;i++)
		if (!(n%i)) {
			ans=ans/i*(i-1);
			while (!(n%i)) n/=i;
		}
	return ans;
}
inline int mul(int x,int y,int mod) {
	return 1LL*x*y>=mod?1LL*x*y%mod+mod:x*y;
}
inline int qpow(int x,int y,int mod) {
	int ans=1;
	while (y) {
		if (y&1) ans=mul(ans,x,mod);
		x=mul(x,x,mod);y>>=1;
	}
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	int n=gi(),i,Q,m,l,r,ans;
	p[0]=gi();
	for (m=0;p[m]!=1;p[m+1]=phi(p[m]),m++);p[m+1]=1;
	for (i=1;i<=n;i++) w[i]=gi();
	Q=gi();
	while (Q--) {
		l=gi(),r=gi();
		ans=1;
		for (i=min(r-l,m);~i;i--)
			ans=qpow(w[i+l],ans,p[i]);
		cout<<ans%p[0]<<endl;
	}
	return 0;
}