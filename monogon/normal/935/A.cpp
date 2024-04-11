#include <iostream>

using namespace std;

int n;
int count = 0;

int main() {
	cin >> n;
	for(int i = 1; i < n; i++) {
		count += n % i == 0;
	}
	cout << count << endl;
}