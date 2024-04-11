#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int T,n,p;
bool used[110][110];
int main()
{
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		memset(used,false,sizeof(used));
		scanf("%d%d",&n,&p);
		for(int i=1;i<=n;i++) used[i][i]=true;
		for(int i=1;i<n;i++) printf("%d %d\n",i,i+1),used[i][i+1]=used[i+1][i]=true;
		printf("%d 1\n",n),used[1][n]=used[n][1]=true;
		for(int i=1;i<n-1;i++) printf("%d %d\n",i,i+2),used[i][i+2]=used[i+2][i]=true;
		printf("%d 1\n",n-1),used[1][n-1]=used[n-1][1]=true;
		printf("%d 2\n",n),used[2][n]=used[n][2]=true;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(!used[i][j]&&p>0)
					p--,used[i][j]=used[j][i]=true,printf("%d %d\n",i,j);
	}
	return 0;
}