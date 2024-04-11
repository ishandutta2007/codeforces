#include <iostream>
#define llint long long

using namespace std;

llint a, b, c, d;

int main(void)
{
	cin >> a >> b >> c >> d;
	
	int h = 2*a;
	if(c > 0 && h == 0){
		cout << 0 << endl;
		return 0;
	}
	h -= 2*d;
	if(h != 0) cout << 0 << endl;
	else cout << 1 << endl;
	
	return 0;
}