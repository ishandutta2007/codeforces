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
#define ld long double
#define inf 1e12
using namespace std;

const int maxn = 1100;
const ld eps = 1e-9;

int n;
int a[maxn],cnt,ok[maxn];
ld p[maxn][maxn],f[maxn],nowp[maxn];

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
	{
		int x; scanf("%d",&x);
		p[i][j]=(ld)x/100;
	}
	
	f[a[cnt=1]=n]=0,ok[n]=1;
	for(int i=1;i<=n;i++) nowp[i]=1;
	while(cnt<n)
	{
		int las=a[cnt];
		for(int i=1;i<=n;i++) if(!ok[i])
		{
			f[i]+=nowp[i]*p[i][las]*(f[las]+1);
			nowp[i]*=(1-p[i][las]);
		}
		ld mn; int mni=-1;
		for(int i=1;i<=n;i++) if(!ok[i])
		{
			ld tmp=fabs(nowp[i]-1)<eps?inf:(f[i]+nowp[i])/(1-nowp[i]);
			if(mni==-1||mn>tmp) mn=tmp,mni=i;
		}
		ok[a[++cnt]=mni]=1;
		f[mni]=(f[mni]+nowp[mni])/(1-nowp[mni]);
	}
	printf("%.9Lf\n",f[1]);
	
	return 0;
}