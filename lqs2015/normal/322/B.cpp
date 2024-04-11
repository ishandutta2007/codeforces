#include<iostream>
using namespace std;
int main()
{
	int r,b,g,s,mx,t,r1,b1,g1;
	cin>>r>>b>>g;
	mx=0;
	for (int i=0;i<=2;i++)
	{
		s=0;
		if (min(r,min(b,g))>=i)
		{
			r1=(r-i)/3;
			b1=(b-i)/3;
			g1=(g-i)/3;
			s=s+i+r1+b1+g1;
			if (s>mx) mx=s;
		}
	}
	cout<<mx;
	return 0;
}