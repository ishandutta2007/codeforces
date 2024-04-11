#include<bits/stdc++.h>
using namespace std;
char a[10010];
int main()
{
	cin>>a+1;int n=strlen(a+1),i,j,mid=n/2;
	if (n==1 || n==2){puts("Impossible");exit(0);}
	for (i=mid;i>=1;i--)
	{
		for (j=1;j<=i;j++) if (a[j]!=a[i-j+1]) break;
		if (j!=i+1) break;
	}
	if (!i){puts("Impossible");exit(0);}
	if (i*2==n) cout<<1;else
	{
		for (i=n+1;i<=2*n;i++) a[i]=a[i-n];
		for (i=2;i<=n;i++)
		{
			for (j=i;j<=i+n-1;j++) {if (a[j]!=a[i+i+n-j-1]) break;}
			if (j==i+n)
			{
				for (j=i;j<=i+n-1;j++) if (a[j]!=a[j-i+1]) break;
				if (j!=i+n) {cout<<1;exit(0);}
			}
		}
		cout<<2;
	}
}