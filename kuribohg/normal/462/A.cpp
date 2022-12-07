#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int n;
char a[1010][1010];
bool p=true;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			int x=0;
			for(int k=0;k<4;k++)
				if(a[i+dx[k]][j+dy[k]]=='o') x++;
			if(x%2==1) {p=false;break;}
		}
	if(p) puts("YES");
	else puts("NO");
	return 0;
}