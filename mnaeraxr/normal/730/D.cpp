#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;
const int64 MAX = 100000;

int n;
int64 r;

int64 L[maxn], T[maxn];
int64 ANS[maxn], pnt = 0;

int64 add(int64 a, int64 b, int64 r, int64 &ans){
	int64 tot = (b - a + r - 1) / r;

	if (tot + pnt > MAX) pnt = MAX + 1;
	else{
		for (int i = 0; i < tot; ++i)
			ANS[pnt++] = a + r * i;
	}

	ans += tot;

	return tot * r - (b - a);
}

void bad(){
	cout << -1 << endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r;

	for (int i = 0; i < n; ++i) cin >> L[i];
	for (int i = 0; i < n; ++i) cin >> T[i];

	int64 acc = 0;
	int64 ans = 0;
	int64 curmoment = 0;

	for (int i = 0; i < n; ++i){
		int64 l = L[i], t = T[i];

		if (t < l) bad();

		int64 d = min(acc, l);
		l -= d; t -= d; acc -= d; curmoment += d;

		if (l == 0) continue;

		if (2 * l <= t){
			curmoment += 2 * l;
			continue;
		}

		acc = add(curmoment + 2 * (t - l), curmoment + t, r, ans);
		curmoment += t;
	}

	cout << ans << endl;

	if (pnt <= MAX){
		for (int i = 0; i < pnt; ++i)
			cout << ANS[i] << " "[i + 1 == pnt];
	}

	return 0;
}