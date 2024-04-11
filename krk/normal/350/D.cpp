#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 300005;
const int Maxm = 1505;

struct line {
	int A, B, C;
	int gcd(int x, int y) { return x? gcd(y % x, x): y; }
	void Fix() {
		if (A == 0) {
			if (B < 0) { B = -B; C = -C; }
			int g = gcd(abs(B), abs(C)); B /= g; C /= g;
		} else if (B == 0) {
			if (A < 0) { A = -A; C = -C; }
			int g = gcd(abs(A), abs(C)); A /= g; C /= g;
		} else {
			if (A < 0) { A = -A; B = -B; C = -C; }
			int g = gcd(gcd(abs(A), abs(B)), abs(C)); A /= g; B /= g; C /= g;
		}
	}
	line(int A = 0, int B = 1, int C = 0): A(A), B(B), C(C) { Fix(); }
	line(int x1, int y1, int x2, int y2) { A = y2 - y1; B = x1 - x2; C = A * x1 + B * y1; Fix(); }
	line Perp(int x, int y) { return line(-B, A, -B * x + A * y); }
	int Num(int x, int y) { return B == 0? y: x; }
	bool operator <(const line &l) const {
		if (A != l.A) return A < l.A;
		if (B != l.B) return B < l.B;
		return C < l.C;
	}
};

int n, m;
int X1[Maxn], Y1[Maxn], X2[Maxn], Y2[Maxn];
int X[Maxm], Y[Maxm], R[Maxm];
map <line, vector <ii> > M;
set <line> was;
ll res;

int main()
{
	scanf("%d %d", &n, &m);
	line cur;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &X1[i], &Y1[i], &X2[i], &Y2[i]); X1[i] *= 2; Y1[i] *= 2; X2[i] *= 2; Y2[i] *= 2;
		cur = line(X1[i], Y1[i], X2[i], Y2[i]);
		int a = cur.Num(X1[i], Y1[i]), b = cur.Num(X2[i], Y2[i]);
		M[cur].push_back(ii(min(a, b), 1)); M[cur].push_back(ii(max(a, b), 3));
		was.insert(cur);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &X[i], &Y[i], &R[i]); X[i] *= 2; Y[i] *= 2; R[i] *= 2;
	}
	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++)
			if (R[i] == R[j] && (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]) > 4 * R[i] * R[i]) {
				cur = line(X[i], Y[i], X[j], Y[j]);
				cur = cur.Perp((X[i] + X[j]) / 2, (Y[i] + Y[j]) / 2);
				if (was.count(cur))	M[cur].push_back(ii(cur.Num((X[i] + X[j]) / 2, (Y[i] + Y[j]) / 2), 2));
			}
	for (map <line, vector <ii> >::iterator it = M.begin(); it != M.end(); it++) {
		sort(it->second.begin(), it->second.end());
		int st = 0;
		for (int i = 0; i < it->second.size(); i++)
			if (it->second[i].second == 1) st++;
			else if (it->second[i].second == 2) res += st;
			else st--;
	}
	printf("%I64d\n", res);
	return 0;
}