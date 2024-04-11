#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
char a[100010],b[100010];
int len1,len2,ans;
char ch1[10],ch2[10];
int main()
{
	scanf("%s%*c%s%*c",a,b);
	len1=strlen(a);
	len2=strlen(b);
	if(len1!=len2) {puts("NO");return 0;}
	for(int i=0;i<len1;i++)
		if(a[i]!=b[i])
		{
			ans++;
			ch1[ans]=a[i],ch2[ans]=b[i];
			if(ans>2) break;
		}
	if(ans>2) puts("NO");
	else
	{
		if(ch1[1]==ch2[2]&&ch1[2]==ch2[1]) puts("YES");
		else puts("NO");
	}
	return 0;
}