#include <bits/stdc++.h>
using namespace std;
int n,l;
int k=30;
long long int inf=5*1e18;
long long int c[60];
long long int s=0;
long long int a=inf;
long long int halt(long long int p)
{
	long long int q=1;
	int t=0;
	while(q<p)
	{
		q=(q<<1);
		t++;
	}
	return c[t];
}
int main()
{
	for(int i=0;i<=30;i++) c[i]=inf;
	cin>>n>>l;
	for(int i=0;i<n;i++) cin>>c[i];
	for(int i=0;i<30;i++) if(c[i+1]>2*c[i]) c[i+1]=2*c[i];
	for(int i=30;i>0;i--) if(c[i]<c[i-1]) c[i-1]=c[i];
	long long int r=1073741824;
	while(k>-1)
	{
		if(s+halt(l)<a) a=s+halt(l);
		if((r&l))
		{
			s+=c[k];
			l-=r;
		}
		k--;
		r=(r>>1);
	}
	cout<<a<<endl;
	return 0;
}