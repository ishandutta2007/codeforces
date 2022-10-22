#include <iostream>
#include <stdlib.h>
#define llint long long

using namespace std;

llint T;
llint n, x, a, b;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> x >> a >> b;
		cout << min(n-1, abs(a-b)+x) << endl;
	}
	return 0;
}