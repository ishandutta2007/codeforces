#include <iostream>
using namespace std;
int main()
{
	long long k,n,s,p;
	cin >> k >> n >> s >> p;
	for (int i=1;;i++)
	{
		if ((i*p/k)*s>=n)
		{
			printf("%d",i);
			return 0;
		}
	}
}