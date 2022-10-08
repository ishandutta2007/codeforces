
#include <iostream>
#include <algorithm>

using namespace std;

long long a, b, c, m;

int offA[3] = {1, 4, 7};
int offB[2] = {2, 6};
int offC[2] = {3, 5};

int main() {
	cin >> a >> b >> c;
	m = -1;
	// compute first day you'll run out of food
	for(int i = 0; i < 7; i++) {
		for(int j = 0; j < 2; j++) {
			offA[j] = (offA[j] + 1) % 7;
			offB[j] = (offB[j] + 1) % 7;
			offC[j] = (offC[j] + 1) % 7;
			if(offA[j] == 0) offA[j] = 7;
			if(offB[j] == 0) offB[j] = 7;
			if(offC[j] == 0) offC[j] = 7;
		}
		offA[2] = (offA[2] + 1) % 7;
		if(offA[2] == 0) offA[2] = 7;
		sort(offA, offA + 3);
		sort(offB, offB + 2);
		sort(offC, offC + 2);

		int A1 = offA[a % 3];
		int B1 = offB[b % 2];
		int C1 = offC[c % 2];

		long long A = 7 * (a / 3) + A1;
		long long B = 7 * (b / 2) + B1;
		long long C = 7 * (c / 2) + C1;
		long long M = min(A, min(B, C)) - 1;
		if(M > m) {
			m = M;
		}
	}
	cout << m << endl;
}