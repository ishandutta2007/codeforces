#include<iostream>
#include<cstdio>
using namespace std;
int a[505],a1[505],a2[505],us[505];
int main()
{
	int n,i,j,mn,mx=0,lst=0,cnt=0,s=0,ans=0;cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>a[i];s+=a[i];
		if (a[i]!=1)
		{
			if (lst) ++cnt,a1[cnt]=lst,a2[cnt]=i;
			else mn=i;mx=max(mx,i);lst=i;ans++;
		}
	}
	if (s<2*n-2){puts("NO");return 0;}
	if (mn==mx)
	{
		for (i=1;i<=n;i++) if (a[i]==1) ++cnt,a1[cnt]=mn,a2[cnt]=i;
		printf("YES %d\n%d\n",2,cnt);
		for (i=1;i<=cnt;i++) printf("%d %d\n",a1[i],a2[i]);
		return 0;
	}
	for (i=1;i<=n;i++) if (a[i]==1)
	{
		if (!us[mn]) {++cnt,a1[cnt]=mn,a2[cnt]=i,us[mn]=1;a[mn]++;ans++;continue;}
		if (!us[mx]) {++cnt,a1[cnt]=mx,a2[cnt]=i,us[mx]=1;a[mx]++;ans++;continue;}
		for (j=1;j<=n;j++) if (a[j]!=1 && a[j]-us[j]>2) {us[j]++,cnt++,a1[cnt]=j,a2[cnt]=i;break;}
	}
	printf("YES %d\n%d\n",ans-1,cnt);
	for (i=1;i<=cnt;i++) printf("%d %d\n",a1[i],a2[i]);
}