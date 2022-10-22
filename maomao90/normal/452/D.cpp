#include <bits/stdc++.h>
using namespace std;

int k, n1, n2, n3, t1, t2, t3;
deque<int> dq1, dq2, dq3;

int main() {
	scanf("%d%d%d%d%d%d%d", &k, &n1, &n2, &n3, &t1, &t2, &t3);
	for (int i = 0; i < n1; i++) dq1.push_back(0);
	for (int i = 0; i < n2; i++) dq2.push_back(0);
	for (int i = 0; i < n3; i++) dq3.push_back(0);
	for (int i = 0; i < k; i++) {
		int time1 = dq1.front(), time2 = dq2.front(), time3 = dq3.front();
		int maxtime = max(time1, max(time2 - t1, time3 - t1 - t2));
		dq1.pop_front();
		dq2.pop_front();
		dq3.pop_front();
		dq1.push_back(maxtime + t1);
		dq2.push_back(maxtime + t1 + t2);
		dq3.push_back(maxtime + t1 + t2 + t3);
		if (i == k - 1) {
			printf("%d\n", maxtime + t1 + t2 + t3);
		}
	}
	return 0;
}