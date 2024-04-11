#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;

int hpy, atky, defy;
int hpm, atkm, defm;
int h, a, d;
ll best = Inf;

int getHP(int atky, int defy)
{
	int myht = atky - defm;
	int tims = hpm / myht;
	if (tims * myht < hpm) tims++;
	int mht = max(0, atkm - defy);
	int lft = hpy - mht * tims;
	if (lft > 0) return 0;
	return -lft + 1;
}

int main()
{
	scanf("%d %d %d", &hpy, &atky, &defy);
	scanf("%d %d %d", &hpm, &atkm, &defm);
	scanf("%d %d %d", &h, &a, &d);
	for (int ba = max(0, defm + 1 - atky); ba <= 250; ba++)
		for (int bd = 0; bd <= 150; bd++) {
			int bh = getHP(atky + ba, defy + bd);
			best = min(best, ll(h) * bh + ll(a) * ba + ll(d) * bd);
		}
	printf("%I64d\n", best);
	return 0;
}