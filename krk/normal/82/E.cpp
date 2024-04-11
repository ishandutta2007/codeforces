#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

typedef long double ld;

const int Maxn = 1005;
const ld eps = 1e-9l;

struct pos {
	ld x, y, z;
	pos(ld x = 0.0l, ld y = 0.0l, ld z = 0.0l): x(x), y(y), z(z) { }
};

int n, h, f;
ld x1u[Maxn], x2u[Maxn];
ld x1d[Maxn], x2d[Maxn];
vector <pos> conv;
ld res;

void Cut(ld x1, ld y1, ld x2, ld y2)
{
	ld A = y2 - y1, B = x1 - x2, C = A * x1 + B * y1;
	conv.push_back(pos(conv[0].x, conv[0].y));
	for (int i = 0; i < conv.size(); i++)
		conv[i].z = A * conv[i].x + B * conv[i].y - C;
	conv.push_back(conv[0]);
	vector <pos> nconv;
	for (int i = 0; i + 1 < conv.size(); i++) {
		if (conv[i].z + eps >= 0.0l)
			nconv.push_back(conv[i]);
		if (conv[i].z + eps >= 0.0l && conv[i + 1].z + eps < 0.0l || conv[i].z + eps < 0.0l && conv[i + 1].z + eps >= 0.0l) {
			ld A2 = conv[i + 1].y - conv[i].y, B2 = conv[i].x - conv[i + 1].x, C2 = A2 * conv[i].x + B2 * conv[i].y;
			ld det = A * B2 - A2 * B;
			ld X = (B2 * C - C2 * B) / det;
			ld Y = (A * C2 - C * A2) / det;
			nconv.push_back(pos(X, Y));
		}
	}
	conv = nconv;
}

int main()
{
	scanf("%d %d %d", &n, &h, &f);
	for (int i = 0; i < n; i++) {
		cin >> x1u[i] >> x2u[i];
		x1d[i] = x1u[i] * f / (f - h);
		x2d[i] = x2u[i] * f / (f - h);
		res += (x2u[i] - x1u[i] + x2d[i] - x1d[i]) * h;
		x1d[n + i] = x1d[i]; x2d[n + i] = x2d[i];
		x1u[n + i] = x1d[n + i] * (f + h) / f;
		x2u[n + i] = x2d[n + i] * (f + h) / f;
		res += (x2u[n + i] - x1u[n + i] + x2d[n + i] - x1d[n + i]) * h;
	}
	for (int i = 0; i < n; i++)
		for (int j = n; j < 2 * n; j++) {
			conv.clear();
			conv.push_back(pos(x1d[i], 0.0l));
			conv.push_back(pos(x1u[i], h));
			conv.push_back(pos(x2u[i], h));
			conv.push_back(pos(x2d[i], 0.0l));
			Cut(x1d[j], 0.0l, x1u[j], h);
			if (conv.empty()) continue;
			Cut(x2u[j], h, x2d[j], 0.0l);
			if (conv.empty()) continue;
			ld subs = 0.0l;
			conv.push_back(conv[0]);
			for (int k = 0; k + 1 < conv.size(); k++)
				subs += (conv[k + 1].x - conv[k].x) * (conv[k + 1].y + conv[k].y);
			res -= subs;
		}
	cout << fixed << setprecision(12) << res << endl;
	return 0;
}