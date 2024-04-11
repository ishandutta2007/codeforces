#include<iostream>
#include<cstdio>
using namespace std;
int n,a[2<<17];
long long F[2<<17],S[2<<17];
main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	F[0]=a[0];
	for(int i=1;i<n;i++)
	{
		F[i]=F[i-1]+(i%2?0:a[i]);
		S[i]=S[i-1]+(i%2?a[i]:0);
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if((i>0?F[i-1]:0)+(S[n-1]-S[i])==(i>0?S[i-1]:0)+(F[n-1]-F[i]))cnt++;
	}
	cout<<cnt<<endl;
}