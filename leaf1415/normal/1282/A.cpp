#include <iostream>
#include <cstdlib>
#define llint long long

using namespace std;

llint T;
llint a, b, c, R;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> a >> b >> c >> R;
		if(a > b) swap(a, b);
		llint l = max(a, c-R), r = min(b, c+R);
		cout << abs(b-a) - max(0LL, r-l) << "\n";
	}
	flush(cout);
	
	return 0;
}