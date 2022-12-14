#include<iostream>
#include<cstdio>
using namespace std;
bool used[111111];
int d[111111],n,pos;
char s[111111];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]);
	pos=1;
	while(1)
	{
		if (pos<=0 || pos>n) break;
		if (used[pos])
		{
			cout<<"INFINITE"<<endl;
			return 0;
		}
		used[pos]=1;
		if (s[pos-1]=='>') pos+=d[pos];
		else pos-=d[pos];
	}
	cout<<"FINITE"<<endl;
	return 0;
}