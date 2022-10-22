#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const ll lim = 10000000000000000ll;
const int Maxn = 10005;

vector <ll> seq;
int t, n;
ll A1[Maxn], B1[Maxn];
ll A2[Maxn], B2[Maxn];

void Update(int lvl, ll a, ll A[], ll B[])
{
    if (a > seq[lvl - 1]) {
        A[lvl] = 1 + (lvl >= 2? A[lvl - 2]: 0);
        B[lvl] = lvl >= 2? B[lvl - 2]: 0;
    } else {
        A[lvl] = min(A[lvl - 1], B[lvl - 1] + 2);
        B[lvl] = min(A[lvl - 1], B[lvl - 1]) + 1 + (lvl - 1) / 2;
    }
}

void Prec(int lvl, ll a, ll b)
{
    if (lvl == 0) A1[0] = B1[0] = A2[0] = B2[0] = 0;
    else {
        ll na = a > seq[lvl - 1]? a - seq[lvl - 1]: a;
        ll nb = b > seq[lvl - 1]? b - seq[lvl - 1]: b;
        Prec(lvl - 1, na, nb);
        Update(lvl, a, A1, B1);
        Update(lvl, b, A2, B2);
    }
}

ll Dist(int lvl, const ll &a, const ll &b)
{
	if (a == b) return 0ll;
	if (a > seq[lvl - 1]) return Dist(lvl - 2, a - seq[lvl - 1], b - seq[lvl - 1]);
	if (b <= seq[lvl - 1])
        return min(Dist(lvl - 1, a, b), min(A1[lvl - 1] + B2[lvl - 1], B1[lvl - 1] + A2[lvl - 1]) + 2);
    return min(A1[lvl - 1], B1[lvl - 1]) + 1 + (lvl >= 2? A2[lvl - 2]: 0);
}

int main()
{
	seq.push_back(1ll); seq.push_back(2ll);
	while (seq[seq.size() - 2] + seq[seq.size() - 1] <= lim)
		seq.push_back(seq[seq.size() - 2] + seq[seq.size() - 1]);
	seq.push_back(seq[seq.size() - 2] + seq[seq.size() - 1]);
	scanf("%d %d", &t, &n);
	while (t--) {
		ll a, b; scanf("%I64d %I64d", &a, &b);
		if (a > b) swap(a, b);
		int ind = lower_bound(seq.begin(), seq.end(), b) - seq.begin();
		int lvl = min(n, ind + 1);
        Prec(lvl, a, b);
		printf("%I64d\n", Dist(lvl, a, b));
	}
	return 0;
}