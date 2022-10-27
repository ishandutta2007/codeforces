#include<iostream>
#include<fstream>
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

int n, b[4];
string S[4];
int ans=inf;

void addans()
{
	cerr<<b[0]<<' '<<b[1]<<' '<<b[2]<<' '<<b[3]<<"\n";
	int ret=0;
	for (int i=0; i<4; i++) for (int j=0; j<n*n; j++) ret+=((S[i][j]-'0')==((b[i]+j)%2));
	ans=min(ans, ret);
}

void BF(int u, int i, int j)
{
	if (u==4)
	{
		addans();
		return;
	}
	
	if (i>0) 
	{
		b[u]=0;
		BF(u+1, i-1, j);
	}
	if (j>0)
	{
		b[u]=1;
		BF(u+1, i, j-1);
	}
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	string t;
	for (int i=0; i<4; i++) 
	{
		S[i]="";
		for (int j=0; j<n; j++)
		{
			cin>>t;
			S[i]+=t;
		}
	}
	
	BF(0, 2, 2);
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: