#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long LL;
typedef long double ld;
#define MP make_pair
#define F first
#define S second

const LL INF = (LL)1e18;
const string Y = "YES";
const string N = "NO";

int c[100];
int kids[100];
int n;
int big;
int small;

bool rec(int pos)
{
    if (pos == big)
    {
        int f = 0;
        for (int i = 0; i < big; i++)
        {
            //assert(c[i] >= 1);
            f += c[i] - 1;
        }
        if (f != small)
            return false;
        for (int i = 0; i < big; i++)
            if (c[i] - 1 + kids[i] < 2)
                return false;
        return true;
    }
    for (int j = 0; j < pos; j++)
    {
        if (c[j] <= c[pos])
            continue;
        c[j] -= c[pos];
        kids[j]++;
        bool ok = rec(pos + 1);
        c[j] += c[pos];
        kids[j]--;
        if (ok)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    if (n == 1)
    {
        if (c[0] == 1)
            cout << Y;
        else
            cout << N;
        return 0;
    }
    sort(c, c + n);
    reverse(c, c + n);
    small = 0;
    for (int i = 0; i < n; i++)
        if (c[i] == 1)
            small++;
    big = n - small;
    if (big > small - 1 || c[0] != n)
    {
        cout << N;
        return 0;
    }
    assert(big <= 11);
    fill(kids, kids + big, 0);
    if (rec(1))
        cout << Y;
    else
        cout << N;

    return 0;
}