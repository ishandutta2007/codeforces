#include <bits/stdc++.h>

using namespace std;

const int INF = 1000 * 1000 * 1000;

int main()
{
    ios_base::sync_with_stdio(0);
    #if defined DEBUG
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    long long n, m, cur = 0;
    long long res = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        long long x;
        cin >> x;
        --x;
        if (x < cur)
            res += n - cur + x;
        else
            res += x - cur;
        cur = x;
    }
    cout << res;

    return 0;
}