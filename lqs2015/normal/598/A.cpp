#include<iostream>
#include<cmath>
using namespace std;
int twin(int k)
{
	int i;
	for (i=1;;i++)
	if (pow(2,i)>k) break;
	return i-1;
}
int main()
{
	int t,k;
	long long g,m,c;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>m;
		g=0;
		k=twin(m);
		for (int j=1;j<=k+1;j++)
		g-=pow(2,j);
		c=m;
		m++;
		g=g+c*m/2;
		cout<<g<<endl;
	}
	return 0;
}