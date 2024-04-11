#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <assert.h>
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
int n;
int a[300005];
pair<int,int> que[300005];
int len;

//int bs1(int i)
//{
//	int l=0,r=len-1,m,res;
//	while(l<=r)
//	{
//		m=l+r>>1;
//		if(que[m].second>=i)
//		{
//			res=m;
//			l=m-1;
//		}
//		else
//		{
//			r=m+1;
//		}
//	}
//	return res;
//}

int bs2(int i,int value)
{
	int l=i,r=len-1,m,res=-1;
	while(l<=r)
	{
		m=l+r>>1;
		if(que[m].first<value)
		{
			res=m;
			l=m+1;
		}
		else
		{
			r=m-1;
		}
	}
	if(res==-1) return inf;
	return que[res].second;
}

void print()
{
	cout<<"size: "<<len<<endl;
	for(int i=0;i<len;i++)
	{
		cout<<que[i].first<<'-'<<que[i].second<<endl;
	}
	cout<<endl;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=n;i<3*n;i++)
	{
		a[i]=a[i-n];
	}
	int mx=-1,mn=inf;
	for(int i=0;i<n;i++)
	{
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	if(mn*2>=mx)
	{
		for(int i=0;i<n;i++)
		{
			cout<<-1<<' ';
		}
		cout<<endl;
		return 0;
	}
	vector <int> res;
	int pre=inf;
	int cur=a[n];
	for(int i=n;i<3*n;i++)
	{
		if(cur>a[i]*2)
		{
			pre=i;
			break;
		}
		cur=max(cur,a[i]);
	}
//	cout<<pre<<endl;
	for(int i=3*n-1;i>=0;i--)
	{
		if(i<n)
		{
			if(a[i+1]>a[i])
			{
				assert(pre!=inf);
				res.push_back(pre);
			}
			else
			{
//				print();
				int pos=bs2(0,a[i]);
//				cout<<pos<<endl;
				if(pos>pre)
				{
					pos=pre;
				}
//				cout<<pos<<endl;
				res.push_back(pos);
				pre=pos;
//				int pos=lower_bound(que,que+n,a[i]);
			}
		}
		while(len && a[i]*2<=que[len-1].first)
		{
			len--;
		}
		que[len].first=a[i]*2;
		que[len].second=i;
		len++;
	}
	reverse(all(res));
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]-i<<' ';
	}
	cout<<endl;
	return 0;
}