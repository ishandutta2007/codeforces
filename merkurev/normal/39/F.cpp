#include <iostream>

using namespace std;
int d[105],kk[105],r[105];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for (int i=0;i<m;i++)
	{
		scanf("%d",&d[i]);
	}
	for (int i=0;i<k;i++)
	{
		scanf("%d",&kk[i]);
	}
	for (int i=0;i<m;i++)
		for (int j=0;j<k;j++)
			if (kk[j]%d[i]==0)
				r[i]++;
	int min=1000,rez=0;
	for(int i=0;i<m;i++)
	{
		if (r[i]<min)
		{
			rez=1;
			min=r[i];
		}
		else
			if (r[i]==min)
				rez++;
	}
	printf("%d\n",rez);
	for (int i=0;i<m;i++)
		if (r[i]==min)
			printf("%d ",i+1);
	return 0;
}