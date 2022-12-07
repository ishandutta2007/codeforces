#include<iostream>
#include<cstdio>
using namespace std;
int n,a[101],b[101],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j&&a[i]==b[j]) ans++;
	printf("%d\n",ans);
	return 0;
}