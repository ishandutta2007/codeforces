#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100010],h[100010],r[100010],ls[100010];
int main()
{
	int n,i,j,k,e=0,nw=0,t=0,ans=0;cin>>n;
	for (i=1;i<=n;i++) cin>>a[i],h[a[i]]++;
	for (i=1;i<=100000;i++) if (h[i]) e++,ls[j]=t,t=j;ls[100001]=t;
	for (i=1;i<=n;i++)
	{
		r[a[i]]++;int flg=0;
		for (j=1;j<=10;j++)
		{
			int t=0,tst=1;r[j]--;
			for (k=1;k<=10;k++) if (r[k]) {if (!t) t=r[k];else if (t!=r[k]) {tst=0;break;}}
			r[j]++;
			if (tst==1) {flg=1;break;}
		}
		if (flg) ans=i;
	}
	cout<<ans;
}