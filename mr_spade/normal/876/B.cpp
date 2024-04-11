#include<cstdio>
#include<vector>
using std::vector;
const int N=1e5+5;
int n,k,m;
int num;
vector<int>cnt[N];
signed main()
{
	int i,j;
	scanf("%d%d%d",&n,&k,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num);
		cnt[num%m].push_back(num);
	}
	for(i=0;i<m;i++)
	{
		if(cnt[i].size()>=k)
		{
			puts("Yes");
			for(j=0;j<k;j++)
				printf("%d ",cnt[i][j]);
			putchar('\n');
			return 0;
		}
	}
	puts("No");
	return 0;
}