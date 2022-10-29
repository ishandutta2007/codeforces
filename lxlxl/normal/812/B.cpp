#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 110;
const int maxm = 1100;

int n,m;
int v[maxn][maxm];
char str[maxm];
int f[maxn][2];
int suf[maxn];

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=n;i>=1;i--)
	{
		scanf("%s",str);
		for(int j=1;j<=m;j++) v[i][j]=str[j]-'0';
		for(int j=1;j<=m;j++) if(v[i][j]) suf[i]++;
		suf[i]+=suf[i+1];
	}
	if(n==1||suf[2]==0)
	{
		int k=0; for(int j=1;j<=m;j++) if(v[1][j]) k=j;
		printf("%d\n",k);
		return 0;
	}
	for(int i=1;i<=m;i++) if(v[1][i]) f[2][0]=i;
	f[2][0]=f[2][0]*2+1; f[2][1]=m+1+1;
	for(int i=2;i<n;i++)
	{
		if(suf[i+1]==0) { n=i; break; }
		int li=0,ri=0;
		for(int j=1;j<=m;j++) if(v[i][j])
		{
			if(!li) li=j;
			ri=j;
		}
		if(!li) li=m+1;
		f[i+1][0]=1+min(f[i][0]+ri*2,f[i][1]+m+1);
		f[i+1][1]=1+min(f[i][0]+m+1,f[i][1]+(m+1-li)*2);
	}
	int li=0,ri=0;
	for(int j=1;j<=m;j++) if(v[n][j])
	{
		if(!li) li=j;
		ri=j;
	}
	if(!li) li=m+1;
	printf("%d\n",min(f[n][0]+ri,f[n][1]+m+1-li));
	
	return 0;
}