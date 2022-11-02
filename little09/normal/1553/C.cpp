#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=100001;
int n,m,T; 
char a[N];

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
int askmax(int x,int t)
{
	int res=0;
	int s=1;
	if (t==1) s=2;
	for (int i=s;i<=x;i+=2)
	{
		if (a[i]=='?'||a[i]=='1') res++;
	}
	return res;
}
int askmin(int x,int t)
{
	int res=0;
	int s=1;
	if (t==1) s=2;
	for (int i=s;i<=x;i+=2)
	{
		if (a[i]=='1') res++;
	}
	return res;
}
void work()
{
	for (int i=1;i<=10;i++) cin >> a[i];
	for (int i=1;i<=10;i++)
	{
		if (askmax(i,0)>askmin(i,1)+(11-i)/2) 
		{
			cout << i << endl;
			return;
		}
		if (askmax(i,1)>askmin(i,0)+(10-i)/2) 
		{
			cout << i << endl;
			return;
		}
	}
	cout << 10 << endl;
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