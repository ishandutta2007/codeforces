#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int a[N+5],b[N+5];
int bucket[N+5];
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	for(int i=1;i<=m;i++) bucket[b[i]]++;
	for(int i=1;i<=n;i++) if(bucket[a[i]]) printf("%d ",a[i]);
	printf("\n");
	return 0;
}