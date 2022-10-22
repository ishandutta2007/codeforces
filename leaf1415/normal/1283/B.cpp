#include <iostream>
#define llint long long

using namespace std;

llint T;
llint n, k;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		if(n % k == 0) cout << n << "\n";
		else{
			cout << min(n/k*k + k/2, n) << "\n";
		}
	}
	flush(cout);
	
	return 0;
}