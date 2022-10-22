#include<bits/stdc++.h>
#define ll long long
using namespace std;
char a[100010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,flg=0;cin>>n;cin>>a;a[n]=0;
		if (n>=2 && a[0]==a[1])
		{
			putchar(a[0]);
			putchar(a[0]);puts("");continue;
		}
		for (i=1;i<n;i++) if (a[i]>a[i-1]) break;
		flg=i;
			for (i=0;i<flg;i++) putchar(a[i]);
			for (i=flg-1;i>=0;i--) putchar(a[i]);puts("");
	}
}