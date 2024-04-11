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

    vector<int> a(4);
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    string s;
    cin >> s;
    int res = 0;
    for (char c : s)
        res += a[c - '1'];
    cout << res;

    return 0;
}