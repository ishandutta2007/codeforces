#include <iostream>

using namespace std;

int n, a;
int x;
int steps[1001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		x += (a == 1);
		steps[x]++;
	}
	cout << x << endl;
	for(int i = 1; i <= x; i++) {
		cout << steps[i] << " ";
	}
	cout << endl;
}