#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
char c[101000];
int main()
{
	int n;scanf("%d",&n);scanf("%s",c);int ans=0;
	for(int i=0;i<n;i++)
	{
		int lx=0;
		while(c[i]=='x'){lx++;i++;}ans+=max(0,lx-2);
	}cout<<ans;
	return 0;
}