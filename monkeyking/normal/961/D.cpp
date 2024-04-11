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
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
typedef unsigned long long ull;
const int inf=103974182;
using namespace std;
int n;
pii a[100005];

bool ok(int x,int y,int z)
{
	return (1LL*(a[y].second-a[x].second)*(a[z].first-a[y].first)==1LL*(a[z].second-a[y].second)*(a[y].first-a[x].first));
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].first,&a[i].second);
	}
	if(n<=4)
	{
		over("YES\n");
	}
	int num[4]={0,1,2,3};
	int f=true;
	int k1=-1,k2=-1;
	for(int i=2;i<n;i++)
	{
		if(!ok(0,1,i))
		{
			if(k1==-1)
			{
				k1=i;
			}
			else if(k2==-1)
			{
				k2=i;
			}
			else
			{
				if(!ok(k1,k2,i))
				{
					f=false;
					break;
				}
			}
		}
	}
	if(f==true) over("YES");
	f=true;
	k1=-1;
	k2=-1;
//	cout<<ok(0,2,3)<<endl;
	for(int i=3;i<n;i++)
	{
		if(!ok(0,2,i))
		{
			if(k1==-1)
			{
				k1=i;
			}
			else
			{
				if(!ok(1,k1,i))
				{
					f=false;
					break;
				}
			}
		}
	}
	if(f==true) over("YES");
	k1=-1;
	k2=-1;
	f=true;
	for(int i=3;i<n;i++)
	{
		if(!ok(1,2,i))
		{
			if(k1==-1)
			{
				k1=i;
			}
			else
			{
				if(!ok(0,k1,i))
				{
					f=false;
					break;
				}
			}
		}
	}
	if(f==true) over("YES");
	over("NO");
	return 0;
}