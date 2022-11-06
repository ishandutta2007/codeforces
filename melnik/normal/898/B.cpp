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

int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i * a <= n; ++i)
    	if ((n - i * a) % b == 0) {
    		cout << "YES" << endl << i << ' ' << (n - i * a) / b;
    		return 0;
    	}
    cout << "NO" << endl;
    return 0;
}