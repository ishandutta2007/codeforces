#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=150010;
const ll INF=1000000000000000000LL;

int n,m,d;
ll F[2][MaxN];
int a[MaxN],b[MaxN],t[MaxN];
int head,tail;
int Qx[MaxN];
ll Qv[MaxN];

int getabs(int x)
{
	return (x>=0)?x:-x;
}

int main()
{
	cin>>n>>m>>d;
	for (int i=1;i<=m;++i)
		scanf("%d%d%d",&a[i],&b[i],&t[i]);
	for (int i=1;i<=m;++i)
	{
		int now=i&1;
		int pre=now^1;
		head=1;
		tail=0;
		ll delta=(ll)(t[i]-t[i-1])*d;
		for (int j=1,k=1;j<=n;++j)
		{
			while (k<=j+delta&&k<=n)
			{
				while (head<=tail)
				{
					if (Qv[tail]>F[pre][k]) break;
					--tail;
				}
				++tail;
				Qx[tail]=k;
				Qv[tail]=F[pre][k];
				++k;
			}
			while (Qx[head]<j-delta) ++head;
			F[now][j]=Qv[head]-getabs(a[i]-j);
			/*
			F[now][j]=-INF;
			for (int p=max(1LL,j-delta);p<=min((ll)n,j+delta);++p)
				F[now][j]=max(F[now][j],F[pre][p]-getabs(a[i]-j));
			*/
		}
	}
	ll ans=F[m&1][1];
	for (int i=1;i<=n;++i)
		ans=max(ans,F[m&1][i]);
	for (int i=1;i<=m;++i)
		ans+=b[i];
	cout<<ans<<endl;
	return 0;
}