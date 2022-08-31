#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<map>

using namespace std;

const int MaxN=110;

char s[MaxN];
map<string,int> H;

int check(int L,int R)
{
	for (int i=R,p=0;i>=L;--i)
	{
		if (s[i]=='(') ++p;
		if (s[i]==')') --p;
		if (!p&&(s[i]=='+'||s[i]=='-'))
		{
			int Lc=check(L,i-1),Rc=check(i+1,R);
			if (!Lc||!Rc||s[i]=='-'&&Rc==1) return 0;
			return 1;
		}
	}
	for (int i=R,p=0;i>=L;--i)
	{
		if (s[i]=='(') ++p;
		if (s[i]==')') --p;
		if (!p&&(s[i]=='*'||s[i]=='/'))
		{
			int Lc=check(L,i-1),Rc=check(i+1,R);
			if (!Lc||!Rc||Lc==1||Rc==1||s[i]=='/'&&Rc==2) return 0;
			return 2;
		}
	}
	if (s[L]=='(')
	{
		if (check(L+1,R-1))
			return 3;
		return 0;
	}
	string t="";
	for (int i=L;i<=R;++i)
		t+=s[i];
	if (H.find(t)!=H.end())
		return H[t];
	else
		return 3;
}

int main()
{
	int T;
	cin>>T;
	++T;
	while (T--)
	{
		char now[MaxN];
		if (T) scanf(" #%s%s",s,now);
		gets(s);
		int n=strlen(s),m=0;
		for (int i=0;i<n;++i)
			if (s[i]!=' ') s[m++]=s[i];
		s[m]=0;
		int p=check(0,m-1);
		if (T)
			H[now]=p;
		else
			puts(p?"OK":"Suspicious");
	}
	return 0;
}