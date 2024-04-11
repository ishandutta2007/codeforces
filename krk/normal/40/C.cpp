#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 400005;
const int nil = 200001;

int n, x, m, y;
vector <ii> seq;
int BIT[Maxn];
bool lef[Maxn], rig[Maxn];
ll res = 1ll;

int Get(int x)
{
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

void Insert(int x, int val)
{
	for (int i = x; i < Maxn; i += i & -i)
		BIT[i] += val;
}

int main()
{
	scanf("%d %d %d %d", &n, &x, &m, &y);
	for (int i = 1; i <= n; i++)
		seq.push_back(ii(i, x));
	for (int i = 1; i <= m; i++)
		seq.push_back(ii(i, y));
	sort(seq.begin(), seq.end());
	for (int i = 0; i < seq.size(); i++) {
		int inter = Get(seq[i].second - seq[i].first + nil) + Get(seq[i].second + seq[i].first + nil);
		bool was = lef[seq[i].second - seq[i].first + nil] || rig[seq[i].second + seq[i].first + nil];
		res += was? max(2 * inter + 1, 1): max(2 * inter, 1);
		Insert(seq[i].second - seq[i].first + 1 + nil, 1); Insert(seq[i].second + seq[i].first + nil, -1);
		lef[seq[i].second - seq[i].first + nil] = rig[seq[i].second + seq[i].first + nil] = true;
	}
	printf("%I64d\n", res);
	return 0;
}