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

    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        y = 5 - y;
        if (y >= k)
            cnt++;
    }
    cout << cnt / 3;

    return 0;
}