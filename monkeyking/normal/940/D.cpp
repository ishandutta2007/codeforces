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
int a[100005];
char b[100005];
vector <pair<char,int> >l,r;

int all(int k)
{
	int res=b[k-4];
	for(int i=k-3;i<k;i++)
	{
		if(res!=b[i]) return -1;
	}
	return res;
}

int min(int k)
{
	int res=a[k-4];
	for(int i=k-3;i<=k;i++)
	{
		res=min(res,a[i]);
	}
	return res;
}

int max(int k)
{
	int res=a[k-4];
	for(int i=k-3;i<=k;i++)
	{
		res=max(res,a[i]);
	}
	return res;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	rep(n)
	{
		scanf("%d",a+i);
	}
	scanf("%s",b);
	for(int i=4;i<n;i++)
	{
		if(b[i]==b[i-1])
		{
			if(all(i)==-1) continue;
			if(all(i)=='1')
			{
				r.push_back(mp('>',min(i)-1));
			}
			else
			{
				l.push_back(mp('<',max(i)+1));
			}
		}
		else
		{
			if(b[i]=='1')
			{
				l.push_back(mp('>',max(i)));
			}
			else
			{
				r.push_back(mp('<',min(i)));
			}
		}
	}
	int low=-1000000000,high=1000000000;
	rep(l.size())
	{
		if(l[i].first=='>')
		{
			low=max(low,l[i].second+1);
		}
		else
		{
			high=min(high,l[i].second-1);
		}
//		printf("l%c%d\n",l[i].first,l[i].second);
	}
	cout<<low<<endl;
	low=-1000000000;
	high=1000000000;
	rep(r.size())
	{
		if(r[i].first=='>')
		{
			low=max(low,r[i].second+1);
		}
		else
		{
			high=min(high,r[i].second-1);
		}
//		printf("l%c%d\n",l[i].first,l[i].second);
	}
	cout<<high<<endl;
	return 0;
}