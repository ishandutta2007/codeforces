//Author:mxh1999
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

map<string,int>	hong;
int n,m;
char s[10010];
string f;

//0 = !
//1 = ok
//2 = -*/
//3 = /
int calc(int l,int r)
{
	for (int i=r,w=0;i>=l;i--)
	{
		w+=s[i]=='(';
		w-=s[i]==')';
		if (w==0 && (s[i]=='+' || s[i]=='-'))
		{
			int x=calc(l,i-1),y=calc(i+1,r);
			if (!x || !y)	return 0;
			if (s[i]=='+')	return 2;
			if (s[i]=='-')	return y==2?0:2;
		}
	}
	for (int i=r,w=0;i>=l;i--)
	{
		w+=s[i]=='(';
		w-=s[i]==')';
		if (w==0 && (s[i]=='*' || s[i]=='/'))
		{
			int x=calc(l,i-1),y=calc(i+1,r);
			if (!x || !y)	return 0;
			if (s[i]=='*')	return (x==2 || y==2)?0:3;
			if (s[i]=='/')	return (x==2 || y==2 || y==3)?0:3;
		}
	}
	if (s[l]=='(')	return calc(l+1,r-1)==0?0:1;
	string tmp;
	for (int i=l;i<=r;i++)	tmp+=s[i];
	return hong.count(tmp)?hong[tmp]:1;
}
int q()
{
	gets(s);
	m=0;
	for (int i=0;i<strlen(s);i++)
	if (s[i]!=' ')
	{
		s[m++]=s[i];
	}
	s[m]=0;
	return calc(0,m-1);
}
int main()
{
	int test;
	//scanf("%d",&test);
	test=1;
	while (test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			char ch=getchar();
			while (ch!='#')	ch=getchar();
			while (ch!='d')	ch=getchar();
			while (ch!=' ')	ch=getchar();
			cin>>f;
			hong[f]=q();
			//cout << f << " " << hong[f]<< endl;
		}
		int tmp=q();
		if (tmp==0)	printf("Suspicious\n");else printf("OK\n");
	}
	return 0;
}