#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long LL;
typedef long double ld;
#define MP make_pair
#define F first
#define S second


int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int, int> in, out;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        in[a[i]]++;
        out[b[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        in[a[i]]--;
        out[b[i]]--;
        int tot = 2 * n - 2;
        int f = n - 1 + in[b[i]];
        cout << f << " " << tot - f << "\n";
        in[a[i]]++;
        out[b[i]]++;
    }
    return 0;
}