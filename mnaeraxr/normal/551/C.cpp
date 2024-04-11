#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

int64 V[100100];
int64 n, m;

bool solve(int64 times)
{
	int64 tot = m;
	int64 ex = 0;
	for (int i = 0; i < n; ++i){
		times--;
		if (times == 0) return false;
		if (ex) --ex;
		if (!V[i]) continue;

		int64 cur = V[i];

		if (ex >= cur){
			ex -= cur;
			continue;
		}

		cur -= ex;

		int64 need = (cur + times - 1) / times;
		if (need > tot) return false;

		tot -= need;
		ex = need * times - cur;
		if (ex == times) ex = 0;
	}
	return true;
}

int main()
{
	scanf("%I64d%I64d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%I64d", &V[i]);

	while (n && !V[n - 1]) --n;

	if (n == 0){
		printf("0\n");
		exit(0);
	}

	int64 lo = 0, hi = 1000000000000000;

	while (lo + 1 < hi)
	{
		int64 mid = (lo + hi) / 2;
		if ( solve(mid) ) hi = mid;
		else lo = mid;
	}

	printf("%I64d\n", hi);

	return 0;
}