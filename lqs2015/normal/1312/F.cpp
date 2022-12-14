#include<bits/stdc++.h>
using namespace std;
const int maxt=100;
int n,x,y,z,all,test,sg[44444][3],cr,ans;
bool used[5];
long long a[333333];
int SG(long long n,int t)
{
	if (n<=maxt+all) return sg[n][t];
	return sg[(n-maxt)%all+maxt][t];
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d%d",&n,&x,&y,&z);
		all=2520;
		sg[0][0]=sg[0][1]=sg[0][2]=0;
		for (int i=1;i<=all+maxt;i++)
		{
			used[sg[max(0,i-x)][0]]=used[sg[max(0,i-y)][1]]=used[sg[max(0,i-z)][2]]=1;
			for (int j=0;j<4;j++)
			{
				if (!used[j])
				{
					sg[i][0]=j;
					break;
				}
			}
			used[sg[max(0,i-x)][0]]=used[sg[max(0,i-y)][1]]=used[sg[max(0,i-z)][2]]=0;
			used[sg[max(0,i-x)][0]]=used[sg[max(0,i-z)][2]]=1;
			for (int j=0;j<4;j++)
			{
				if (!used[j])
				{
					sg[i][1]=j;
					break;
				}
			}
			used[sg[max(0,i-x)][0]]=used[sg[max(0,i-z)][2]]=0;
			used[sg[max(0,i-x)][0]]=used[sg[max(0,i-y)][1]]=1;
			for (int j=0;j<4;j++)
			{
				if (!used[j])
				{
					sg[i][2]=j;
					break;
				}
			}
			used[sg[max(0,i-x)][0]]=used[sg[max(0,i-y)][1]]=0;
		}
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		cr=0;ans=0;
		for (int i=1;i<=n;i++) cr^=SG(a[i],0);
		for (int i=1;i<=n;i++)
		{
			if ((cr^SG(a[i],0)^SG(max(0ll,a[i]-x),0))==0) ans++;
			if ((cr^SG(a[i],0)^SG(max(0ll,a[i]-y),1))==0) ans++;
			if ((cr^SG(a[i],0)^SG(max(0ll,a[i]-z),2))==0) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}