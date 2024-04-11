#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define u64 unsigned long long int

u64 ff(int t, u64 B) {
	if (t == 0)return B;
	if (t == 1 || t == 3) {
		u64 x = B, y = B + 1;
		if (x % 2==0)x /= 2;else y /= 2;
		x *= y;
		return t == 3 ? x * x : x;
	}
	u64 x = B, y = B + 1, z = 2 * B + 1;
	if (x % 2==0)x /= 2;else
		y /= 2;
	if (x % 3 == 0)x /= 3;else
		if (y % 3 == 0)y /= 3;
		else
			z /= 3;
	return x * y*z;
}
u64 pp(int t, u64 B) {
	if (t == 0)return 1;
	if (t == 1)return B;
	if (t == 2)return B * B;
	return B * B * B;
}

u64 n;int m;
vector<u64> A[4];
vector<u64> B[4];
vector<u64> P;
u64 calc(u64 w, int id, u64 f,int cc) {
	u64 cnt = (w > m ? B[0][n / w] : A[0][w]) - (u64)id;
	u64 ret = cnt * f + (w > m ? B[cc][n / w] : A[cc][w]) - ((u64)(A[cc][P[id] - 1]));
	for (int i = id; i<P.size(); i++) {
		u64 p = P[i];
		u64 q = (u64)p*p;
		if (q > w)break;
		ret += calc(w / p, i + 1, f + pp(cc, p), cc);
		int e = 1;
		while (1) {
			++e;
			u64 f2 = f + pp(cc, p) * e;
			ret += f2;
			u64 qq = q * p;
			if (qq <= w) {
				ret += calc(w / q, i + 1, f2, cc);
				q = qq;
			}
			else
				break;
		}
	}
	return ret;
}

int main() {
		u64 x;
		cin >> x;

		n = x;
		m = (int)sqrt(n + .5);
		for (int i = 0; i < 4; i++) {
			A[i].resize(m + 1);
			B[i].resize(m + 1);
		}
		P.clear();
		for (int i = 1; i <= m; i++) {
			for (int j = 0; j < 4; j++) {
				A[j][i] = ff(j, i) - 1;
				B[j][i] = ff(j, n / i) - 1;
			}
		}
		for (u64 p = 2; p <= m; p++) {
			if (A[0][p] == A[0][p - 1])continue;
			P.push_back(p);
			u64 d[4];
			for (int j = 0; j < 4; j++)d[j] = A[j][p - 1];
			u64 p2 = (u64)p * p;
			u64 to = min(n / p2, (u64)m);
			u64 mid = m / p;
			for (int i = 1; i <= mid; i++) {
				for (int j = 0; j < 4; j++) {
					u64 cur = B[j][i*p] - d[j];
					for (int x = 0; x < j; x++)cur *= p;
					B[j][i] -= cur;
				}
			}
			u64 tmp = n / p;
			for (int i = mid + 1; i <= to; i++) {
				for (int j = 0; j < 4; j++) {
					u64 cur = A[j][tmp / i] - d[j];
					for (int x = 0; x < j; x++)cur *= p;
					B[j][i] -= cur;
				}
			}
			for (int i = m; i >= p2; i--) {
				for (int j = 0; j < 4; j++) {
					u64 cur = A[j][i/p] - d[j];
					for (int x = 0; x < j; x++)cur *= p;
					A[j][i] -= cur;
				}
			}
		}
		P.push_back(m + 1);

		u64 res = 0, coef;
		for (int i = 3; i >= 0; i--) {
			cin >> coef;
			res += coef * (n > 1 ? calc(n, 0, 0, i) : 0);
		}
		printf("%u\n", (unsigned int)(res & 4294967295ULL));
		return 0;
}