#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

struct Rect {
	ll x1, y1, x2, y2;

	ll area() const {
		if (x2 < x1 || y2 < y1) return 0;
		else return (x2 - x1) * (y2 - y1);
	}
};
Rect its(Rect a, Rect b) {
	Rect res;
	res.x1 = max(a.x1, b.x1);
	res.x2 = min(a.x2, b.x2);
	res.y1 = max(a.y1, b.y1);
	res.y2 = min(a.y2, b.y2);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Rect w, b1, b2;
	cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
	cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
	cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;

	ll res = w.area() - its(w, b1).area() - its(w, b2).area() + its(w, its(b1, b2)).area();
	if (res > 0) cout << "YES\n";
	else cout << "NO\n";
}