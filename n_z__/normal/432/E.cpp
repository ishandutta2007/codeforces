#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
inline int work(int x,int y)
{
	if(a[x][y])return a[x][y];
	for(int now=1;now<=26;now++)
	if(a[x-1][y]!=now&&a[x][y-1]!=now&&a[x+1][y]!=now&&a[x][y+1]!=now)
	return now;	
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int x=1;x<=n;x++)
	for(int y=1;y<=m;y++)
	{
		if(a[x][y])continue;
		int t=work(x,y),k=0;
		while(work(x,y+k)==t&&x+k<=n&&y+k<=m)
		k++;
		for(int q=x;q<x+k;q++)
		for(int p=y;p<y+k;p++)
		a[q][p]=t;
	}
	for (int x=1;x<=n;x++)
	{
		for (int y=1;y<=m;y++)
		cout<<(char)(a[x][y]-1+'A');
		cout<<endl;
	}
}