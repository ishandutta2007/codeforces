#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 210000;
const int maxc = 2550000;

int n;
vector<int>V[maxc];
int a[maxn];

vector< pair<int,int> >sum[maxc<<1];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		V[a[i]].push_back(i);
	}
	
	int las=0;
	for(int i=0;i<maxc;i++) if((int)V[i].size()>=2)
	{
		if((int)V[i].size()>=4)
		{
			puts("YES");
			for(int j=0;j<4;j++) printf("%d ",V[i][j]);
			return 0;
		}
		if(las!=0)
		{
			puts("YES");
			for(int j=0;j<2;j++) printf("%d %d ",V[las][j],V[i][j]);
			return 0;
		}
		else las=i;
	}
	
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
	{
		int s=a[i]+a[j];
		for(auto k:sum[s])
		{
			if(k.first!=i&&k.second!=i&&k.second!=j)
			{
				puts("YES");
				printf("%d %d %d %d\n",i,j,k.first,k.second);
				return 0;
			}
		}
		sum[s].push_back(make_pair(i,j));
	}
	puts("NO");
	
	return 0;
}