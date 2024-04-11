#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    long long int n, a, r;
    cin>>n;
for (int i=0;i<n;i++)
{
	cin>>a;
	r = (1 + a)*a/2;	
	for (int i=1; i<=a; i*=2)
	{
	r-=(i*2);
	}
	cout<<r<<endl;

}
}