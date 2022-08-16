#include<cstdio>
#include<iostream>

using namespace std;

int calc(char c,int x,int y)
{
	if (c=='&')
		return x&y;
	if (c=='|')
		return x|y;
	if (c=='^')
		return x^y;
}

int solve()
{
	char c;
	scanf("%c",&c);
	if (c=='0')
		return 1;
	if (c=='1')
		return 8;
	if (c=='?')
		return 6;
	int x=solve();
	scanf("%c",&c);
	int y=solve();
	int p=0;
	for (int i=0;i<4;++i) if (x&(1<<i))
		for (int j=0;j<4;++j) if (y&(1<<j))
			p|=1<<calc(c,i,j);
	scanf("%c",&c);
	return p;
}

int main()
{
	int tmp;
	scanf("%d ",&tmp);
	puts((solve()&6)?"YES":"NO");
	return 0;
}