#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 100005;

int n, x[N], y[N];
string s;
pair<int, int> des, src;

long long find_ans()
{
    long long le = 0, ri = 1E14;
    while (le <= ri)
    {
        long long mi = (le + ri) / 2;
        long long cx = des.fi - src.fi, cy = des.se - src.se;
        cx += 1LL * x[n] * (mi / n) + x[mi % n];
        cy += 1LL * y[n] * (mi / n) + y[mi % n];
        if (abs(cx) + abs(cy) <= mi)
            ri = mi - 1;
        else
            le = mi + 1;
    }
    return le > 1E14 ? -1 : le;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> des.fi >> des.se >> src.fi >> src.se >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        x[i] = x[i - 1]; y[i] = y[i - 1];
        switch (s[i - 1])
        {
        case 'U': y[i]++; break;
        case 'D': y[i]--; break;
        case 'L': x[i]--; break;
        case 'R': x[i]++; break;
        }
    }
    cout << find_ans();
}