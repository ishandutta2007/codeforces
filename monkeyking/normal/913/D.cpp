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
int n,time;
int road[200005];

struct form
{
	int problem;
	int need;
	int num;
}a[200005];

bool compare(form a,form b)
{
	return (a.need<b.need);
}

bool check(int k)
{
	int have=time,solve=0;
	for(int i=0;i<n;i++)
	{
		if(a[i].problem<k) continue;
		if(have<a[i].need) break;
		have-=a[i].need;
		solve++;
	}
	return (solve>=k);
}

void print(int k)
{
	int have=time,solve=0;
	for(int i=0;i<n;i++)
	{
		if(a[i].problem<k) continue;
		if(have<a[i].need) break;
		have-=a[i].need;
		road[solve++]=a[i].num+1;
	}
	cout<<k<<endl;
	rep(k)
	{
		cout<<road[i]<<' ';
	}
	cout<<endl;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>time;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].problem,&a[i].need);
		a[i].num=i;
	}
	sort(a,a+n,compare);
	int l=0,r=n,m,ans;
	while(l<=r)
	{
		m=(l+r)>>1;
		if(check(m))
		{
			ans=m;
			l=m+1;
		}
		else
		{
			r=m-1;
		}
	}
	cout<<ans<<Endl;
	print(ans);
	return 0;
}