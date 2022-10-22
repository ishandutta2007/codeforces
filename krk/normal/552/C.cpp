#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

int w, m;
ll cur;
vector <ll> seq;

int main()
{
	scanf("%d %d", &w, &m);
	if (w == 2) { printf("YES\n"); return 0; }
	cur = 1; seq.push_back(1);
	while (cur <= m) {
		cur *= w;
		seq.push_back(cur);
	}
	for (int i = 0; i < 1 << seq.size(); i++) {
		ll add = m;
		for (int j = 0; j < seq.size(); j++)
			if (i & 1 << j) add += seq[j];
		bool ok = true;
		for (int j = 0; j < seq.size() && ok; j++) {
			if (add % w == 1) {
				ok = !(i & 1 << j); add--;
			} else if (add % w) ok = false;
			add /= w;
		}
		if (ok && add == 0) { printf("YES\n"); return 0; }
	}
	printf("NO\n");
	return 0;
}