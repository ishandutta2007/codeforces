#include <iostream>
#include <cstdlib>
#define llint long long

using namespace std;

llint n, T;
llint a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		llint s = 0, x = 0;
		for(int i = 1; i <= n; i++) s += a[i], x ^= a[i];
		
		llint y = (1LL<<50)-2;
		cout << 3 << "\n";
		cout << y-x << " ";
		
		s += y-x, x ^= y-x;
		llint z = (2*x - s) / 2;
		cout << z << " " << z << "\n";
	}
	flush(cout);
	
	return 0;
}