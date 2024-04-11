#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
int cnt[100];char s1[101000],s2[101000],s3[101000];
map<char,int> mp;
int main()
{
	int n;int max1=0,max2=0,max3=0;
	scanf("%d%s%s%s",&n,s1,s2,s3);
	for(int i=0;i<26;i++)mp[i+'a']=i+1,mp[i+'A']=i+27;
	int len=strlen(s1);
	for(int i=0;i<len;i++)cnt[mp[s1[i]]]++;
	for(int i=1;i<=54;i++)max1=max(max1,cnt[i]);memset(cnt,0,sizeof(cnt));
	for(int i=0;i<len;i++)cnt[mp[s2[i]]]++;
	for(int i=1;i<=54;i++)max2=max(max2,cnt[i]);memset(cnt,0,sizeof(cnt));
	for(int i=0;i<len;i++)cnt[mp[s3[i]]]++;
	for(int i=1;i<=54;i++)max3=max(max3,cnt[i]);memset(cnt,0,sizeof(cnt));
	if(max1==len&&n==1)max1--;
	else if(n==1)max1++;
	if(max2==len&&n==1)max2--;
	else if(n==1)max2++;
	if(max3==len&&n==1)max3--;
	else if(n==1)max3++;
	if(n!=1)
	{
		max1=min(len,n+max1);
		max2=min(len,n+max2);
		max3=min(len,n+max3);
	}
	int Max=max(max(max1,max2),max3);
	if(max1==Max&&max2==Max||max1==Max&&max3==Max||max2==Max&&max3==Max)return 0*puts("Draw");
	if(max1==Max)return 0*puts("Kuro");
	if(max2==Max)return 0*puts("Shiro");
	if(max3==Max)return 0*puts("Katie");
}