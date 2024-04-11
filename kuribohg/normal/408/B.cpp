#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
char str1[10001],str2[10001];
int a[31],b[31],len1,len2,ans;
int main()
{
	scanf("%s%*c%s%*c",str1,str2);
	len1=strlen(str1);
	len2=strlen(str2);
	for(int i=0;i<len1;i++)
		a[str1[i]-'a'+1]++;
	for(int i=0;i<len2;i++)
		b[str2[i]-'a'+1]++;
	for(int i=1;i<=26;i++)
		if(a[i]==0&&b[i]!=0) {puts("-1");return 0;}
	for(int i=1;i<=26;i++)
		ans+=min(a[i],b[i]);
	printf("%d\n",ans);
	return 0;
}