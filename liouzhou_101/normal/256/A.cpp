#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

const int MaxN=4010;

int n;
int a[MaxN];
int F[MaxN][MaxN];
int p[1000010];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int ans=min(n,2);
	for (int i=1;i<=n;++i)
		F[i][0]=1;
	for (int i=2;i<=n;++i)
	{
		for (int j=1;j<=n;++j)
			p[a[j]]=0;
		for (int j=1;j<i;++j)
		{
			F[i][j]=max(F[i][j],F[j][p[a[i]]]+1);
			ans=max(ans,F[i][j]);
			p[a[j]]=j;
		}
	}
	cout<<ans<<endl;
	return 0;
}