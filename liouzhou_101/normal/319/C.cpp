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
typedef pair<ll,ll> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=100010;

int n;
ll a[MaxN],b[MaxN];
int x,y;
ll qx[MaxN],qy[MaxN];
ll F[MaxN];

ld det(ld x1,ld y1,ld x2,ld y2,ld x3,ld y3)
{
	return x1*y2-x2*y1+x2*y3-x3*y2+x3*y1-x1*y3;
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	for (int i=1;i<=n;++i)
		cin>>b[i];
	x=y=1;
	qx[1]=-b[1];
	qy[1]=F[1]=0;
	for (int i=2;i<=n;++i)
	{
		while (x<y)
		{
			if (qy[x+1]-qy[x]>a[i]*(qx[x+1]-qx[x])) break;
			++x;
		}
		F[i]=qy[x]-a[i]*qx[x];
		++y;
		qx[y]=-b[i];
		qy[y]=F[i];
		while (x+1<y)
		{
			if (det(qx[y-2],qy[y-2],qx[y-1],qy[y-1],qx[y],qy[y])>0) break;
			qx[y-1]=qx[y];
			qy[y-1]=qy[y];
			--y;
		}
	}
	cout<<F[n]<<endl;
	return 0;
}