#include<bits/stdc++.h>
#define ll long long
using namespace std;
int sg[1001];
int main()
{
	sg[0]=sg[1]=0;
	int i,j;
	for (j=2;j<=300;j++)
	{
		int tp[10050]={};
		for (i=1;i<=j-1;i++)
		{
			int l=i-1,r=j-(i+1);
			tp[sg[l]^sg[r]]=1;
		}
		for (i=0;i<10024;i++) if (!tp[i]) {sg[j]=i;break;}
	}
	int T;cin>>T;
	while (T--)
	{
		int n,res=0,cntr=0,cntb=0;cin>>n;
		string a;cin>>a;
		for (i=0;i<n;i++) if (a[i]=='R') cntr++;else cntb++;
		for (i=0;i<n-1;i++)
		{
			int cnt=1;
			while (i<n-1 && a[i]!=a[i+1])
			{
				i++;cnt++;
			}
			while (cnt>300) cnt-=34;
			res^=sg[cnt];
		}
		if (res)cntr++;
		if (cntr>cntb) puts("Alice");else puts("Bob");
	}
}