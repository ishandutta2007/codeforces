#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[110],tot,p;
bool used[210];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p);
		used[p+100]=true;
	}
	for(int i=0;i<=200;i++)
		if(used[i]) a[++tot]=i-100;
	sort(a+1,a+tot);
	if(tot>=2) printf("%d\n",a[2]);
	else puts("NO");
	return 0;
}