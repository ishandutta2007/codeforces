#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[100];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int idx = 0;
	int val = a[0];
	int probs = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] != val) {
			int dist = i - idx;
			if(dist % 2) {
				probs += a[i] - val;
				idx = i - 1;
			}else {
				idx = i;
			}
			val = a[i];
		}
	}
	cout << probs << endl;
}