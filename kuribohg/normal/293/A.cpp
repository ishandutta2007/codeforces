#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,pair11,pair10,pair01,pair00,ans1,ans2;
char str1[3000010],str2[3000010];
int main()
{
	scanf("%d%s%s",&n,str1,str2);
	for(int i=0;i<n+n;i++)
	{
		if(str1[i]=='0'&&str2[i]=='0') pair00++;
		if(str1[i]=='1'&&str2[i]=='0') pair10++;
		if(str1[i]=='0'&&str2[i]=='1') pair01++;
		if(str1[i]=='1'&&str2[i]=='1') pair11++;
	}
	for(int i=1;i<=n;i++)
	{
		if(pair11) pair11--,ans1++;
		else if(pair10) pair10--,ans1++;
		else if(pair01) pair01--;
		else if(pair00) pair00--;
		if(pair11) pair11--,ans2++;
		else if(pair10) pair10--;
		else if(pair01) pair01--,ans2++;
		else if(pair00) pair00--;
	}
	if(ans1>ans2) puts("First");
	else if(ans1<ans2) puts("Second");
	else puts("Draw");
	return 0;
}