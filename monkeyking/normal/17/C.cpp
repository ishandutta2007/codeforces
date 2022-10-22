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
#include <assert.h>
#include <bitset>
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
const int mod=51123987;
using namespace std;
//int dp[55][55][55][3];
//bool have[155][155][3];
char str[155];
int n;
int dp[155][55][55][55];
int nxt[155][3];
vector <char> c;

inline void upd(int &x,int y)
{
	x+=y;
	if(x>=mod) x-=mod;
}

int main() 
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	scanf("%s",str);
	for(int i=0;i<n;i++)
	{
		c.push_back(str[i]);
	}
	c.erase(unique(all(c)),c.end());
	int len=c.size();
	for(int ch=0;ch<3;ch++)
	{
		nxt[len][ch]=len;
		for(int i=len-1;i>=0;i--)
		{
			nxt[i][ch]=nxt[i+1][ch];
			if(c[i]==ch+'a') nxt[i][ch]=i;
		}
	}
	dp[0][0][0][0]=1;
	for(int s=0;s<n;s++)
	{
		for(int i=0;i<len;i++)
		{
			for(int a=0;a<=50;a++)
			{
				for(int b=0;b<=50;b++)
				{
					int c=s-a-b;
					if(c<0) break;
					if(c>50) continue;
					int &t=dp[i][a][b][c];
					upd(dp[nxt[i][0]][a+1][b][c],t);
					upd(dp[nxt[i][1]][a][b+1][c],t);
					upd(dp[nxt[i][2]][a][b][c+1],t);
				}
			}
		}
	}
	int res=0;
	for(int a=0;a<=50;a++)
	{
		for(int b=0;b<=50;b++)
		{
			for(int c=0;c<=50;c++)
			{
				if(max(max(a,b),c)-min(min(a,b),c)>1) continue;
				if(a+b+c!=n) continue;
				for(int i=0;i<len;i++)
				{
					upd(res,dp[i][a][b][c]);
				}
			}
		}
	}
	cout<<res<<endl;
	return 0;
}