#include <iostream>


using namespace std;



int main()
{
	int a,b;
	cin>>a>>b;
	int kk=0;
	int res;
	res=a;
	kk=a;
	a=0;
	while (kk>=b)
	{
		a=kk/b;
		kk%=b;
		res+=a;
		kk+=a;
		a=0;
	}
	cout<<res;
}