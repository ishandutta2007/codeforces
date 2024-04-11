#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 300500;
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
    int x = 1;
    while (true) {
        int cnt = a / x + b / x;
        if (cnt < n || a / x == 0 || b / x == 0)
            break;
        ++x;
    }
    cout << x - 1 << endl;
    return 0;
}