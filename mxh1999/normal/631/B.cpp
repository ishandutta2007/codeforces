#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int n,m,Q;
int a[maxn],b[maxn];
int tia[maxn],tib[maxn];

int main()
{
	read(n);read(m);read(Q);
	for (int i=1;i<=Q;i++)
	{
		int op,x,y;
		read(op),read(x),read(y);
		if (op==1)
		{
			a[x]=y;
			tia[x]=i;
		}	else
		{
			b[x]=y;
			tib[x]=i;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		if (tia[i]>tib[j])	printf("%d ",a[i]);else printf("%d ",b[j]);
		printf("\n");
	}
	return 0;
}