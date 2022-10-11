#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,a,b;
	cin >> n >> a >> b;
	cout << n-max(a+1,n-b)+1;
}