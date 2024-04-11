#include <iostream>

using namespace std;

inline void no() {
	cout << "NO\n";
}

inline void yes() {
	cout << "YES\n";
}

int main() {
		
	int t, s, x;
	
	cin >> t >> s >> x;
	
	if(x < t) no();
	else if(x == t) yes();
	else {
		if((x - t) % s == 0 || x - t > 1 && (x - t - 1) % s == 0) yes();
		else no();
	}
		
	return 0;
}