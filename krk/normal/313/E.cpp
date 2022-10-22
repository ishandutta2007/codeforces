#include <cstdio>
#include <set>
using namespace std;

const int Maxn = 100005;

int n, m;
multiset <int> a, b;
int res[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int num; scanf("%d", &num);
		a.insert(num);
	}
	for (int i = 0; i < n; i++) {
		int num; scanf("%d", &num);
		b.insert(num);
	}
	multiset <int>::iterator alst, blst;
	multiset <int>::iterator fa, fb;
	while (!a.empty()) {
		alst = a.end(); alst--;
		blst = b.end(); blst--;
		if (*alst + *blst < m) { res[*alst + *blst]++; a.erase(alst); b.erase(blst); continue; }
		if (*alst + *b.begin() >= m && *blst + *a.begin() >= m) { res[(*alst + *blst) % m]++; a.erase(alst); b.erase(blst); continue; }
		if (*alst + *b.begin() >= m) {
			fb = a.lower_bound(m - *blst); fb--;
			res[*fb + *blst]++; a.erase(fb); b.erase(blst); continue;
		}
		if (*blst + *a.begin() >= m) {
			fa = b.lower_bound(m - *alst); fa--;
			res[*fa + *alst]++; a.erase(alst); b.erase(fa); continue;
		}
		fb = a.lower_bound(m - *blst); fb--;
		fa = b.lower_bound(m - *alst); fa--;
		if (*fb + *blst > *fa + *alst) { res[*fb + *blst]++; a.erase(fb); b.erase(blst); }
		else { res[*fa + *alst]++; a.erase(alst); b.erase(fa); }
	}
	bool pr = false;
	for (int i = Maxn - 1; i >= 0; i--)
		for (int j = 0; j < res[i]; j++) {
			if (pr) printf(" ");
			else pr = true;
			printf("%d", i);
		}
	printf("\n");
	return 0;
}