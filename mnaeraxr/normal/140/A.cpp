#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef complex<double> point;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;
const double PPI = 3.141592653589793;

void end(bool v){
	if (v) cout << "YES" << endl;
	else cout << "NO" << endl;
	exit(0);
}

double dot(const point &a, const point &b)
{
	return real(conj(a) * b);
}

double cross(const point &a, const point &b)
{
	return imag(conj(a) * b);
}

inline double angle(point p, point q, point r)
{
	point u = p-q, v = r-q;
	return abs(atan2(cross(u,v),dot(u,v)));
}

point mnorm(point a){
	double val = sqrt(a.real() * a.real() + a.imag() * a.imag());
	return point(a.real() / val, a.imag() / val);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int r, R;
	cin >> n >> R >> r;

	if (r > R) end(false);
	if (2 * r > R) end(n == 1);
	if (2 * r == R) end(n <= 2);

	double l = R - r;
	double a = sqrt( (l * l) / (r * r) - 1);
	double x = a * l / (a * a + 1);
	double y = a * x;
	double ang = 2 * angle(mnorm(point(x, y)), point(0, 0), point(0, 1));

	end(2 * PPI + EPS >= ang * n);

	return 0;
}