#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
long long n,a[11];
long long t,ans,mn;
long long Pow(int n,int i)
{
    long long p=1;
    for (int j=1;j<=i;j++)
    {
        p=p*n;
    }
    return p;
}
void doo(int t)
{
	sort(a,a+t);
	reverse(a,a+t);
	ans=1;
	for (int i=0;i<t;i++)
	{
		ans=ans*Pow(prime[i],a[i]-1);
	}
	if (ans>0) mn=min(ans,mn);
}
void doit(int n)
{
	int i=0;
	while(n>1)
	{
		if (n%prime[i]==0) 
		{
			a[t++]=prime[i];
			n/=prime[i];
		}
		else i++;
	}
}
void back(int t)
{
	doo(t);
	if (t==1) return;
	long long b[11];
	for (int i=0;i<t;i++) b[i]=a[i];
	for (int i=0;i<t;i++)
	{
		for (int j=i+1;j<t;j++)
		{
			a[i]=a[i]*a[j];
			for (int k=j+1;k<t;k++) a[k-1]=a[k];
			back(t-1);
			for (int k=0;k<t;k++) a[k]=b[k];
		}
	}
}
int main()
{
	mn=1e18;
	cin>>n;
	doit(n);
	back(t);
	cout<<mn<<endl;
	return 0;
}