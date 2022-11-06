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
    int n;
    cin >> n;
    int d1 = n - 10 * (n / 10);
    int d2 = 10 * (n / 10 + 1) - n;
    if (d1 < d2)
    	cout << 10 * (n / 10);
    else
    	cout << 10 * (n / 10 + 1);
    return 0;
}