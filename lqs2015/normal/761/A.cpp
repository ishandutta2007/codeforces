#include<iostream>
#include<cmath>
using namespace std;
int a,b;
int main()
{
	cin>>a>>b;
	if (abs(a-b)<=1 && (a || b)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}