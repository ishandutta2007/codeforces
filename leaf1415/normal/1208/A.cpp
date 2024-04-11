#include <iostream>

using namespace std;

int T;
int a, b, n;

int main(void)
{
	cin >> T;
	for(int t = 0; t < T; t++){
		int ans;
		cin >> a >> b >> n;
		if(n%3 == 0) ans = a;
		if(n%3 == 1) ans = b;
		if(n%3 == 2) ans = a^b;
		cout << ans << "\n";
	}
	flush(cout);
	return 0;
}