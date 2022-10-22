#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,m,a[N];bool ans;map<int,bool> vs;
void slv()
{
	scanf("%d %d",&n,&m);ans=0;vs.clear();
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		vs[a[i]]=1;if(vs[a[i]-m] || vs[a[i]+m]) ans=1;
	}puts(ans?"Yes":"No");
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}