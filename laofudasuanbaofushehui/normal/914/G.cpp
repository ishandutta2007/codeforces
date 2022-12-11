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

const int N=1<<17;
const int mod=1e9+7;
const int inv2=(mod+1)>>1;

int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}

int a[1<<17][18],p[18];
int c[1<<17];
int tot[1<<17];

int A[N],B[N],C[N],fib[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	int n=gi(),s,i,j,k,x,y;
	for (i=2,fib[0]=0,fib[1]=1;i<N;i++) fib[i]=(fib[i-1]+fib[i-2])%mod;
	while (n--) tot[gi()]++;

	for (s=0;s<1<<17;s++)
		a[s][__builtin_popcount(s)]=tot[s];
	for (k=0;k<17;k++)
		for (s=0;s<1<<17;s++)
			if (!(s>>k&1))
				for (i=0;i<=17;i++)
					(a[s|1<<k][i]+=a[s][i])%=mod;
	for (s=0;s<1<<17;s++) {
		for (i=0;i<=17;i++) p[i]=a[s][i],a[s][i]=0;
		for (i=0;i<=17;i++)
			for (j=0;i+j<=17;j++)
				a[s][i+j]=(a[s][i+j]+1LL*p[i]*p[j])%mod;
	}
	for (k=0;k<17;k++)
		for (s=0;s<1<<17;s++)
			if (!(s>>k&1))
				for (i=0;i<=17;i++)
					(a[s|1<<k][i]-=a[s][i])%=mod;
	for (s=0;s<1<<17;s++)
		A[s]=1LL*fib[s]*a[s][__builtin_popcount(s)]%mod;

	for (s=0;s<1<<17;s++)
		B[s]=1LL*tot[s]*fib[s]%mod;

	for (s=0;s<1<<17;s++)
		c[s]=tot[s];
	for (k=0;k<17;k++)
		for (s=0;s<1<<17;s++)
			if (!(s>>k&1)) {
				x=c[s],y=c[s|1<<k];
				c[s]=(x+y)%mod;
				c[s|1<<k]=(x-y)%mod;
			}
	for (s=0;s<1<<17;s++)
		c[s]=1LL*c[s]*c[s]%mod;
	for (k=0;k<17;k++)
		for (s=0;s<1<<17;s++)
			if (!(s>>k&1)) {
				x=c[s],y=c[s|1<<k];
				c[s]=1LL*(x+y)*inv2%mod;
				c[s|1<<k]=1LL*(x-y)*inv2%mod;
			}
	for (s=0;s<1<<17;s++)
		C[s]=1LL*c[s]*fib[s]%mod;

	for (k=0;k<17;k++)
		for (s=0;s<1<<17;s++)
			if (!(s>>k&1)) {
				(A[s]+=A[s|1<<k])%=mod;
				(B[s]+=B[s|1<<k])%=mod;
				(C[s]+=C[s|1<<k])%=mod;
			}
	for (s=0;s<1<<17;s++)
		A[s]=1LL*A[s]*B[s]%mod*C[s]%mod;
	for (k=0;k<17;k++)
		for (s=0;s<1<<17;s++)
			if (!(s>>k&1)) {
				(A[s]-=A[s|1<<k])%=mod;
			}
	int ans=0;
	for (i=0;i<17;i++)
		(ans+=A[1<<i])%=mod;
	cout<<(ans+mod)%mod<<endl;
	return 0;
}