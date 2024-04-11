#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
int T,n;ll a[N];bool fl;
void slv()
{
	scanf("%d",&n);fl=0;
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]),a[i]+=a[i-1];
	if(a[n]) {printf("No\n");return;}
	for(int i=1;i<=n;++i) if(a[i]<0) {printf("No\n");return;}
	for(int i=1;i<=n;++i)
	{fl|=!a[i];if(a[i] && fl) {printf("No\n");return;}}
	printf("Yes\n");
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}