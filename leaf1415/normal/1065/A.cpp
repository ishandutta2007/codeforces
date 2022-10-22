#include <iostream>
#define llint long long

using namespace std;

llint T;
llint s, a, b, c;

int main(void)
{
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> s >> a >> b >> c;
		llint n = s / c;
		llint ans = n + n/a*b;
		cout << ans << endl;
	}
	return 0;
}