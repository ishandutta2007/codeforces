
#include <iostream>

using namespace std;

int n, k;
int x[100000];
int l[100001], r[100001];

int main() {
	cin >> n >> k;
	for(int i = 0; i < k; i++) {
		cin >> x[i];
	}
	for(int i = 1; i <= n; i++) {
		l[i] = k;
		r[i] = 0;
	}
	for(int i = 0; i < k; i++) {
		if(l[x[i]] > i) {
			l[x[i]] = i;
		}
	}
	for(int i = k - 1; i >= 0; i--) {
		if(r[x[i]] < i) {
			r[x[i]] = i;
		}
	}
	int count = 0;
	for(int i = 1; i < n; i++) {
		if(l[i] + 1 >= r[i + 1]) {
			count++;
		}
	}
	for(int i = 2; i <= n; i++) {
		if(l[i] + 1 >= r[i - 1]) {
			count++;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(l[i] == k) {
			count++;
		}
	}
	cout << count << endl;
}