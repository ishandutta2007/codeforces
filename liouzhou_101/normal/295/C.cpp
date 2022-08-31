#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
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

const int MaxN=52;
const int MOD=1000000007;

int n,k;
int nx,ny;
int F[MaxN][MaxN][2];
ll G[MaxN][MaxN][2];
queue<pair<pii,int> > Q;
ll C[MaxN][MaxN];

int main()
{
	cin>>n>>k;
	for (int i=0;i<=n;++i)
		C[i][0]=1;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	for (int i=1;i<=n;++i)
	{
		int a;
		cin>>a;
		if (a==50) nx++; else ny++;
	}
	F[0][0][1]=1;
	G[0][0][1]=1;
	Q.push(pair<pii,int>(pii(0,0),1));
	while (!Q.empty())
	{
		int x=Q.front().X.X,y=Q.front().X.Y,s=Q.front().Y;
		Q.pop();
		int tF=F[x][y][s];
		ll tG=G[x][y][s];
		if (s)
		{
			x=nx-x,y=ny-y;
			for (int i=0;i<=x;++i)
				for (int j=0;j<=y;++j) if (i+j>0)
					if (i*50+j*100<=k)
					{
						if (!F[nx-x+i][ny-y+j][0])
						{
							F[nx-x+i][ny-y+j][0]=tF+1;
							Q.push(pair<pii,int>(pii(nx-x+i,ny-y+j),0));
						}
						if (F[nx-x+i][ny-y+j][0]==tF+1)
						{
							F[nx-x+i][ny-y+j][0]=tF+1;
							(G[nx-x+i][ny-y+j][0]+=C[x][i]*C[y][j]%MOD*tG%MOD)%=MOD;
						}
					}
		}
		else
		{
			for (int i=0;i<=x;++i)
				for (int j=0;j<=y;++j) if (i+j>0)
					if (i*50+j*100<=k)
					{
						if (!F[x-i][y-j][1])
						{
							F[x-i][y-j][1]=tF+1;
							Q.push(pair<pii,int>(pii(x-i,y-j),1));
						}
						if (F[x-i][y-j][1]==tF+1)
						{
							F[x-i][y-j][1]=tF+1;
							(G[x-i][y-j][1]+=C[x][i]*C[y][j]%MOD*tG%MOD)%=MOD;
						}
					}
		}
	}
	if (!F[nx][ny][0])
		cout<<-1<<endl<<0<<endl;
	else
		cout<<F[nx][ny][0]-1<<endl<<G[nx][ny][0]<<endl;
	return 0;
}