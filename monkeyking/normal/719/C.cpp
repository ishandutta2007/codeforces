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
char c[200005];
int k;
int n;
char temp[200005];

void printadd(int l,int r)
{
	temp[0]='0';
	for(int i=l;i<r;i++)
	{
		temp[i+1]=c[i];
	}
	temp[r]++;
	for(int i=r;i>=0;i--)
	{
		if(temp[i]>'9')
		{
			temp[i]='0';
			temp[i-1]++;
		}
		else
		{
			break;
		}
	}
	for(int i=(temp[0]=='0');i<=r;i++)
	{
		putchar(temp[i]);
	}
	puts("");
}

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%d%d%s",&n,&k,c);
	int i;
	for(i=0;i<n;i++)
	{
		if(c[i]=='.') break;
	}
	for(i=i+1;i<n;i++)
	{
		if(c[i]>='5') break;
	}
	if(i==n)
	{
		printf("%s\n",c);
		return 0;
	}
	int add=0;
	while(k)
	{
		if(c[i]<='4') break;
		if(c[i-1]=='.')
		{
			add=1;
			break;
		}
		else
		{
			c[i-1]++;
			if(c[i-1]>'9') c[i-1]='0';
		}
		i--;
		k--;
	}
	i++;
	n=i;
	if(add!=1)
	{
		for(int i=0;i<n;i++)
		{
			putchar(c[i]);
		}
		puts("");
	}
	else
	{
		printadd(0,n-2);
	}
	return 0;
}