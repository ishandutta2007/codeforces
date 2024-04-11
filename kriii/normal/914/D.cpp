#include <stdio.h>
#include <vector>
using namespace std;

const int Z = 1 << 19;
int N,IT[Z*2];

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int go(int i, int x)
{
	if (IT[i] % x == 0) return 0;
	if (i >= Z) return 1;
	int c = go(i * 2, x);
	if (c > 1) return 2;
	c += go(i * 2 + 1, x);
	if (c > 1) return 2;
	return c;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &IT[i + Z]);
	for (int i = Z - 1; i >= 1; i--) IT[i] = gcd(IT[i * 2], IT[i * 2 + 1]);

	int Q; scanf("%d", &Q); while (Q--) {
		int o; scanf("%d", &o);
		if (o == 1) {
			int l, r, x; scanf("%d %d %d", &l, &r, &x);
			vector<int> cand;
			l += Z; r += Z;
			while (l < r) {
				if (l & 1) cand.push_back(l++);
				if (~r & 1) cand.push_back(r--);
				l /= 2; r /= 2;
			} if (l == r) cand.push_back(l);
			
			int cnt = 0;
			for (auto &i : cand) {
				cnt += go(i,x);
				if (cnt > 1) break;
			}

			puts(cnt <= 1 ? "YES" : "NO");
		}
		else {
			int i, x; scanf("%d %d", &i, &x);
			i += Z; IT[i] = x; i /= 2;
			while (i) {
				IT[i] = gcd(IT[i * 2], IT[i * 2 + 1]);
				i /= 2;
			}
		}
	}

	return 0;
}