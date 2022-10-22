#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxb = 42;

int cnt[Maxb];
multiset <ll> S;
int n;
int A, B;
vector <int> V;

int getPw(ll a)
{
	for (ll i = 0; i < Maxb; i++)
		if (a == 1ll << i) return i;
	return -1;
}

bool Check()
{
	for (int i = 0; i + 1 < Maxb; i++)
		for (int j = cnt[i]; j > cnt[i + 1]; j--) {
			ll got = 1ll << ll(i + 1);
			multiset <ll>::iterator it = S.upper_bound(got);
			if (it != S.begin()) {
				it--; S.erase(it);
			}
		}
	return S.empty();
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ll a; scanf("%I64d", &a);
		int p = getPw(a);
		if (p == -1) { B++; S.insert(a); }
		else cnt[p]++;
	}
	for (int i = 0; i + 1 < Maxb; i++)
		while (cnt[i] < cnt[i + 1]) {
			B++; S.insert(1ll << ll(i + 1)); 
			cnt[i + 1]--;
		}
	if (!Check()) { printf("-1\n"); return 0; }
	for (int i = 0; i + 1 < Maxb; i++)
		A += cnt[i] - cnt[i + 1];
	while (A >= B) {
		V.push_back(A);
		for (int i = 0; i + 1 < Maxb; i++)
			if (cnt[i] > cnt[i + 1]) { 
				A--;
				for (int j = 0; j <= i; j++) {
					cnt[j]--; B++;
				}
				break; 
			}
	}
	if (V.empty()) printf("-1\n");
	else {
		sort(V.begin(), V.end());
		for (int i = 0; i < V.size(); i++)
			printf("%d%c", V[i], i + 1 < V.size()? ' ': '\n');
	}
	return 0;
}