// Lynkcat.
// Problem: F. Colouring Game
// Contest: Codeforces - CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
// #define N 
using namespace std;
int n;
string st;
const int MAXN = 100010;
int sg[121];
bool vis[121];
int mex(int x)
{
    if(sg[x]!=-1)return sg[x];
    if(x==0||x==1)return sg[x] = 0;
    if(x==2||x==3)return sg[x] = 1;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<x-1;i++)
        vis[mex(i)^mex(x-i-2)] = 1;
    for(int i=0;;i++)
        if(!vis[i]) return sg[x] = i;
}
int SG(int x)
{
    if(x<=120) return sg[x];
    x=x%34+2*34;
    return sg[x];
}
void BellaKira()
{
	cin>>n;
	cin>>st;
	int x=0,y=0;
	for (auto u:st)
		if (u=='R') x++;
		else y++;
	if (x>y) cout<<"Alice"<<endl;
	else if (x<y) cout<<"Bob"<<endl;
	else
	{
		int p=0;
		poly g;
		int lst=1,y=0;
		if (st[0]=='B') y=0;
		else y=1;
		for (int i=1;i<=n;i++)
		{
			if (st[i]==st[i-1]||i==n)
			{
				p^=SG(lst);
				lst=1;
			} else lst++;
		}
		if (p) cout<<"Alice"<<endl;
		else  cout<<"Bob"<<endl;
	}
		
			
	
}
signed main()
{
	memset(sg,-1,sizeof(sg));
    for(int i = 0;i <= 120;i++)
        sg[i] = mex(i);
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}