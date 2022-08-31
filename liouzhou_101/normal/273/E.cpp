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

/*
const int MaxN=1000000001;

bitset<MaxN> F,G;

int main()
{
	freopen("try.in","r",stdin);
	freopen("try.out","w",stdout);
	printf("{%d,%d},\n",0,1);
	int pre=0;
	for (int k=3;k<MaxN;++k)
	{
		int x=k/3;
		int y=k-x;
		x=F[x]|G[x]<<1;
		y=F[y]|G[y]<<1;
		if (x!=0&&y!=0) x=0;
		else if (x!=1&&y!=1) x=1;
		else x=2;
		F[k]=x&1;
		G[k]=x&2;
		if (x!=pre)
		{
			printf("{%d,%d},\n",x,k);
			pre=x;
		}
	}
	return 0;
}
*/

int v[][2]=
{
{0,1},
{1,3},
{2,4},
{1,5},
{2,7},
{0,9},
{1,13},
{2,15},
{0,19},
{1,27},
{2,39},
{0,40},
{2,57},
{1,58},
{2,81},
{0,85},
{2,120},
{1,121},
{2,174},
{0,179},
{2,255},
{1,260},
{2,363},
{0,382},
{2,537},
{1,544},
{2,780},
{0,805},
{2,1146},
{1,1169},
{2,1632},
{0,1718},
{2,2415},
{1,2447},
{2,3507},
{0,3622},
{2,5154},
{1,5260},
{2,7341},
{0,7730},
{2,10866},
{1,11011},
{2,15780},
{0,16298},
{2,23190},
{1,23669},
{2,33033},
{0,34784},
{2,48894},
{1,49549},
{2,71007},
{0,73340},
{2,104352},
{1,106510},
{2,148647},
{0,156527},
{2,220020},
{1,222970},
{2,319530},
{0,330029},
{2,469581},
{1,479294},
{2,668910},
{0,704371},
{2,990087},
{1,1003364},
{2,1437882},
{0,1485130},
{2,2113113},
{1,2156822},
{2,3010092},
{0,3169669},
{2,4455390},
{1,4515137},
{2,6470466},
{0,6683084},
{2,9509007},
{1,9705698},
{2,13545411},
{0,14263510},
{2,20049252},
{1,20318116},
{2,29117094},
{0,30073877},
{2,42790530},
{1,43675640},
{2,60954348},
{0,64185794},
{2,90221631},
{1,91431521},
{2,131026920},
{0,135332446},
{2,192557382},
{1,196540379},
{2,274294563},
{0,288836072},
{2,405997338},
{1,411441844},
{2,589621137},
{0,608996006},
{2,866508216},
{1,884431705},
{0,1000000001}
};

const int MaxN=1010;
const int MOD=1000000007;

int n,p;
ll a[4];
ll F[MaxN][4];

int main()
{
	cin>>n>>p;
	for (int i=0;v[i][1]<=p;++i)
	{
		int L=v[i][1];
		int R=min(v[i+1][1]-1,p);
		(a[v[i][0]]+=(ll)(2*p-L-R)*(R-L+1)/2)%=MOD;
	}
	F[0][0]=1;
	for (int i=1;i<=n;++i)
		for (int j=0;j<4;++j)
			for (int k=0;k<4;++k)
				(F[i][j^k]+=F[i-1][j]*a[k])%=MOD;
	cout<<(F[n][1]+F[n][2]+F[n][3])%MOD<<endl;
	return 0;
}