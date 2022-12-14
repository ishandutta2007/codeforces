#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
int n,m,z,g;
int main()
{
	cin>>n>>m>>z;
	g=n*m/gcd(n,m);
	cout<<z/g<<endl;
	return 0;
}