#include <iostream>
#include <algorithm>
#include <complex>
#include <vector>
using namespace std;
int x,arr[200005];
typedef complex<double> cpx;
#define pi acos(-1)
void fft(vector<cpx>& a,bool inv)
{
	int n=a.size();
	if (n==1)
	return;
	vector<cpx> even(n/2),odd(n/2);
	for (int i=0;i<n/2;i++)
	{
		even[i]=a[2*i];
		odd[i]=a[2*i+1];
	}
	fft(even,inv);
	fft(odd,inv);
	double angle=2*pi/n*(inv? -1:1);
	cpx w(1,0),wn(cos(angle),sin(angle));
	for (int i=0;i<n/2;i++)
	{
		a[i]=even[i]+w*odd[i];
		a[i+n/2]=even[i]-w*odd[i];
		if (inv)
		{
			a[i]/=2;
			a[i+n/2]/=2;
		}
		w*=wn;
	}
}
void mul(vector<cpx>& a,vector<cpx>& b)
{
	int n=max(a.size(),b.size()),tmp=1;
	while (tmp<n)
	tmp*=2;
	tmp*=2;
	int as=a.size(),bs=b.size();
	for (int i=0;i<tmp-as;i++)
	a.push_back(0);
	for (int i=0;i<tmp-bs;i++)
	b.push_back(0);
	fft(a,0);
	fft(b,0);
	for (int i=0;i<a.size();i++)
	a[i]*=b[i];
	fft(a,1);
}
int main()
{
	int n;
	scanf("%d%d",&n,&x);
	vector<cpx> a,b;
	int last=-1;
	long long z=0;
	arr[n]=-(1<<30);
	for (int i=0;i<=n;i++)
	{
		if (i!=n)
		scanf("%d",&arr[i]);
		if (arr[i]<x)
		{
			a.push_back(i-last);
			b.push_back(i-last);
			long long sz=i-last-1;
			z+=sz*(sz+1)/2;
			last=i;
		}
	}
	while (b.size()!=n+1)
	{
		a.push_back(0);
		b.push_back(0);
	}
	reverse(b.begin(),b.end());
	mul(a,b);
	printf("%I64d ",z);
	for (int i=n+1;i<=2*n;i++)
	printf("%I64d ",(long long)round(real(a[i])));
}