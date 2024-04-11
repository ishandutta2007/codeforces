
#include <iostream>
#include <set>

using namespace std;

int n, x, y;
set<pair<int, int> > points;
int a[1000];
int b[1000];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x >> y;
		points.insert(make_pair(x, y));
	}
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for(pair<int, int> point : points) {
		pair<int, int> T = make_pair(point.first + a[0], point.second + b[0]);
		int i = 1;
		for(; i < n; i++) {
			pair<int, int> point2 = make_pair(T.first - a[i], T.second - b[i]);
			if(points.find(point2) == points.end()) {
				break;
			}
		}
		if(i == n) {
			cout << T.first << " " << T.second << endl;
			break;
		}
	}
}