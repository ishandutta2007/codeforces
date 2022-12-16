#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
char s[100005];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='A'||s[i]=='a'||s[i]=='O'||s[i]=='o'||s[i]=='Y'||s[i]=='y'||s[i]=='E'||s[i]=='e'||s[i]=='U'||s[i]=='u'||s[i]=='i'||s[i]=='I') continue;
		else if(s[i]>='a'&&s[i]<='z') cout<<"."<<s[i];
		else printf(".%c",s[i]+'a'-'A');
	}
}