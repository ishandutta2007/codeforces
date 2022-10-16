#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define double long double

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

typedef complex<int> point;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int64 PREFSUM[maxn];
int64 COUNT[maxn];

void update(int idx, int64 v, int64 *bit){
	while (idx < maxn){
		bit[idx] += v;
		idx += idx & -idx;
	}
}

int64 query(int idx, int64 *bit){
	int64 ans = 0;
	while (idx){
		ans += bit[idx];
		idx -= idx & -idx;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	int64 s = 0;

	double E = 0;
	double I = 1;

	for (int i = 1; i <= n; ++i){
		int v; cin >> v;

		int64 a = query(v, PREFSUM), b = s - a;
		int ta = query(v, COUNT), tb = i - 1 - ta;

		double A = I * a * (n - i + 1) / n / (n + 1);
		double B = I * b * (n - i + 1) / n / (n + 1);

		B = I * tb - B;

		E += A + B;

		update(v, i, PREFSUM);
		update(v, 1, COUNT);
		s += i;
	}

	cout.precision(17);
	cout << fixed << E << endl;

	return 0;
}
/*
3
2 3 1
 */