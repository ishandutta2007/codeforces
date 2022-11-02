#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=100001;
int n,m,T; 
int a[N],s[N];

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
	for (int i=1;i<=n;i++) 
	{
		char x;
		cin >> x;
		if (x=='M') a[i]=1;
		else a[i]=0;
	}
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	if (s[n]!=n/3) 
	{
		puts("NO");
		return; 
	}
	for (int i=1;i<=n;i++)
	{
		if (a[i]==1&&(i-1-s[i-1]<=s[i-1])) 
		{
			puts("NO");
			return; 	
		}
	}
	s[n+1]=0;
	for (int i=n;i>=1;i--) s[i]=s[i+1]+a[i];
	for (int i=1;i<=n;i++)
	{
		if (a[i]==1&&(n-i-s[i+1]<=s[i+1])) 
		{
			puts("NO");
			return; 	
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