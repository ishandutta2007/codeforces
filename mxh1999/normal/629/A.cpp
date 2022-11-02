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

#define maxn 10010
pair<int,int>	a[maxn];
int n,m;
int main()
{
	read(n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			char ch=getchar();
			while (ch!='.' && ch!='C')	ch=getchar();
			if (ch=='C')
			{
				m++;
				a[m]=make_pair(i,j);
			}
		}
	int mjy=0;
	for (int i=1;i<=m;i++)
		for (int j=i+1;j<=m;j++)
		if (a[i].first==a[j].first || a[i].second==a[j].second)	mjy++;
	printf("%d\n",mjy);
	return 0;
}