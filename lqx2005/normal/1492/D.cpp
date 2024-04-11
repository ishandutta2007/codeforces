#include <bits/stdc++.h>
#define x first
#define y second
#define pi pair<int, int>
#define db double
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 2e5 + 10;
int a, b, k;

void output(int x, int c) {
	assert(c >= 0);
	for(int i = 1; i <= c; i++) cout << x;
	return; 
}

int main() {
	cin >> a >> b >> k;
	if(b == 1 || a == 0) {
		if(k) {
			cout << "No" << endl;
			exit(0);
		}
		cout << "Yes" << endl;
		output(1, b), output(0, a);
		cout << endl;
		output(1, b), output(0, a);
		cout << endl;
		exit(0);
	}
	if(a + b - 2 < k) {
		cout << "No" << endl;
		exit(0);
	}
	cout << "Yes" << endl;
	output(1, b), output(0, a);
	cout << endl;
	output(1, 1);
	if(k <= a) {
		output(1, b - 2);
		output(0, k);
		output(1, 1);
		output(0, a - k);
	} else {
		k -= a;
		output(1, b - 2 - k);
		output(0, 1);
		output(1, k);
		output(0, a - 1);
		output(1, 1);
	}
	cout << endl;
    return 0;
}