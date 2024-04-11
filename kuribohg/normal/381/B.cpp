#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=100010;
int n,a[MAXN],u[MAXN],d[MAXN],tot1,tot2;
bool used[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	a[0]=-10000;
	a[n+1]=-10000;
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i-1]) u[++tot1]=a[i],used[i]=true;
	for(int i=n;i>=1;i--)
		if(!used[i]&&a[i]!=a[i+1]) d[++tot2]=a[i];
	if(d[1]==u[tot1]) tot1--;
	printf("%d\n",tot1+tot2);
	for(int i=1;i<=tot1;i++)
		printf("%d ",u[i]);
	for(int i=1;i<tot2;i++)
		printf("%d ",d[i]);
	if(tot2) printf("%d\n",d[tot2]);
	return 0;
}