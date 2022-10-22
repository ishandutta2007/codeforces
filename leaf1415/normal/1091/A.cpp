#include <iostream>

using namespace std;

int a, b, c;

int main(void)
{
	cin >> a >> b >> c;
	b--, c-=2;
	int x = min(a, min(b, c));
	cout << 3*x+3 << endl;
	return 0;
}