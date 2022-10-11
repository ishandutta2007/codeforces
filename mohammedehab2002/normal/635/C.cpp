#include <iostream>
using namespace std;
int main()
{
	long long a,b;
	cin >> a >> b;
	if((a-b)%2 || a-b<0 || (((a-b)/2)&b))
	cout << 0;
	else
	cout << (1LL<<__builtin_popcountll(b))-2*(a==b);
}