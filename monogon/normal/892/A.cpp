#include <iostream>

using namespace std;

// can1 biggest, can2 second biggest
long long n, a, can1, can2, vol;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		vol += a;
	}
	for(int i = 0; i < n; i++) {
		cin >> a;
		if(a > can1) {
			can2 = can1;
			can1 = a;
		}else if(a > can2) {
			can2 = a;
		}
	}
	cout << (can1 + can2 >= vol ? "YES" : "NO") << endl;
}