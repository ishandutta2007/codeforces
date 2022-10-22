#include<iostream>
using namespace std;
int a[1010],b[1010],p[1010],cnt;
int main()
{
	int n,i,j,k,flg;cin>>n;
	for (i=1;i<=n;i++) cin>>a[i],b[i]=a[i]-a[i-1];
	for (i=1;i<=n;i++)
	{
		flg=0;
		for (j=1;j<=i;j++)
		{
			for (k=j;k<=n;k+=i) if (b[k]!=b[j]) {flg=1;break;}
			if (flg) break;
		}
		if (!flg) {p[++cnt]=i;}
	}
	cout<<cnt<<endl;for (i=1;i<=cnt;i++) cout<<p[i]<<' ';
}