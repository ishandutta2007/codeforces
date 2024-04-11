#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n,a[110],b[3],sum;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) b[a[i]/100]++,sum+=a[i]/100;
	if(sum&1) puts("NO");
	else if(sum%4&&!b[1]) puts("NO");
	else puts("YES");
	return 0;
}