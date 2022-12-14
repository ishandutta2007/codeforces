#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T; cin>>T;
	while(T--)
	{
		int n; cin>>n; 
		int a[n+2]={0},b[n+2]={0};
		int maxn = 0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			b[a[i]]++;
			maxn = max(maxn,a[i]);
		}
		int cnt = 0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==1) 
			{
				cnt = i;
				break;
			}
		}
		if(cnt!=0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==cnt) 
				{
					cnt = i;
					break;
				}
			}
		}
		
		if(cnt) cout<<cnt<<endl;
		else cout<<-1<<endl;
	}
 }