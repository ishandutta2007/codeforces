
#include <iostream>

using namespace std;

int n;
long long a[300000];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int i = 0; // index of small side
	int j = 0; // index of 2 larger sides
	long long count = 0;
	while(i < n && j < n) {
		if(a[i] == 0) {
			i++;
		}else if(i == j) {
			count += a[i] / 3;
			a[i] %= 3;
			j++;
		}else if(a[j] >= 2) {
			long long tris = min(a[i], a[j] / 2);
			count += tris;
			a[i] -= tris;
			a[j] -= 2 * tris;
		}else {
			j++;
		}
	}
	cout << count << endl;
}