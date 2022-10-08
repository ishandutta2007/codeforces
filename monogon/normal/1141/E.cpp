
#include <iostream>

using namespace std;

long long H;
int n;
long long d[200000];

int main() {
	cin >> H >> n >> d[0];
	for(int i = 1; i < n; i++) {
		cin >> d[i];
		d[i] += d[i - 1];
	}
	if(d[n - 1] < 0) {
		long long t = (H - d[n - 1] - 1) / (-d[n - 1]);
		int idx = -1;
		for(int i = 0; i + 1 < n; i++) {
			long long M = (H + d[i] - d[n - 1] - 1) / (-d[n - 1]);
			if(M < 0) M = 0;
			if(M < t) {
				t = M;
				idx = i;
			}
		}
		cout << (n * t + idx + 1) << endl;
	}else {
		for(int i = 0; i < n; i++) {
			if(H + d[i] <= 0) {
				cout << (i + 1) << endl;
				return 0;
			}
		}
		cout << -1 << endl;
	}
}