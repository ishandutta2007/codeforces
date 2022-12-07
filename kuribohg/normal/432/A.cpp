#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<cstdlib>
#include<stack>
#include<set>
#include<map>
#include<utility>
using namespace std;
int n,k,a[3001],ans;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) if(a[i]<=5-k) ans++;
	printf("%d\n",ans/3);
	return 0;
}