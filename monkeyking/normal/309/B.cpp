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
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n,r,c;
string word[1000005];
int len[1000005];
int nxt[1000005];
pair<int,int> st[1000005][22];
int sum[1000005];

int calc(int start)
{
//	if(start!=0) return -1;
	int res=0;
	for(int i=0;i<22;i++)
	{
		if((1<<i) & r)
		{
			res+=st[start][i].second;
			start=st[start][i].first;
		}
	}
//	cout<<res<<endl;
	return res;
}

void print(int start)
{
	for(int i=0;i<r;i++)
	{
		if(start==n) break;
		for(int j=start;j<nxt[start];j++)
		{
			cout<<word[j];
			if(j!=nxt[start]-1) cout<<' ';
		}
		cout<<endl;
		start=nxt[start];
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n>>r>>c;
	for(int i=0;i<n;i++)
	{
		cin>>word[i];
		len[i]=word[i].size();
	}
	sum[0]=len[0]+1;
	for(int i=1;i<n;i++)
	{
		sum[i]=sum[i-1]+len[i]+1;
	}
	for(int i=0,j=0;i<n;i++)
	{
		while(j<n && sum[j]-(i?sum[i-1]:0)-1<=c) j++;
		nxt[i]=j;
	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<nxt[i]<<' ';
//	}
//	cout<<endl;
	for(int i=0;i<n;i++)
	{
		st[i][0]=mp(nxt[i],nxt[i]-i);
	}
	for(int i=0;i<22;i++)
	{
		st[n][i]=mp(n,0);
	}
	for(int k=1;k<22;k++)
	{
		for(int i=0;i<n/*-(1<<k)+1*/;i++)
		{
			st[i][k].first=st[st[i][k-1].first][k-1].first;
			st[i][k].second=st[i][k-1].second+st[st[i][k-1].first][k-1].second;
		}
	}
	int res=-1,maxk=-1;
	int temp;
	for(int i=0;i<n;i++)
	{
		temp=calc(i);
		if(temp>res)
		{
			res=temp;
			maxk=i;
		}
	}
	print(maxk);
	return 0;
}