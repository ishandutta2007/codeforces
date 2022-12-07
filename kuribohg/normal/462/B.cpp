#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,m,c[110];
long long ans;
char s[100010];
int main()
{
	scanf("%d%d%s",&n,&m,s);
	for(int i=0;i<n;i++) c[s[i]-'A']++;
	sort(c,c+26);
	for(int i=25;i>=0;i--)
	{
		if(c[i]<=m) m-=c[i],ans+=(long long)c[i]*c[i];
		else {ans+=(long long)m*m;break;}
	}
	printf("%I64d\n",ans);
	return 0;
}