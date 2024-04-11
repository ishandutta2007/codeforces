#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <double, double> dd;

const int Maxn = 305;
const double eps = 1e-8;

int n, k;
int y[Maxn][Maxn];
double res[Maxn];
vector <dd> has, nhas;

bool Eq(const dd &a, const dd &b)
{
	return fabs(a.first - b.first) <= eps && fabs(a.second - b.second) <= eps;
}

void Get(const dd &p1, const dd &p2, double &A, double &B, double &C)
{
	A = p2.second - p1.second, B = p1.first - p2.first;
	C = A * p1.first + B * p1.second;
}

bool Inters(const dd &p1, const dd &p2, const dd &p3, const dd &p4, dd &res)
{
	double A1, B1, C1; Get(p1, p2, A1, B1, C1);
	double A2, B2, C2; Get(p3, p4, A2, B2, C2);
	double det = A1 * B2 - A2 * B1;
	if (fabs(det) < eps) return false;
	res.first = (B2 * C1 - B1 * C2) / det;
	res.second = (A1 * C2 - A2 * C1) / det;
	if (Eq(res, p3) || Eq(res, p4)) return false;
	return min(p1.first, p2.first) <= res.first + eps && res.first <= max(p1.first, p2.first) + eps &&
	       min(p1.second, p2.second) <= res.second + eps && res.second <= max(p1.second, p2.second) + eps &&
		   min(p3.first, p4.first) <= res.first + eps && res.first <= max(p3.first, p4.first) + eps &&
		   min(p3.second, p4.second) <= res.second + eps && res.second <= max(p3.second, p4.second) + eps;
}

bool Check(const dd &p, int l, int j)
{
	double ax = 1, ay = y[l][j + 1] - y[l][j];
	double bx = p.first - j, by = p.second - y[l][j];
	return ax * by - ay * bx + eps >= 0.0;
}

double Area()
{
	double res = 0.0;
	for (int i = 1; i + 1 < has.size(); i++) {
		double ax = has[i + 1].first - has[0].first, ay = has[i + 1].second - has[0].second;
		double bx = has[i].first - has[0].first, by = has[i].second - has[0].second;
		res += ax * by - ay * bx;
	}
	return fabs(res) / 2.0;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= k; j++)
			scanf("%d", &y[i][j]);
	for (int j = 0; j < k; j++)
		for (int i = 0; i < n; i++) {
			has.clear();
			has.push_back(dd(j, 0.0)); has.push_back(dd(j, y[i][j]));
			has.push_back(dd(j + 1, y[i][j + 1])); has.push_back(dd(j + 1, 0.0));
			for (int l = 0; l < i && !has.empty(); l++) {
				dd pnt; nhas.clear();
				for (int z = 0; z < has.size(); z++)
					if (Inters(dd(j, y[l][j]), dd(j + 1, y[l][j + 1]), has[z], has[(z + 1) % has.size()], pnt)) {
						nhas.push_back(pnt);
						if (Check(has[(z + 1) % has.size()], l, j)) nhas.push_back(has[(z + 1) % has.size()]);
					} else if (Check(has[(z + 1) % has.size()], l, j)) nhas.push_back(has[(z + 1) % has.size()]);
				has = nhas;
			}
			res[i] += Area();
		}
	for (int i = 0; i < n; i++)
		printf("%.12lf\n", res[i]);
	return 0;
}