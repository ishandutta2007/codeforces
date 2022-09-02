#include <iostream>
#include <vector>
#include <utility>
#include <deque>
using namespace std;

const int N = 1e5;
int cou[N];
int n, dist, off;

bool can_reach(int x, int t) {
	int teach_time = min(n-t, t+1);
	int stud_time = (abs(x-t)+(dist-1)) / dist;
	// cout << "reach " << x << ' '<< t << ' ' << teach_time << ' ' << stud_time << '\n';
	return (stud_time <= teach_time);
}
// is it possible to get correct counts in rooms a...b
bool can(int a, int b) {
	int j = a;
	int rem = off;
	for (int i = 0; i < n; ++i) {
		int cur = cou[i];
		while((j < n) && (cur > 0) && (can_reach(i, j))) {
			int del = min(rem, cur);
			rem -= del;
			cur -= del;
			if (rem == 0) {
				rem = off;
				++j;
			}
		}
	}
	if (j > b) return true;
	return false;
}

int main() {
	cin >> n >> dist >> off;
	for (int i = 0; i < n; ++i) cin >> cou[i];
	//cout << can(26, n-1-26) << '\n';
	int low = 0;
	int high = n / 2;
	while(low != high) {
		int mid = (low + high) >> 1;
		if (can(mid, n-1-mid)) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	cout << low << '\n';
}