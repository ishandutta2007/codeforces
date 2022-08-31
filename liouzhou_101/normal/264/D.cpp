#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=1000010;

int n,m;
char s[MaxN],t[MaxN];
int F[3][3][MaxN];

int main()
{
	scanf("%s%s",s+1,t+1);
	ll ans=0;
	n=strlen(s+1);
	m=strlen(t+1);
	for (int i=1;i<=n;++i)
	{
		if (s[i]=='R') s[i]=0;
		if (s[i]=='G') s[i]=1;
		if (s[i]=='B') s[i]=2;
	}
	for (int i=1;i<=m;++i)
	{
		if (t[i]=='R') t[i]=0;
		if (t[i]=='G') t[i]=1;
		if (t[i]=='B') t[i]=2;
	}
	for (int i=1;i<=m;++i)
		for (int x=0;x<3;++x)
			for (int y=0;y<3;++y)
			{
				F[x][y][i]=F[x][y][i-1];
				if (i>1&&t[i-1]==x&&t[i]==y) F[x][y][i]++;
			}
	for (int i=1,L=1,R=1;i<=n;++i)
	{
		while (R<m&&t[R]!=s[i]) ++R;
		ans+=R-L+1;
		int x=s[i-1],y=s[i];
		if (i>1)
		{
			x=s[i-1],y=s[i];
			if (x!=y)
			ans-=F[y][x][R]-F[y][x][L];
		}
		//cout<<L<<" "<<R<<" "<<F[y][x][R]-F[y][x][L]<<endl;
		if (s[i]==t[L])
		{
			++L;
			if (L>m) break;
		}
		++R;
		R=min(R,m);
	}
	cout<<ans<<endl;
	return 0;
}