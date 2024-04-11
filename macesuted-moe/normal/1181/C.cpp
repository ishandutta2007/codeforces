#pragma GCC optimzie ("O2")
#pragma G++ optimize ("O2") 
#include <bits/stdc++.h>
using namespace std;

#define QUICK

#ifdef QUICK
	#define Re register 
#else
	#define Re 
#endif

char flag[1005][1005];
int Right[1005][1005],Down[1005][1005],Long[1005][1005];

int main()
{
#ifdef QUICK
	ios::sync_with_stdio(false);
#endif
	int n,m;
	cin>>n>>m;
	for(Re int r=1;r<=n;r++)
	{
		string s;
		cin>>s;
		for (Re int c=1;c<=m;c++)
		{
			flag[r][c]=s[c-1];
		}
	}
	for (Re int r=1;r<=n;r++)
	{
		for (Re int c=m;c>=1;c--)
		{
			if(flag[r][c]==flag[r][c+1])
			{
				Right[r][c]=Right[r][c+1]+1;
			}
			else
			{
				Right[r][c]=1;
			}
		}
	}
	for (Re int r=n;r>=1;r--)
	{
		for (Re int c=1;c<=m;c++)
		{
			if(flag[r][c]==flag[r+1][c])
			{
				Down[r][c]=1+Down[r+1][c];
				Long[r][c]=min(Long[r+1][c],Right[r][c]);
			}
			else
			{
				Down[r][c]=1;
				Long[r][c]=Right[r][c];
			}
		}
	}
	int ans=0;
	for(Re int r=1;r<=n;r++)
	{
		for (Re int c=1;c<=m;c++)
		{
			int size=Down[r][c];
			if(r+2*size>n) continue;
			if(Down[r+size][c]==size&&Down[r+2*size][c]>=size)
			{
				int t=0xfffffff;
				for (Re int i=r+2*size;i<=r+3*size-1;i++)
				{
					t=min(t,Right[i][c]);
				}
				ans+=min(Long[r][c],min(Long[r+size][c],t));
			}
		}
	}
	cout<<ans<<endl; 
	return 0;
}