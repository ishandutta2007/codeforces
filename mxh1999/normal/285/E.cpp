//This is meng meng da mjy>_<
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000007
typedef long long ll;
using namespace std;

void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 1010
const int mo=1e9+7;
ll f[maxn][maxn][4],mjy;
int n,k;

int main()
{
	read(n),read(k);
	f[1][0][0]=1;
	for (int i=2;i<=n;i++)
	{
		for (int j=0;j<i;j++)
		{
			f[i][j][0]=(f[i][j][0]+f[i-1][j][0])%mo;
			f[i][j+2][2]=(f[i][j+2][2]+f[i-1][j][0])%mo;
			f[i][j-1][3]=(f[i][j-1][3]+f[i-1][j][0]*j)%mo;
			f[i][j][3]=(f[i][j][3]+f[i-1][j][0]*(i-j-2))%mo;
			
			f[i][j][0]=(f[i][j][0]+f[i-1][j][1])%mo;
			f[i][j][1]=(f[i][j][1]+f[i-1][j][1])%mo;
			f[i][j+1][1]=(f[i][j+1][1]+f[i-1][j][1])%mo;
			f[i][j-1][3]=(f[i][j-1][3]+f[i-1][j][1]*(j-1))%mo;
			f[i][j][3]=(f[i][j][3]+f[i-1][j][1]*(i-j-2))%mo;
			
			f[i][j][0]=(f[i][j][0]+f[i-1][j][2])%mo;
			f[i][j][1]=(f[i][j][1]+f[i-1][j][2]*2)%mo;
			f[i][j-1][3]=(f[i][j-1][3]+f[i-1][j][2]*(j-2))%mo;
			f[i][j][3]=(f[i][j][3]+f[i-1][j][2]*(i-j-1))%mo;
			
			f[i][j][0]=(f[i][j][0]+f[i-1][j][3])%mo;
			f[i][j+1][1]=(f[i][j+1][1]+f[i-1][j][3]*2)%mo;
			f[i][j-1][3]=(f[i][j-1][3]+f[i-1][j][3]*j)%mo;
			f[i][j][3]=(f[i][j][3]+f[i-1][j][3]*(i-j-3))%mo;
		}
	}
	mjy=f[n][k][0]+f[n][k][1]+f[n][k][2]+f[n][k][3];
	mjy%=mo;
	printf("%d\n",mjy);
	return 0;
}