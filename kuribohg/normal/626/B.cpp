#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,r,g,b;
char s[210];
int f[210][210][210];
int main()
{
	scanf("%d%s",&n,s);
	for(int i=0;i<n;i++)
		if(s[i]=='R') r++;
		else if(s[i]=='G') g++;
		else b++;
	f[r][g][b]=1;
	for(int S=n;S>1;S--)
	{
		for(int i=0;i<=S;i++)
			for(int j=0;j+i<=S;j++)
				if(f[i][j][S-i-j])
				{
					if(i>=1&&j>=1) f[i-1][j-1][S-i-j+1]=1;
					if(j>=1&&S-i-j>=1) f[i+1][j-1][S-i-j-1]=1;
					if(i>=1&&S-i-j>=1) f[i-1][j+1][S-i-j-1]=1;
					if(i>=2) f[i-1][j][S-i-j]=1;
					if(j>=2) f[i][j-1][S-i-j]=1;
					if(S-i-j>=2) f[i][j][S-i-j-1]=1;
				}
	}
	if(f[0][0][1]) putchar('B');
	if(f[0][1][0]) putchar('G');
	if(f[1][0][0]) putchar('R');
	return 0;
}