#include <iostream>
using namespace std;

#define x first
#define y second
typedef pair<int, int> ii;

void operator -= (ii &A, ii B) { A.x -= B.x; A.y -= B.y; }
long long ccw (ii O, ii A, ii B) { A -= O; B -= O; return 1LL * A.x * B.y - 1LL * A.y * B.x; }

ii a[100005];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y;
	cin >> m;
	while(m--) {
		ii p;
		cin >> p.x >> p.y;
		if(ccw(a[1], a[2], p) >= 0) return cout << "NO", 0;
		if(ccw(a[1], a[n], p) <= 0) return cout << "NO", 0;
		int l = 2, r = n;
		while(l != r) {
			int mid = (l + r) >> 1;
			if(ccw(a[1], a[mid], p) < 0) l = mid + 1;
			else r = mid;
		} 
		if(ccw(a[l - 1], a[l], p) >= 0) return cout << "NO", 0;  
	}
	cout << "YES";
}