#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 400005;
const int Inf = 1000000000;
const int mod = 1000000007;

char tmp[20];
int n;
set <int> A, M, B;
int res = 1;

int main()
{
	A.insert(-Inf); B.insert(Inf);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", tmp);
		int p; scanf("%d", &p);
		auto it = A.end(); it--;
		int lst = *it;
		int fir = *B.begin();
		if (tmp[1] == 'D')
			if (p < lst) A.insert(p);
			else if (p > fir) B.insert(p);
			else M.insert(p);
		else if (p < lst) { printf("0\n"); return 0; }
			 else if (p == lst) {
			 	A.erase(it);
			 	auto it2 = M.begin();
			 	while (it2 != M.end()) { B.insert(*it2); M.erase(it2++); }
			 } else if (p < fir) {
			 	res = ll(res) * 2 % mod;
			 	auto it2 = M.begin();
			 	while (it2 != M.end()) {
			 		if (*it2 < p) A.insert(*it2);
			 		else if (*it2 > p) B.insert(*it2);
			 		M.erase(it2++);
			 	}
			 } else if (p == fir) {
			 	B.erase(B.begin());
			 	auto it2 = M.begin();
			 	while (it2 != M.end()) { A.insert(*it2); M.erase(it2++); }
			 } else { printf("0\n"); return 0; }
	}
	res = ll(res) * (ll(M.size()) + 1ll) % mod;
	printf("%d\n", res);
	return 0;
}