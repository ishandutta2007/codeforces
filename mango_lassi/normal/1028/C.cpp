#include <iostream>
using namespace std;
const int INF = 100 + (int)1e9;
struct Rect {
	int sx;
	int sy;
	int ex;
	int ey;

	bool operator==(const Rect& oth) const {
		return (sx == oth.sx) && (sy == oth.sy) && (ex == oth.ex) && (ey == oth.ey);
	}
};

Rect null_rect;
Rect full_rect;

Rect its(Rect a, Rect b) {
	Rect res;
	res.sx = max(a.sx, b.sx);
	res.ex = min(a.ex, b.ex);
	res.sy = max(a.sy, b.sy);
	res.ey = min(a.ey, b.ey);
	if (res.ex < res.sx || res.ey < res.sy) res = null_rect;
	return res;
}

const int N = 200000;
Rect rects[N];

Rect solve(int a, int b, Rect oth) {
	if (a == b) return oth;
	int m = (a + b) / 2;
	
	Rect l_oth = oth;
	for (int i = a; i <= m; ++i) {
		l_oth = its(l_oth, rects[i]);
	}
	
	Rect r_oth = oth;
	for (int i = m+1; i <= b; ++i) {
		r_oth = its(r_oth, rects[i]);
	}

	Rect l_res = solve(a, m, r_oth);
	Rect r_res = solve(m+1, b, l_oth);
	if (l_res == null_rect) return r_res;
	else return l_res;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> rects[i].sx >> rects[i].sy >> rects[i].ex >> rects[i].ey;
	}
	
	full_rect.sx = -INF;
	full_rect.ex = INF;
	full_rect.sy = -INF;
	full_rect.ey = INF;

	Rect res = solve(0, n-1, full_rect);
	cout << res.sx << ' ' << res.sy << '\n';
}