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
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MOD=1000000007;

int n,m,k;
int C[210][210];
int F[52][104][52][104];

void add(int &x,int y)
{
	x+=y;
	if (x>=MOD) x-=MOD;
}

int main()
{
	cin>>n>>m>>k;
	for (int i=0;i<=200;++i)
		C[i][0]=1;
	for (int i=1;i<=200;++i)
		for (int j=1;j<=i;++j)
			C[i][j]=min(C[i-1][j-1]+C[i-1][j],200);
	for (int i=2;i<=n;i+=2)
		F[2][i][i/2][1]=1;
	int ans=0;
	for (int i=2;i<=n/2+1&&i<=m;++i)
		for (int j=1;j<=n;++j)
			for (int x=1;x<=n/2;++x)
				for (int w=1;w<=k;++w)
				{
					int tF=F[i][j][x][w];
					if (!tF) continue;
					add(ans,(ll)tF*(m-i+1)%MOD);
					for (int y=1;j+2*y<=n;++y)
					{
						int v=w*C[x+y-1][y];
						if (!v||v>k) continue;
						add(F[i+1][j+2*y][y][v],tF);
					}
				}
	cout<<ans<<endl;
	return 0;
}