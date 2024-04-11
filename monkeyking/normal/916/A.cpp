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

bool have(int x)
{
	int t=x;
	while(t)
	{
		if(t%10==7) return true;
		t/=10;
	}
	return false;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int x,h,m;
	cin>>x>>h>>m;
	int ans=175082375;
	int th,tm,d;
	for(int i=0;i<24;i++)
	{
		for(int j=0;j<60;j++)
		{
			if(!have(i) && !have(j)) continue;
			else if(i>h) th=h+24-i;
			else if(i==h && j==m)
			{
				cout<<0<<endl;
				return 0;
			}
			else if(i==h && j>m)
			{
				th=24;
			}
			else
			{
				th=h-i;
			}
//			cout<<th<<endl;
//			if(tm>m) tm+=60,th--;
			d=(th)*60+(m-j);
			if(d%x) continue;
//			if(d/x<ans)
//			{
//				cout<<i<<' '<<j<<' ';
//				cout<<th<<' '<<m-tm<<endl;
//			}
			ans=min(ans,d/x);
		}
	}
	cout<<ans<<Endl;
	return 0;
}