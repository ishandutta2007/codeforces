#include <bits/stdc++.h>
#define int long long

using namespace std;

int last[1000005];
bool prime[1000005];
int phi[1000005];
int n, k;

void eras()
{
	for(int i=1; i<=1000000; i++)
	{
		last[i]=1000000000;
	}
	for(int i=2; i<=n; i++)
	{
		if(prime[i]) continue;
		for(int j=2*i; j<=n; j+=i)
		{
			last[j]=min(last[j], i);
			prime[j]=true;
		}
	}
	for(int i=2; i<=n; i++)
	{
		if(!prime[i])
		{
			phi[i]=i-1;
		}
		else
		{
			int j=i, lol=1;
			while(j%last[i]==0)
			{
				lol*=last[i];
				j/=last[i];
			}
			if(min(j, lol)>1)
			phi[i]=phi[lol]*phi[j];
			else
			phi[i]=i-i/last[i];
		}
	}
}

signed main()
{
	cin>>n>>k;
	eras();
	phi[1]=1000000000;
	phi[2]=1000000000;
	int ans=0;
	sort(phi+1, phi+n+1);
	for(int i=1; i<=k; i++)
	{
		ans+=phi[i];
	}
	if(k==1) cout<<ans+1;
	else cout<<ans+2;
}