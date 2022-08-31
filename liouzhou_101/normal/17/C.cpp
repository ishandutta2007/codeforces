#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;

const int MOD=51123987;

int n,m,d;
char s[155];

int v[3];
int p[155][3];

int F[155][55][55][55];

int ans;

int main()
{
	cin>>n>>s+1;
	m=unique(s+1,s+n+1)-s-1;
	d=n/3+1;
	for (int i=m;i>=0;--i)
	{
		if (i) v[s[i]-'a']=i;
		for (int j=0;j<3;++j)
			p[i][j]=v[j];
	}
	F[0][0][0][0]=1;
	for (int k=0;k<=m;++k)
		for (int x=0;x<=d;++x)
			for (int y=0;y<=d;++y)
				for (int z=0;z<=d;++z)
				{
					if (!F[k][x][y][z]) continue;
					if (x+y+z==n) if (abs(x-y)<2&&abs(y-z)<2&&abs(z-x)<2) (ans+=F[k][x][y][z])%=MOD;
					if (p[k][0]) (F[p[k][0]][x+1][y][z]+=F[k][x][y][z])%=MOD;
					if (p[k][1]) (F[p[k][1]][x][y+1][z]+=F[k][x][y][z])%=MOD;
					if (p[k][2]) (F[p[k][2]][x][y][z+1]+=F[k][x][y][z])%=MOD;
				}
	cout<<ans<<endl;
	return 0;
}