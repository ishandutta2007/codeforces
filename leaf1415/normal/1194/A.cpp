#include <iostream>
#define llint long long

using namespace std;

llint T;
llint n, x;

int main(void)
{
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> x;
		cout << 2*x << endl;
	}
	return 0;
}