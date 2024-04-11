#include <bits/stdc++.h>
using namespace std;
#define N 1005
int n,a[N],ord[N],rv[N],ans[N][N];
bool cmp(int x,int y) {return a[x]>a[y];}
int main()
{
	scanf("%d",&n);printf("%d\n",n+1);
	for(int i=1;i<=n;++i) ord[i]=i,scanf("%d",&a[i]);
	sort(ord+1,ord+n+1,cmp);
	for(int i=1;i<=n;++i) rv[ord[i]]=i;
	for(int i=1;i<=n;++i)
		for(int j=1,k=i;j<=a[ord[i]];++j,k=k>n?1:k+1)
			ans[k][i]=1;
	for(int i=1;i<=n+1;++i,puts(""))
		for(int j=1;j<=n;++j)
			putchar(ans[i][rv[j]]+48);return 0;
}