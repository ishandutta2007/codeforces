#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,ans;
char str[100][100];
bool used[1000];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",str[i]);
	for(int i=0;i<n-1;i++)
		for(int j=0;j<m-1;j++)
		{
			memset(used,false,sizeof(used));
			used[str[i][j]]=used[str[i+1][j]]=used[str[i][j+1]]=used[str[i+1][j+1]]=true;
			if(used['f']&&used['a']&&used['c']&&used['e']) ans++;
		}
	printf("%d\n",ans);
	return 0;
}