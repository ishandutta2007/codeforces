#include <iostream>
using namespace std;
int main()
{
	int i;
	double a1[]={500,1000,1500,2000,2500},a2[5],a3[5],s,u,f;
	for (i=0;i<5;i++)
	cin >> a2[i];
	for (i=0;i<5;i++)
	cin >> a3[i];
	cin >> s >> u;
	f=s*100-u*50;
	for (i=0;i<5;i++)
	f+=max(0.3*a1[i],(1-a2[i]/250)*a1[i]-50*a3[i]);
	cout << f;
}