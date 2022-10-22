#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
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
typedef unsigned long long ull;
using namespace std;
int a[100005],num[100005];

int main()
{
//	freopen("input.txt","r",stdin);
	int n,k,m,t;
	cin>>n>>k>>m;
	rep(n)
	{
		scanf("%d",&num[i]);
		a[num[i]%m]++;
	}
	int maxn=a[0],maxk=0;
	for(int i=0;i<m;i++)
	{
		if(a[i]>maxn) maxn=a[i],maxk=i;
	}
	if(maxn>=k)
	{
		int s=0;
		cout<<"Yes\n";
		rep(n)
		{
			if(num[i]%m==maxk) s++,cout<<num[i]<<' ';
			if(s==k)
			{
				cout<<endl;
				break;
			}
		}
	}
	else
	{
		cout<<"No";
	}
	return 0;
}