#include <bits/stdc++.h>
using namespace std;

int t;
int d, k;

bool isPos(int v) {
	long long x = (long long) (v / 2) * k,
		 y = (long long) ((v + 1) / 2) * k;
	x *= x;
	y *= y;
	return (x + y) <= (long long) d * d;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &d, &k);
		int lo = d / k, hi = d * 2 / k, mid;
		int maxMoves = -1;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (isPos(mid)) {
				maxMoves = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		if (maxMoves % 2 == 1) printf("Ashish\n");
		else printf("Utkarsh\n");
	}
	return 0;
}