#include<bits/stdc++.h>
#define ll long long
using namespace std;
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int main()
{
	int T,n;cin>>T;
	while (T--)
	{
		scanf("%d",&n);int i,a[33]={};
		for (i=1;i<=n;i++)
		{
			int t;scanf("%d",&t);
			for (int j=0;j<=30;j++) if (t&(1<<j)) a[j]++;
		}
		int tp=0;
		for (i=0;i<=30;i++) tp=gcd(tp,a[i]);
		for (i=1;i<=n;i++) if (tp%i==0) printf("%d ",i);puts("");
	}
}