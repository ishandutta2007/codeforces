
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[200000];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int k = 1;
	for(int i = 0; i < n; i++) {
		if(a[i] >= k) {
			k++;
		}
	}
	cout << (k - 1) << endl;
}