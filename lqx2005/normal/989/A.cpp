#include<bits/stdc++.h>
using namespace std;
const int N=1000;
string s;
int slen;
bool vis[3][N+5];
int main()
{
	cin>>s;
	slen=s.length();
	for(int i=1;i<=slen;i++)
	{
		if(s[i-1]=='.') continue;
		if(s[i-1]=='A') vis[0][i-1]=vis[0][i]=vis[0][i+1]=1;
		if(s[i-1]=='B') vis[1][i-1]=vis[1][i]=vis[1][i+1]=1;
		if(s[i-1]=='C') vis[2][i-1]=vis[2][i]=vis[2][i+1]=1;
	}
	for(int i=0;i<=slen+1;i++)
	{
		if(vis[0][i]&&vis[1][i]&&vis[2][i])
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}