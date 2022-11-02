#include<bits/stdc++.h>
using namespace std;

const int maxn=100010;
int a[maxn],num[maxn],cnt[maxn];
int n,m;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		num[i]=a[i];
	}
	sort(num+1,num+n+1);
	m=unique(num+1,num+n+1)-(num+1);
	for (int i=1;i<=n;i++)
		cnt[lower_bound(num+1,num+m+1,a[i])-num]++;
	for (int i=m;i>=1;i--)
	if (cnt[i]&1)
	{
		printf("Conan\n");
		return 0;
	}
	printf("Agasa\n");
	return 0;
}