#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
double a[maxn],b[maxn],f[maxn],e[maxn];
int n; 
char g[maxn];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>e[i];
		a[i]=(a[i-1]+1)*e[i];
		b[i]=(b[i-1]+2*a[i-1]+1)*e[i]+b[i-1]*(1-e[i]);
	}
	printf("%.7lf",b[n]);
	return 0;
}