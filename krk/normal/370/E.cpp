#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n;
vector <ii> seq;
int myl[Maxn], myr[Maxn];
int L[Maxn], R[Maxn];
int res[Maxn];

bool Dec()
{
	for (int i = 1; i < seq.size(); i++)
		if (seq[i - 1].first > seq[i].first)
			return true;
	return false;
}

int canGet()
{
	int pnt = 0;
	int res = -1;
	for (int i = 1; i < Maxn; i++) {
		if (pnt < seq.size() && seq[pnt].first == i) {
			int l = seq[pnt++].second;
			int r = l;
			while (pnt < seq.size() && seq[pnt].first == i)
				r = seq[pnt++].second;
			if (r - l + 1 > 5) return -1;
			myl[i] = l; myr[i] = r;
			L[i] = Maxn; R[i] = -1;
			for (int froml = 0; froml <= 4; froml++)
				for (int fromr = 0; fromr <= 4 - froml; fromr++) {
					int tot = froml + r - l + 1 + fromr;
					if (tot < 2 || tot > 5) continue;
					int ends = l - froml - 1;
					if (L[i - 1] <= ends && ends <= R[i - 1]) {
						L[i] = min(L[i], r + fromr); R[i] = max(R[i], r + fromr);
					}
				}
			if (L[i] > n) return -1;
		} else { L[i] = L[i - 1] + 2; R[i] = R[i - 1] + 5; myl[i] = -1; }
		if (n <= R[i])
			if (L[i] <= n) res = i;
			else return pnt == seq.size()? res: -1;
	}
}

void getRes(int from)
{
	int lst = n;
	for (int i = from; i > 0; i--) {
		int tk = 2;
		while (myl[i] != -1 && myl[i] <= lst - tk || R[i - 1] < lst - tk)
			tk++;
		while (tk--) res[lst--] = i;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		if (a) seq.push_back(ii(a, i));
	}
	if (Dec()) printf("-1\n");
	else {
		int r = canGet();
		if (r == -1) printf("-1\n");
		else {
			getRes(r);
			printf("%d\n", r);
			for (int i = 1; i <= n; i++)
				printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
		}
	}
	return 0;
}