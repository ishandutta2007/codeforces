#include <iostream>
#include <vector>
#include <complex>
using namespace std;
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
vector<int> multiply(vector<int> aa,vector<int> bb)
{
    int la=0,lb=0;
    for (int i=aa.size()-1;i>=0;i--)
    {
        if (aa[i])
        {
            la=i;
            break;
        }
    }
    for (int i=bb.size()-1;i>=0;i--)
    {
        if (bb[i])
        {
            lb=i;
            break;
        }
    }
    int tmp=1;
    while (tmp<la+lb)
    tmp*=2;
    while (aa.size()<tmp)
    aa.push_back(0);
    while (bb.size()<tmp)
    bb.push_back(0);
	vector<cpx> a(aa.begin(),aa.end()),b(bb.begin(),bb.end());
	fft(a,0);
	fft(b,0);
	for (int i=0;i<a.size();i++)
	a[i]*=b[i];
	fft(a,1);
	vector<int> res;
	for (int i=0;i<a.size();i++)
	res.push_back(min((int)round(real(a[i])),1));
	return res;
}
vector<int> pow(vector<int> a,int k)
{
	if (k==1)
	return a;
	vector<int> tmp=pow(a,k/2);
	tmp=multiply(tmp,tmp);
	if (k%2)
	tmp=multiply(tmp,a);
	return tmp;
}
int main()
{
	vector<int> v(1024);
	int n,k;
	scanf("%d%d",&n,&k);
	while (n--)
	{
		int a;
		scanf("%d",&a);
		v[a]=1;
	}
	vector<int> c=pow(v,k);
	for (int i=0;i<c.size();i++)
	{
		if (c[i])
		printf("%d ",i);
	}
}