#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[100005],cnt[100005],b[1000005];
int main()
{
	int n,i;cin>>n;bool flg=1;
	for (i=1;i<=n;i++) cin>>a[i],a[i]=n-a[i],cnt[a[i]]++;
	for (i=1;i<=n;i++) if (cnt[i]%i!=0) flg=0;
	if (flg==0) printf("Impossible");
	else
	{
		printf("Possible\n");
		for(int i=1;i<=n;i++) b[i]=cnt[i]/i;
		for(int i=1;i<=n;i++) b[i]+=b[i-1];
		for(int i=1;i<=n;i++)
		{
			printf("%d ",b[a[i]]);
			cnt[a[i]]--;if ((cnt[a[i]]%a[i])==0) b[a[i]]--;
		}
	}
}