#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))

const int N=100001;
int n,m,T; 
int a[N],dis[N];

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

void work(int l,int r,int d)
{
	if (l>r) return;
	int u=l;
	for (int i=l+1;i<=r;i++) 
	{
		if (a[i]>a[u]) u=i;
	}
	dis[u]=d;
	if (l==r) return;
	work(l,u-1,d+1);
	work(u+1,r,d+1);
	return;
}

int main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		work(1,n,0);
		for (int i=1;i<=n;i++) cout << dis[i] << " ";
		cout << endl;
	}
	return 0;
}