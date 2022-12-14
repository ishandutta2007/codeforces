#include<bits/stdc++.h>
using namespace std;
char opt[10];
int ask(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	scanf("%s",opt);
	if (opt[0]=='N') return 0;
	return 1;
}
void clear()
{
	printf("R\n");
	fflush(stdout);
}
void report(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
}
int n,k,N,l,r,cnt;
bool f,lcyfucklrt[2222];
void access(int x)
{
	for (int i=x*k+1;i<=x*k+k;i++)
	{
		if (lcyfucklrt[i]) continue;
		if (ask(i)) lcyfucklrt[i]=1;
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	N=n/k;
	for (int i=0;i<N;i++)
	{
		l=(i+N-1)%N;r=(i+1)%N;f=0;
		access(i);
		for (int j=1;j<N;j++)
		{
			if (f) 
			{
				access(r);
				r=(r+1)%N;
				f=0;
			}
			else
			{
				access(l);
				l=(l+N-1)%N;
				f=1;
			}
		}
		clear();
	}
	for (int i=1;i<=n;i++) 
	{
		if (!lcyfucklrt[i]) cnt++;
	}
	report(cnt);
	return 0;
}