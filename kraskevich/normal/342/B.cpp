#include <bits/stdc++.h>

using namespace std;

const int N = 100 * 1000 + 10;

int t[N];
int l[N], r[N];
int n, m, s, f;
string res;

bool in(int L, int R, int x)
{
    return L <= x && x <= R;
}


int main()
{
    ios_base::sync_with_stdio(0);
    #if defined DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n >> m >> s >> f;
    int time = 1;
    for (int i = 0; i < m; i++)
        cin >> t[i] >> l[i] >> r[i];
    while (s != f)
    {
        int pos = lower_bound(t, t + m, time) - t;
        int L = -1, R = -1;
        if (pos != m && t[pos] == time)
            L = l[pos], R = r[pos];
        time++;
        if (f < s)
        {
            if (!in(L, R, s) && !in(L, R, s - 1))
                res += 'L', s--;
            else
                res += 'X';
        }
        else
        {
            if (!in(L, R, s) && !in(L, R, s + 1))
                res += 'R', s++;
            else
                res += 'X';
        }
    }
    cout << res;

    return 0;
}