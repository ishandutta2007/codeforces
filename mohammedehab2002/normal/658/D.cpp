#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int arr[200005],v[200035];
vector<int> pos;
int sign(int x)
{
	return (x<0? -1:1);
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		int s=sign(arr[i]);
		arr[i]*=s;
		for (int x=0;x<30;x++)
		{
			if (arr[i]&(1<<x))
			v[i+x]+=s;
		}
		arr[i]*=s;
	}
	for (int i=0;i<200034;i++)
	{
		v[i+1]+=v[i]/2;
		v[i]%=2;
		if (v[i]==-1)
		{
			v[i+1]--;
			v[i]=1;
		}
	}
	if (v[200034]==-1)
	{
		memset(v,0,sizeof(v));
		for (int i=0;i<=n;i++)
		{
			arr[i]*=-1;
			int s=sign(arr[i]);
			arr[i]*=s;
			for (int x=0;x<30;x++)
			{
				if (arr[i]&(1<<x))
				v[i+x]+=s;
			}
			arr[i]*=s;
		}
		for (int i=0;i<200034;i++)
		{
			v[i+1]+=v[i]/2;
			v[i]%=2;
			if (v[i]==-1)
			{
				v[i+1]--;
				v[i]=1;
			}
		}
	}
	for (int i=0;i<200035;i++)
	{
		if (v[i])
		pos.push_back(i);
	}
	if (pos.size()>60)
	{
		printf("0");
		return 0;
	}
	int res=0;
	for (int i=0;i<=n;i++)
	{
		bool b=1;
		long long ans=0;
		for (int x:pos)
		{
			if (x-i>60 || x-i<0)
			{
				b=0;
				break;
			}
			ans|=(1LL<<(x-i));
		}
		if (!b)
		continue;
		if (abs(ans-arr[i])<=k && (ans-arr[i]!=0 || i!=n))
		res++;
	}
	printf("%d",res);
}