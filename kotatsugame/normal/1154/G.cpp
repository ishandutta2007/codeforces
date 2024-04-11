#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N;
vector<int>id[10000001];
int A[1<<20];
main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&A[i]);
		id[A[i]].push_back(i);
	}
	long long ans=1e18;
	int x,y;
	for(int i=1;i<=10000000;i++)
	{
		int a=-1,b=-1;
		for(int j=i;j<=10000000;j+=i)
		{
			for(int idx:id[j])
			{
				if(a==-1)a=idx;
				else if(b==-1)
				{
					b=idx;
					break;
				}
			}
			if(b!=-1)break;
		}
		if(b!=-1)
		{
			long long T=(long long)A[a]*A[b]/i;
			if(ans>T)
			{
				ans=T;
				x=a;
				y=b;
			}
		}
	}
	if(x>y)swap(x,y);
	printf("%d %d\n",x,y);
}