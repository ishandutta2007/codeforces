#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[110],ans[110],tot;
char str[110][110];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	while(true)
	{
		int sub=0;
		for(int i=1;i<=n;i++)
			if(a[i]==0) sub=i;
		if(!sub) break;
		for(int i=1;i<=n;i++)
			a[i]-=str[sub][i]-'0';
		ans[sub]=true,tot++;
	}
	printf("%d\n",tot);
	for(int i=1;i<=n;i++)
		if(ans[i]) printf("%d ",i);
	return 0;
}