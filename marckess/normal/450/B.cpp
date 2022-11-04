
#include <iostream>

using namespace std;

#define mod 1000000007

int main(){
	long long x, y, n, res;

	cin >> x >> y >> n;
	n--;
	n %= 6;

	switch(n){
		case 0:
			res = x;
			break;
		case 1:
			res = y;
			break;
		case 2:
			res = y - x;
			break;
		case 3:
			res = -x;
			break;
		case 4:
			res = -y;
			break;
		case 5:
			res = -y + x;
			break;
	}

	cout << (res % mod + mod) % mod;

	return 0;
}