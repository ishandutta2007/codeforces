#include <iostream>
using namespace std;

const int N = 30;
int flip[N];

int ask(int y) {
	cout << y << endl;
	int res;
	cin >> res;
	if (res == 0) exit(0);
	if (res == -2) exit(0);
	return res;
}

int main() {
	int m, n;
	cin >> m >> n;

	for (int i = 0; i < n; ++i) {
		flip[i] = ask(1); // 1 if speaks the truth
	}
	int low = 1;
	int high = m;

	int j = 0;
	while(low < high) {
		int mid = (low + high) / 2;
		int res = ask(mid) * flip[j];
		j = (j + 1) % n;
		if (res == -1) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	ask(low);
}