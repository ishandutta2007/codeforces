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
int n;
char c[300005];
bool unc[300005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	scanf("%s",c);
	if(n&1) over(":(");
	int remain=n/2;
	for(int i=0;i<n;i++)
	{
		if(c[i]=='(') remain--;
		if(c[i]=='?') unc[i]=true,c[i]=')';
	}
	for(int i=0;i<n;i++)
	{
		if(unc[i])
		{
			if(remain) c[i]='(',remain--;else c[i]=')';
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(c[i]=='(') cnt++;else cnt--;
		if(i!=n-1 && cnt==0) over(":(");
		if(cnt<0) over(":(");
	}
	if(cnt!=0) over(":(");
	printf("%s",c);
	return 0;
}