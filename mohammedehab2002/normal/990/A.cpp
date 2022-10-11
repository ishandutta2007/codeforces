#include <iostream>
using namespace std;
int main()
{
	long long n,m,a,b;
	cin >> n >> m >> a >> b;
	cout << min((n%m)*b,((m-n%m)%m)*a);
}