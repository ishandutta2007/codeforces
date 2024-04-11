#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int> > a;
vector<int> ans;
double pi = 3.14159265359;

double angle(int x1, int y1, int x2, int y2, int x3, int y3) {

    double dot = ((x2 - x1 * 1.0) * (x2 - x3) + (y2 - y1 * 1.0) * (y2 - y3));
    double cross = ((x2 - x1 * 1.0) * (y2 - y3) - (y2 - y1 * 1.0) * (x2 - x3)); 

    double ans = atan2(cross, dot);

    return abs(ans * 180 / pi);
}

int main() {
	scanf("%d", &n);
	a.resize(n);
	ans.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
		ans[i] = i+1;
	}
	bool change = false;
	for (int tries = 0; tries <= 5 * n; tries++) {
		change = false;
		for (int i = 0; i < n - 2; i++) {
			//printf("%lf\n", angle(a[i].first, a[i].second, a[i+1].first, a[i+1].second, a[i+2].first, a[i+2].second));
			if (angle(a[i].first, a[i].second, a[i+1].first, a[i+1].second, a[i+2].first, a[i+2].second) >= 89.999999) {
				swap(a[i], a[i+1]);
				swap(ans[i], ans[i+1]);
				change = true;
			}
		}
		if (!change) break;
		if (tries % n == 0 && tries != 0) {
			swap(a[a.size() - 1], a[a.size() - 2]);
			swap(ans[a.size() - 1], ans[a.size() - 2]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	
	return 0;
}