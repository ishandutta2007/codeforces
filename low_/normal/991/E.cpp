#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005
#define FLN "test"

int cnt[15], temp[15];
int n, ans=0;
int fact[20];

int cur_tinh()
{
	int ret=0;
	for (int i=0; i<10; i++) ret+=temp[i];
	ret=fact[ret];
	for (int i=0; i<10; i++) ret/=fact[temp[i]];
	return ret;
}

void calc()
{
	int ret=cur_tinh();
	if (temp[0]==0) 
	{
		ans+=ret;
		return;
	}
	
	temp[0]--;
	ret-=cur_tinh();
	temp[0]++;
	ans+=ret;
}

void duyet(int u)
{
	if (u==10) 
	{
		calc();
		return;
	}
	
	if (cnt[u]==0) duyet(u+1);
	else
	{
		for (int i=1; i<=cnt[u]; i++) 
		{
			temp[u]=i;
			duyet(u+1);
		}
	}
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	fact[0]=1;
	for (int i=1; i<20; i++) fact[i]=fact[i-1]*i;
	for (int i=0; i<10; i++) cnt[i]=0;
	cin>>n;
	while (n>0)
	{
		cnt[n%10]++;
		n/=10;
	}
	for (int i=0; i<10; i++) temp[i]=0;
	duyet(0);
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: