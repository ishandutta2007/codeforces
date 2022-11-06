#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];

void UpdateAns(int &x, int &y, int i, int j) {
	if (1LL * x * j < 1LL * i * y) {
		x = i;
		y = j;
	}
}

int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
   	int n, u;
   	scanf ("%d%d", &n, &u);
   	for (int i = 0; i < n; ++i)
   		scanf ("%d", &a[i]);
   	int ans1 = 0, ans2 = 1;
   	for (int i = 0; i < n; ++i) {
   		int l = i + 2;
   		int r = n - 1;
   		if (r < l)
   			continue;
   		while (r - l) {
   			int mid = (l + r + 1) >> 1;
   			if (a[mid] - a[i] <= u)
   				l = mid;
   			else
   				r = mid - 1;
   		}
   		if (a[l] - a[i] > u)
   			continue;
   		UpdateAns(ans1, ans2, a[l] - a[i + 1], a[l] - a[i]);
   	}
   	if (!ans1)
   		cout << -1 << endl;
   	else
   		cout << fixed << setprecision(20) << 1.0L * ans1 / ans2 << endl;

    return 0;
}