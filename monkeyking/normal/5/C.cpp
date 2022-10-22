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
typedef unsigned long long ull;
using namespace std;
string c;
int len;
int ans,sum;

void cal(int l,int r)
{
	if(l==r) return;
	if(l==r-1) return;
	int x=0,y=0;
	for(int i=r-1;i>=l;i--)
	{
		if(c[i]==')')
		{
			y++;
		}
		else
		{
			x++;
		}
		if(x==y)
		{
			if(ans==x+y)
			{
				sum++;
			}
			else if(ans<x+y)
			{
				ans=x+y;
				sum=1;
			}
		}
		if(y<x)
		{
			y=0;
			x=0;
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>c;
	len=c.size();
	int q=0,l=0;
	for(int i=0;i<len;i++)
	{
		if(c[i]=='(')
		{
			q++;
		}
		else
		{
			q--;
		}
		if(q<0)
		{
			cal(l,i);
			q=0;
			l=i+1;
		}
	}
	cal(l,len);
	if(ans==0) sum=1;
	cout<<ans<<' '<<sum<<endl;
	return 0;
}