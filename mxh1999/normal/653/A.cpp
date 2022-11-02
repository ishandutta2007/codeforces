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

#define maxn 1010
int n;
int a[maxn];
int main()
{
	read(n);
	for (int i=1;i<=n;i++)	read(a[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n;k++)
			if (i!=j && j!=k && k!=i)
			{
				if (abs(a[i]-a[j])<=2 && abs(a[j]-a[k])<=2 && abs(a[k]-a[i])<=2 && a[i]!=a[j] && a[j]!=a[k] && a[k]!=a[i])
				{
					printf("YES\n");
					return 0;
				}
			}
	printf("NO\n");
	return 0;
}