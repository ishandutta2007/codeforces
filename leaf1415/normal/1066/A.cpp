#include <iostream>
#define llint long long

using namespace std;

llint T;
llint L, v, l, r;

int main(void)
{
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> L >> v >> l >> r;
		llint x = r/v - (l-1)/v;
		cout << L/v - x << endl;
	}
	return 0;
}