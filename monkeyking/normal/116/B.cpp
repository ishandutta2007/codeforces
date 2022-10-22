#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
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
#define For(I,N) for(int I=0;I<N;I++)
typedef unsigned long long ull;
using namespace std;
char a[15][15];
bool use[15][15];

int main()
{
//	freopen("input.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a[i]+1);
	}
	int s=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='P')
			{
				bool f=false;
				if(a[i-1][j]=='W' && !use[i-1][j])
				{
					s++;
					use[i-1][j]=true;
				}
				else if( a[i+1][j]=='W'&&!use[i+1][j])
				{
					s++;
					use[i+1][j]=true;
				}
				else if(a[i][j-1]=='W' && !use[i][j-1])
				{
					s++;
					use[i][j-1]=true;
				}
				else if(a[i][j+1]=='W' && !use[i][j+1])
				{
					s++;
					use[i][j+1]=true;
				}
			}
		}
	}
	cout<<s<<endl;
	return 0;
}