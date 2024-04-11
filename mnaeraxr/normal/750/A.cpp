#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
#endif

    int n, k;
    cin >> n >> k;

    int v = (240 - k) / 5;

    int s = 0, t = 0;

    while (s + t + 1 <= v)
        s += ++t;

    cout << min(t, n) << endl;

    return 0;
}