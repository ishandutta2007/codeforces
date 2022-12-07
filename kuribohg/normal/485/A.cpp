#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=100010;
int x,m;
bool used[MAXN];
int main()
{
	scanf("%d%d",&x,&m);
	for(int i=0;i<=m;i++)
	{
		used[x]=true;
		x=(x+x%m)%m;
	}
	if(!used[0]) puts("No");
	else puts("Yes");
	return 0;
}