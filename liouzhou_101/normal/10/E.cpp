#include<cstdio>
#include<iostream>

using namespace std;

const int INF=2100000000;

int n;
int a[410];

int ans=INF;

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	for (int i=1;i<=n;++i)
		for (int j=i+1;j<=n;++j)
		{
			int p=a[i]-1,t=a[j],v=1;
			for (int k=i+1;k<=j;++k)
			{
				v+=p/a[k];
				t+=p/a[k]*a[k];
				p%=a[k];
			}
			p=t;
			for (int k=1;k<=n;++k)
			{
				v-=p/a[k];
				p%=a[k];
			}
			if (v<0)
				ans=min(ans,t);
		}
	if (ans==INF) ans=-1;
	cout<<ans<<endl;
	return 0;
}