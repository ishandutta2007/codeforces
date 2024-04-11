#include <iostream>
#define llint long long

using namespace std;

llint q;

int main(void)
{
	cin >> q;
	llint n, a, b;
	for(int i = 0; i < q; i++){
		cin >> n >> a >> b;
		if(b > 2*a) cout << n*a << endl;
		else cout << n/2*b+n%2*a << endl;
	}
	return 0;
}