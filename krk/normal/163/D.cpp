#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;
typedef long double ld;
typedef pair <int, int> ii;

const ll Inf = 9000000000000000000ll;

map <ll, ii> M;
int T;
ll n;
lli pr[20];
int plen;
ll A;
ll best;
int wA, wB;
ll wC;
int res, resA;

void genB(int lvl, int val, int rem)
{
	if (lvl >= plen || rem < pr[lvl].first) {
		ll C = n / A / val;
		ll cand = A * (val + C) + val * C;
		if (cand < best) {
			best = cand;
			wA = A; wB = val; wC = C;
		} 
		res++;
	} else for (int i = 0; i <= pr[lvl].second; i++) {
		genB(lvl + 1, val, rem);
		if (rem >= pr[lvl].first) {
			rem /= pr[lvl].first;
			val *= pr[lvl].first;
		}
		else break;
	}
}

void genA(int lvl, int val, int rem)
{
	if (lvl >= plen || rem < pr[lvl].first) {
		A = val;
		resA++;
		int lim2 = sqrtl(ld(n / A)) + 0.5;
		int X = max(1, lim2 - 1);
		ll cand = 2 * ll(A) * X + n / A;
		if (cand < best) genB(0, 1, lim2);
	} else for (int i = 0; i <= pr[lvl].second; i++) {
		pr[lvl].second -= i;
		genA(lvl + 1, val, rem);
		pr[lvl].second += i;
		if (rem >= pr[lvl].first) {
			rem /= pr[lvl].first;
			val *= pr[lvl].first;
		}
		else break;
	}
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		n = 1;
		scanf("%d", &plen);
		for (int i = 0; i < plen; i++) {
			scanf("%I64d %d", &pr[i].first, &pr[i].second);
			for (int j = 0; j < pr[i].second; j++)
				n *= pr[i].first;
		}
		auto it = M.find(n);
		if (it == M.end()) {
			sort(pr, pr + plen);
			best = Inf;
			ll lim = powl(ld(n), 1.0l / 3.0l) + 0.5;
			genA(0, 1, lim);
			M.insert(make_pair(n, ii(wA, wB)));
		} else {
			wA = it->second.first;
			wB = it->second.second;
			wC = n / wA / wB;
			best = wA * (wB + wC) + wB * wC;
		}
		printf("%I64d %d %d %I64d\n", 2ll * best, wA, wB, wC);
	}
    return 0;
}