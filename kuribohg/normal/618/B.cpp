#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100][100],p[100];
bool used[100];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(used[j]) continue;
			bool ok=true;
			for(int k=1;k<=n;k++)
				if(k!=j&&!used[k]&&a[j][k]!=i) ok=false;
			if(ok) {used[j]=true,p[j]=i;break;}
		}
	for(int i=1;i<=n;i++) printf("%d\n",p[i]);
	return 0;
}