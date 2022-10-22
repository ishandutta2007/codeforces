#include <iostream>
#define llint long long

using namespace std;

llint n;

int main(void)
{
	cin >> n;
	cout << n*(n+1)/2%2 << endl;
	
	return 0;
}