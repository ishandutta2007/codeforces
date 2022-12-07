#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int k,len;
char s[100010];
bool palindrome(int l,int r)
{
	for(int i=0;i<=r-l;i++)
		if(s[l+i]!=s[r-i]) return false;
	return true;
}
int main()
{
	scanf("%s%d",s,&k);
	len=strlen(s);
	if(len%k) {puts("NO");return 0;}
	for(int i=0;i<len;i+=len/k)
		if(!palindrome(i,i+len/k-1)) {puts("NO");return 0;}
	puts("YES");
	return 0;
}