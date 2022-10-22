#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cingroup(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfgroup(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
typedef unsigned long long ull;
using namespace std;
int n,a,b;

bool check(int x[])
{
	int s[6]={0};
	for(int i=0;i<6;i++)
	{
		if(i<4)
		{
			s[x[i]]+=a;
		}
		else
		{
			s[x[i]]+=b;
		}
	}
	for(int i=0;i<6;i++)
	{
		if(s[i]>n) return false; 
	}
	return true;
}

int appear(int a[])
{
	bool f[6]={0};
	for(int i=0;i<6;i++)
	{
		f[a[i]]=true;
	}
	int res=0;
	rep(6)
	{
		res+=f[i];
	}
	return res;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>a>>b;
	int ans=8950324;
	int t[6];
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			for(int k=0;k<6;k++)
			{
				for(int x=0;x<6;x++)
				{
					for(int y=0;y<6;y++)
					{
						for(int z=0;z<6;z++)
						{
							t[0]=i;
							t[1]=j;
							t[2]=k;
							t[3]=x;
							t[4]=y;
							t[5]=z;
							if(check(t))
							{
								ans=min(ans,appear(t));
							}
						}
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}