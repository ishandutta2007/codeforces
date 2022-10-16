#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)2e5 + 10;

pair<pii,int> SG[MAXN];
multimap<int64,int64> BR;
int RSG[MAXN];
int ans[MAXN];

bool compare(int a, int b){
	return SG[a] < SG[b];
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	int64 l1, r1;
	scanf("%I64d%I64d", &l1, &r1);

	for (int i = 1; i < n; ++i){
		int64 l2, r2;
		scanf("%I64d%I64d", &l2, &r2);
		SG[i - 1] = {{r2 - l1, l2 - r1}, i - 1};
		RSG[i - 1] = i - 1;
		l1 = l2, r1 = r2;
	}

	for (int i = 0; i < m; ++i){
		int64 sz;
		scanf("%I64d", &sz);
		BR.insert({sz, i + 1});
	}

	sort(RSG, RSG + n - 1, compare);

	for (int i = 0; i < n - 1; ++i)
	{
		int idx = RSG[i];
		auto segment = SG[idx];
//
		auto cur = BR.lower_bound(segment.first.second);
		if (cur == BR.end() || cur->first > segment.first.first){
			printf("No\n");
			exit(0);
		}
		ans[segment.second] = cur->second;
		BR.erase(cur);
	}

	printf("Yes\n");
	for (int i = 0; i < n - 1; ++i)
		printf("%d ", ans[i]);
	putchar('\n');

	return 0;
}