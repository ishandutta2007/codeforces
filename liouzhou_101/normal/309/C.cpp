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

int n,m;
int a[30],b[30];

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		for (int j=0;j<30;++j)
		{
			if (x&1) ++a[j];
			x>>=1;
		}
	}
	for (int i=1;i<=m;++i)
	{
		int x;
		scanf("%d",&x);
		++b[x];
	}
	int ans=0;
	for (int i=0;i<30;++i) for (int x=1;x<=b[i];++x)
	{
		int t=0;
		for (int j=i;j<30;++j)
		{
			if (a[j])
			{
				t=1;
				++ans;
				--a[j];
				for (int k=0;k<j;++k)
					++a[k];
				break;
			}
		}
		if (!t) break;
	}
	cout<<ans<<endl;
	return 0;
}