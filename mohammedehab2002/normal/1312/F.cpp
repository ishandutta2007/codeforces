#include <bits/stdc++.h>
using namespace std;
int gr[6][6][6][1000][3],st[6][6][6][3],cyc[6][6][6][3];
long long a[300005];
int mex(vector<int> v)
{
	int ans=0;
	while (find(v.begin(),v.end(),ans)!=v.end())
	ans++;
	return ans;
}
int solve(int x,int y,int z,int i,int l)
{
	if (i<=0)
	return 0;
	if (gr[x][y][z][i][l]!=-1)
	return gr[x][y][z][i][l];
	if (!l)
	return gr[x][y][z][i][l]=mex({solve(x,y,z,i-x,0),solve(x,y,z,i-y,1),solve(x,y,z,i-z,2)});
	if (l==1)
	return gr[x][y][z][i][l]=mex({solve(x,y,z,i-x,0),solve(x,y,z,i-z,2)});
	return gr[x][y][z][i][l]=mex({solve(x,y,z,i-x,0),solve(x,y,z,i-y,1)});
}
int solve2(int x,int y,int z,long long i,int l)
{
	if (i<st[x][y][z][l])
	return solve(x,y,z,i,l);
	return solve(x,y,z,(i-st[x][y][z][l])%cyc[x][y][z][l]+st[x][y][z][l],l);
}
int main()
{
	memset(gr,-1,sizeof(gr));
	for (int x=1;x<=5;x++)
	{
		for (int y=1;y<=5;y++)
		{
			for (int z=1;z<=5;z++)
			{
				for (int l=0;l<3;l++)
				{
					for (int len=1;!cyc[x][y][z][l];len++)
					{
						for (int s=0;s<=300;s++)
						{
							bool ok=1;
							for (int i=s;i<s+300;i++)
							{
								if (solve(x,y,z,i,l)!=solve(x,y,z,i+len,l))
								{
									ok=0;
									break;
								}
							}
							if (ok)
							{
								st[x][y][z][l]=s;
								cyc[x][y][z][l]=len;
								break;
							}
						}
					}
				}
			}
		}
	}
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,x,y,z,tot=0,ans=0;
		scanf("%d%d%d%d",&n,&x,&y,&z);
		for (int i=0;i<n;i++)
		{
			scanf("%I64d",&a[i]);
			tot^=solve2(x,y,z,a[i],0);
		}
		for (int i=0;i<n;i++)
		{
			ans+=!(tot^solve2(x,y,z,a[i],0)^solve2(x,y,z,a[i]-x,0));
			ans+=!(tot^solve2(x,y,z,a[i],0)^solve2(x,y,z,a[i]-y,1));
			ans+=!(tot^solve2(x,y,z,a[i],0)^solve2(x,y,z,a[i]-z,2));
		}
		printf("%d\n",ans);
	}
}