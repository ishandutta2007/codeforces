#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

int p[100];

int main()
{
	int n,m;scanf("%d%d",&n,&m);
	int i,ans=0x7fffffff;
	for(i=0;i<m;i++)scanf("%d",p+i);
	sort(p,p+m);
	for(i=0;i<=m-n;i++){
		ans=min(ans,p[i+n-1]-p[i]);
	}
	printf("%d",ans);
	return 0;
}