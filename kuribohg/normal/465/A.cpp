#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,ans;
char a[1010],b[1010];
int main()
{
	scanf("%d%s",&n,a);
	for(int i=0;i<n;i++) b[i]=a[i];
	for(int i=0;i<n;i++)
	{
		if(a[i]=='0') {a[i]++;break;}
		else a[i]='0';
	}
	for(int i=0;i<n;i++) if(a[i]!=b[i]) ans++;
	printf("%d\n",ans);
	return 0;
}