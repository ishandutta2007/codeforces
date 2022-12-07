#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int a[5],len,ans;
char ch[100010];
int main()
{
	for(int i=1;i<=4;i++) scanf("%d",&a[i]);
	scanf("%s",ch);
	len=strlen(ch);
	for(int i=0;i<len;i++) ans+=a[ch[i]-'0'];
	printf("%d\n",ans);
	return 0;
}