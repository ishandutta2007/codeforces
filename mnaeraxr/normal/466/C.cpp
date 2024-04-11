#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;

const int INF = 1<<30;
const double EPS = 1e-9;
const int MAXN = 5e5 + 100;

int64 L[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		int64 v;
		cin >> v;
		L[i] = v + L[i - 1];
	}

	int64 ans = 0, counter = 0;

	if (L[T] % 3)
	{
		cout << 0 << endl;
	}
	else
	{
		int64 f = L[T] / 3;
		int64 s = 2 * f;

		for (int i = 1; i < T; ++i)
		{
			if (L[i] == s)
				ans += counter;
			if (L[i] == f)
				counter++;
		}
		cout << ans << endl;
	}
	return 0;
}