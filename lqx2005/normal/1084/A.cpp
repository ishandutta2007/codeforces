#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n;
int a[N+5];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int ans=0;
	for(int i=1;i<=n;i++) ans+=a[i]*(i-1)*4;
	printf("%d\n",ans);
	return 0;
}