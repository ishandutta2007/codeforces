#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
typedef long long LL;
const int MAXN=200010;
int n;
LL k,a[MAXN],ans;
map<LL,LL> c1,c2;
int main()
{
	scanf("%d%I64d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]%k==0&&c2.count(a[i]/k)) ans+=c2[a[i]/k];
		if(a[i]%k==0&&c1.count(a[i]/k)) c2[a[i]]+=c1[a[i]/k];
		c1[a[i]]++;
	}
	printf("%I64d\n",ans);
	return 0;
}