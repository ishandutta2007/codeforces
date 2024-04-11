#include <fstream>



char arr[6000][6000];

int lin[6000][6000];


int n,m;

int lin1(int l,int r)
{
	if (l<0 || r>=m)
		return 0;
	else
		return lin[l][r];
}


int main()
{
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%s",arr[i]);
	}
	for (int i=0;i<n;i++)
	{
		int dl=0;
		for (int j=0;j<m;j++)
		{
			if (dl!=0 && arr[i][j]=='0')
			{
				lin[j-dl][j-1]++;
				dl=0;
			}
			if (arr[i][j]!='0')
				dl++;
		}
		if (dl!=0)
		{
			lin[m-dl][m-1]++;
		}
	}
	/*for (int i=0;i<m;i++)
	{
		for (int j=0;j<m;j++)
		{
			printf("%d ",lin[i][j]);
		}
		printf("\n");
	}*/
	int maxlvl=0;
	for (int j=m;j>0;j--)
	{
		for (int i=0;i+j-1<m;i++)
		{
			lin[i][i+j-1]=lin[i][i+j-1]+lin1(i-1,i+j-1)+lin1(i,i+j)-lin1(i-1,i+j);
			if (lin[i][i+j-1]*j>maxlvl)
			{
				maxlvl=lin[i][i+j-1]*j;
			}
		}
	}
	printf("%d",maxlvl);
}