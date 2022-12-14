#include<iostream>
using namespace std;
long long m,b,y,mx,sum;
int main()
{
	cin>>m>>b;
	for (long long x=1;x<=m*b;x++)
	{
		if (x%m) continue;
		y=-(x/m)+b;
		sum=(1+x)*x/2*(y+1)+(1+y)*y/2*(x+1);
		mx=max(mx,sum);
	}
	cout<<mx<<endl;
	return 0;
}