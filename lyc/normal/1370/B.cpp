#include<bits/stdc++.h>
#define N 100000
using namespace std;
int T,n,sum,cnt1,cnt2,a[N],l1[N],l2[N];
signed main()
{
	cin>>T;
	while (T--)
	{
		cin>>n;sum=cnt1=cnt2=0;
		for (int i=1;i<=2*n;i++) 
		{
			cin>>a[i];
			if (a[i]&1) l1[++cnt1]=i; else l2[++cnt2]=i;
		}
		for (int i=1;i<=cnt1;i+=2)
		{
			
			if (sum==n-1) break;
			if (i+1<=cnt1)
			{
			cout<<l1[i]<<" "<<l1[i+1]<<endl;
			sum++;}
		}
		for (int i=1;i<=cnt2;i+=2)
		{
			if (sum==n-1) break;
			if (i+1<=cnt2)
			{
			cout<<l2[i]<<" "<<l2[i+1]<<endl;
			sum++;}
		}
	}
}