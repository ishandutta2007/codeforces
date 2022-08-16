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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=310;

bool F[MaxN][MaxN][MaxN];
bool u[MaxN][MaxN],v[MaxN][MaxN];

bool tF[MaxN][MaxN];
bool tu[MaxN],tv[MaxN];

void make_list()
{
	for (int i=0;i<300;++i)
		for (int j=0;j<300;++j)
			u[i][j]=v[i][j]=1;
	u[0][0]=v[0][0]=0;
	for (int i=0;i<300;++i)
		for (int j=i;j<300;++j)
			for (int k=j;k<300;++k)
			{
				bool p=0;
				if (i&&!u[j][k]) p=1;
				if (j&&!u[i][k]) p=1;
				if (k&&!u[i][j]) p=1;
				if (i&&j&&k&&!v[j-i][k-j]) p=1;
				F[i][j][k]=p;
				if (!F[i][j][k])
				{
					u[i][j]=u[i][k]=u[j][k]=0;
					v[j-i][k-j]=0;
				}
			}
	
	for (int i=0;i<300;++i)
		tu[i]=tv[i]=1;
	tu[0]=tv[0]=0;
	for (int i=0;i<300;++i)
		for (int j=i;j<300;++j)
		{
			bool p=0;
			if (i&&!tu[j]) p=1;
			if (j&&!tu[i]) p=1;
			if (i&&j&&!tv[j-i]) p=1;
			tF[i][j]=p;
			if (!tF[i][j])
			{
				tu[i]=tu[j]=0;
				tv[j-i]=0;
			}
		}
}

int n;
int a[4];

int main()
{
	make_list();
	cin>>n;
	for (int i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);
	if (n==1)
	{
		puts(a[0]?"BitLGM":"BitAryo");
	}
	else if (n==2)
	{
		puts(tF[a[0]][a[1]]?"BitLGM":"BitAryo");
	}
	else
	{
		puts(F[a[0]][a[1]][a[2]]?"BitLGM":"BitAryo");
	}
	return 0;
}