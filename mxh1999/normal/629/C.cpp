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

const int mo=1e9+7;
#define maxn 2010
ll f[maxn][maxn];
int n,m;
int main()
{
	read(n),read(m);
	f[0][0]=1;
	for (int i=1;i<=n-m;i++)
		for (int j=0;j<=i;j++)
		{
			if (j>0)	f[i][j]=(f[i-1][j-1]+f[i-1][j+1])%mo;
			else f[i][j]=f[i-1][j+1];
		}
	int op=0,from=0;
	for (int i=1;i<=m;i++)
	{
		char ch=getchar();
		while (ch!='(' && ch!=')')	ch=getchar();
		if (ch=='(')	op--;else op++;
		if (op>from)	from=op;
	}
	ll mjy=0;
	n=n-m;
	for (int i=from;i<=n;i++)
		for (int j=from;j<=i;j++)
		if (j-op>=0 && j-op<=n-i)	mjy=(mjy+f[i][j]*f[n-i][j-op])%mo;
	cout<<mjy<<endl;
	return 0;
}