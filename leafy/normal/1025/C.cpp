#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
char s[1000005];
int f[1000005];
int main() 
{
	scanf("%s",s);int n=strlen(s);
	for(int i=0;i<n;i++) s[i+n]=s[i];
	n=2*n;
	f[0]=1;int ans=1;
	for(int i=1;i<n;i++)
		if(s[i]!=s[i-1]) f[i]=f[i-1]+1,ans=max(ans,f[i]);
		else f[i]=1;
	cout<<min(ans,n>>1);
    return 0;
}