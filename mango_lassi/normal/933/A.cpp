#include <iostream>
#include <vector>
using namespace std;

const int N = 2000;
int val[N];
int decr[N][N][4];
int incr[N][N][4];

int getdecr(int a, int b, int con) {
	if (b < a) return 0;
	return decr[a][b][con];
}
int getincr(int a, int b, int con) {
	if (b < a) return 0;
	return incr[a][b][con];
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> val[i];
		--val[i];
	}
	for (int a = 0; a < n; ++a) {
		for (int b = a; b < n; ++b) {
			if (a == b) {
				if (val[b] == 0) {
					decr[a][b][0 + 0] = 1;
					incr[a][b][0 + 0] = 1;
				} else {
					decr[a][b][1 + 2] = 1;
					incr[a][b][1 + 2] = 1;
				}
			} else {
				if (val[b] == 0) {
					decr[a][b][0 + 0] = decr[a][b-1][0 + 0] + 1;
					decr[a][b][1 + 0] = max(decr[a][b-1][1 + 0], decr[a][b-1][1 + 2]) + 1;
					incr[a][b][0 + 0] = incr[a][b-1][0 + 0] + 1;

					incr[a][b][0 + 2] = incr[a][b-1][0 + 2];
					incr[a][b][1 + 2] = incr[a][b-1][1 + 2];
					decr[a][b][1 + 2] = decr[a][b-1][1 + 2];
				} else {
					decr[a][b][1 + 2] = decr[a][b-1][1 + 2] + 1;
					incr[a][b][0 + 2] = max(incr[a][b-1][0 + 0], incr[a][b-1][0 + 2]) + 1;
					incr[a][b][1 + 2] = incr[a][b-1][1 + 2] + 1;

					incr[a][b][0 + 0] = incr[a][b-1][0 + 0];
					decr[a][b][0 + 0] = decr[a][b-1][0 + 0];
					decr[a][b][1 + 0] = decr[a][b-1][1 + 0];
				}
			}
		}
	}
	for (int a = 0; a < n; ++a) {
		for (int b = a; b < n; ++b) {
			incr[a][b][0 + 2] = max(incr[a][b][0 + 2], max(incr[a][b][1 + 2], incr[a][b][0 + 0]));
			decr[a][b][1 + 0] = max(decr[a][b][1 + 0], max(decr[a][b][1 + 2], decr[a][b][0 + 0]));
		}
	}
	int res = max(incr[0][n-1][0 + 0], incr[0][n-1][1 + 2]);
	for (int a = 0; a < n; ++a) {
		for (int b = a; b < n; ++b) {
			int mid = (a+b)>>1;
			vector<int> start (4, 3);
			// case 1: zero-one changes on first segment
			start[0] = 2;
			res = max(res, getincr(0, a-1, start[0]) + getdecr(mid+1, b, start[1]) + getdecr(a, mid, start[2]) + getincr(b+1, n-1, start[3]));
			// case 2: zero-one changes on second segment
			start[0] = 0;
			start[1] = 1;
			res = max(res, getincr(0, a-1, start[0]) + getdecr(mid+1, b, start[1]) + getdecr(a, mid, start[2]) + getincr(b+1, n-1, start[3]));
			// case: zero-one changes on left part of flip
			start[1] = 0;
			start[2] = 1;
			res = max(res, getincr(0, a-1, start[0]) + getdecr(mid+1, b, start[1]) + getdecr(a, mid, start[2]) + getincr(b+1, n-1, start[3]));
			// case: zero-one changes on right part of flip
			start[2] = 0;
			start[3] = 2;
			res = max(res, getincr(0, a-1, start[0]) + getdecr(mid+1, b, start[1]) + getdecr(a, mid, start[2]) + getincr(b+1, n-1, start[3]));
		}
	}
	cout << res << '\n';
}