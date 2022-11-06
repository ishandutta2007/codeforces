#include<bits/stdc++.h>
#define re register
int a[1010],a1[1010],p[1010];
inline bool cmp(re int aa,re int a2){return a1[aa]==a1[a2]?(a[aa]==a[a2]?aa<a2:a[aa]<a[a2]):a1[aa]<a1[a2];}
int main()
{
	re int n,num=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)scanf("%d",&a[i]),a1[i]=a[i];
	for(re int i=1;i<=n;i++)for(re int j=i+1;j<=n;j++)if(a[i]>a[j])num++;
	printf("%d\n",num);
	for(re int i=1;i<n;i++)
	{
		for(re int j=i+1;j<=n;j++)p[j-i]=j;
		std::sort(p+1,p+n-i+1,cmp);
		for(re int j=n-i;j;j--)if(a[i]>a[p[j]])printf("%d %d\n",i,p[j]),std::swap(a1[i],a1[p[j]]);
	}
}