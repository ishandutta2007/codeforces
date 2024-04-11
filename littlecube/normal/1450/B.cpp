#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

int main() {
	int t, n, k;
	pii p[105];
	cin >> t;
	while(t--) {
		bool success = true;
		cin >> n >> k;
		for(int i = 0; i < n; i++) {
			cin >> p[i].first >> p[i].second;
		}
		for(int i = 0; i < n; i++) {
			success = true;
			for(int j = 0; j < n; j++) {
				if(abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second) >k) {
					success = false;
					break;
				}
			}
			if(success)
				break;
		}
		if(success)
			cout << "1\n";
		else
			cout << "-1\n";

	}
}