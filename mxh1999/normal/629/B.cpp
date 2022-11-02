#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 5010
int x[maxn],y[maxn],op[maxn];
int n,m;
int main()
{
	read(n);
	for (int i=1;i<=n;i++)
	{
		char ch=getchar();
		while (ch!='M' && ch!='F')	ch=getchar();
		if (ch=='M')	op[i]=1;else op[i]=2;
		read(x[i]),read(y[i]);
		if (x[i]>y[i])	swap(x[i],y[i]);
	}
	int mjy=0;
	for (int i=1;i<=366;i++)
	{
		int male=0,f=0;
		for (int j=1;j<=n;j++)
		if (i<=y[j] && i>=x[j])
		{
			if (op[j]==1)	male++;
			else f++;
		}
		mjy=max(mjy,min(male,f));
	}
	cout<<mjy*2<<endl;
	return 0;
}