#include <bits/stdc++.h>
using namespace std;
#define N 105
int T,n,m,s,a[N];
void slv()
{
	scanf("%d %d",&n,&m);s=0;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),s+=a[i];
	if(m==s) {puts("NO");return;}s=0;puts("YES");
	for(int i=1;i<=n;++i)
	{
		s+=a[i];if(m==s) swap(a[i],a[i+1]);
		printf("%d ",a[i]);
	}puts("");
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0; 
}