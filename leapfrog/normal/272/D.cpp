#include<bits/stdc++.h>
using namespace std;
int n,p,ans,d2,a[100005],b[100005];map<int,int>mp;
int main()
{
	scanf("%d",&n),d2=0,ans=1;
	for(int i=1;i<=n;i++) scanf("%d",a+i),mp[a[i]]++;
	for(int i=1;i<=n;i++) scanf("%d",b+i),mp[b[i]]++,d2+=(a[i]==b[i]);
	scanf("%d",&p);
	for(map<int,int>::iterator i=mp.begin();i!=mp.end();i++)//num[i]!
		for(int j=1,t=j;j<=(*i).second;j++,t=j)
		{
			while(d2&&t%2==0) t/=2,d2--;
			ans=1ll*ans*t%p;
		}
	return printf("%d\n",ans),0;
}