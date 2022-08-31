#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> Vint;
typedef long double ld;

const int N = (int)1e5 + 10;
char str[N];

void update (int l, int r, int c)
{
    memset(str + l, c + '0', (r - l + 1) * sizeof(char));
}
bool check (int l, int r, int d)
{
    if (d == r - l + 1)
        return true;
    return memcmp(str + l, str + l + d, (r - l + 1 - d) * sizeof(char)) == 0;
}

void solve (int n)
{
    int m, k;
    cin >> m >> k;
    scanf(" %s", str);
    assert(strlen(str) == n);
    int q = m + k;

    for (int i = 0; i < q; i++)
    {
        int t, l, r, d;
        scanf(" %d %d %d %d", &t, &l, &r, &d);
        --l, --r;
        if (t == 1)
            update(l, r, d);
        else
        {
            bool ok = check(l, r, d);
            if (ok)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    while (cin >> n)
        solve(n);
}