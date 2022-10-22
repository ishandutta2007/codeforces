#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ld, int> ldi;
typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
int X[Maxn], Y[Maxn];
vector <ldi> seq;
ii p;
int res[Maxn];

ll Len(const ii &p) { return ll(p.first) * p.first + ll(p.second) * p.second; }

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &X[i], &Y[i]);
		res[i] = 1;
		if (ii(X[i], Y[i]) < ii(-X[i], -Y[i])) {
			X[i] = -X[i]; Y[i] = -Y[i];
			res[i] = -1;
		}
		seq.push_back(ldi(atan2(ld(Y[i]), ld(X[i])), i));
	}
	sort(seq.begin(), seq.end());
	for (int i = 0; i < seq.size(); i++) {
		int ind = seq[i].second;
		ii a = ii(p.first + X[ind], p.second + Y[ind]);
		ii b = ii(p.first - X[ind], p.second - Y[ind]);
		if (Len(a) < Len(b)) p = a;
		else { p = b; res[ind] *= -1; }
	}
	assert(Len(p) <= 2250000000000ll);
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}