#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000000;

int n;
int a[Maxn], b[Maxn];
int oth[Maxn], tp[Maxn];
set <int> S;
int res;
int tlef = -Maxn, trig = Maxn;
int blef = -Maxn, brig = Maxn;
int A, B;

bool Add(int x, bool big)
{
	if (tp[x]) A++;
	else B++;
	if (x <= tlef || x >= trig) return false;
	if (oth[x] <= blef || oth[x] >= brig) return false;
	S.erase(x); S.erase(oth[x]);
	if (big) { trig = x; blef = oth[x]; }
	else { tlef = x; brig = oth[x]; }
	return true;
}

int getLef() { return max(tlef, blef); }

int getRig() { return min(trig, brig); }

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		tp[a[i]] = true;
		oth[a[i]] = b[i];
		oth[b[i]] = a[i];
		S.insert(a[i]);
		S.insert(b[i]);
	}
	while (!S.empty()) {
		A = 0, B = 0;
		Add(*S.begin(), false);
		while (!S.empty())
			if (*S.begin() < getLef())
				while (!S.empty() && *S.begin() < getLef()) {
					if (!Add(*S.begin(), false)) { printf("-1\n"); return 0; }
				}
			else if (*S.rbegin() > getRig())
				while (!S.empty() && *S.rbegin() > getRig()) {
					if (!Add(*S.rbegin(), true)) { printf("-1\n"); return 0; }
				}
			else break;
		res += min(A, B);
	}
	printf("%d\n", res);
    return 0;
}