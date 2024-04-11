#include <iostream>

using namespace std;

int T;

int main(void)
{
	cin >> T;
	int n, s, t, x;
	for(int q = 0; q < T; q++){
		cin >> n >> s >> t;
		int x = (s+t)-n;
		cout << max(s-x, t-x)+1 << endl;
	}
	return 0;
}