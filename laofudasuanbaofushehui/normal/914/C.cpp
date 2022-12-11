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

int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}

inline int F(int x) {
	int ans=0;
	while (x!=1)
		x=__builtin_popcount(x),ans++;
	return ans;
}
int f[1010];
int g[1010][1010][2];
char n[1010];
const int mod=1e9+7;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	for (int i=1;i<=1000;i++)
		f[i]=F(i);
	scanf("%s",n+1);int len=strlen(n+1),Q=gi();
	reverse(n+1,n+1+len);
	if (!Q) return puts("1"),0;
	g[len][0][1]=1;
	for (int i=len;i;i--)
		for (int j=0;j<=len;j++)
			for (int k=0;k<2;k++)
				for (int t=0;t<2;t++) {
					if (k&&t>n[i]-'0')
						continue;
					(g[i-1][j+t][k&&t==n[i]-'0']+=g[i][j][k])%=mod;
				}
	int ans=Q==1?-1:0;
	for (int i=1;i<=len;i++)
		if (f[i]+1==Q)
			ans=((LL)ans+g[0][i][0]+g[0][i][1])%mod;
	cout<<ans<<endl;
	return 0;
}