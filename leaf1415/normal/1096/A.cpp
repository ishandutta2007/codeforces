#include <iostream>

using namespace std;

int T;

int main(void)
{
	cin >> T;
	for(int t = 0; t < T; t++){
		int l, r;
		cin >> l >> r;
		cout << l << " " << 2*l << endl;
	}
	return 0;
}