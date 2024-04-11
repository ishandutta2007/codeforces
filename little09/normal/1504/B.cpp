#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=500001;
int n,m,T; 
char a[N],b[N];

inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 

void work()
{
	n=read();
	cin >> a >> b;
	int u=0,las=0;
	for (int i=0;i<n;i++)
	{
		if (a[i]=='0') u++;
		else u--;
		if (u==0)
		{
			int flag1=0,flag2=0;
			for (int j=las;j<=i;j++)
			{
				if (a[j]!=b[j]) flag1=1;
				else flag2=1;
			}
			if (flag1==1&&flag2==1)
			{
				puts("NO");
				return;
			}
			las=i+1;
		}
	}
	if (las!=n)
	{
		for (int i=las;i<n;i++)
		{
			if (a[i]!=b[i])
			{
				puts("NO");
				return;		
			}
		} 
	}
	puts("YES");
	return;
}

int main()
{
	T=read();
	while (T--)
	{
		work();
	}
	return 0;
}