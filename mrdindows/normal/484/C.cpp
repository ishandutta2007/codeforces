#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <complex>
#include <functional>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cctype>
#include <climits>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pnt;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int MAXN = 1e6 + 10;
int ne[MAXN], l[MAXN];
int one[MAXN];
int n;
int g[MAXN];
void D(int *a, int *b)
{
    for (int i = 0; i < n; i++)
        g[i] = b[a[i]];
    for (int i = 0; i < n; i++)
        a[i] = g[i];
}
void Pow(int deg)
{
    int new_deg = 0;
    int cnt = 0;
    while (deg > 0)
    {
        cnt++;
        new_deg *= 2;
        new_deg += (deg % 2);
        deg /= 2;
    }
    while (new_deg > 0 || cnt > 0)
    {
        D(one, one);
        if (new_deg % 2)
            D(one, ne);
        new_deg /= 2;
        cnt--;
    }
}
void solve(int k, int d, string &s)
{
    for (int i = 0; i < n; i++)
        one[i] = i;
    int cnt = 0;

    for (int i = 0; i < d; i++)
        for (int j = 0; j * d + i < k; j++)
            ne[j * d + i] = cnt++;
    for (int i = k; i < n; i++)
        ne[i] = i;
    for (int i = 0; i < n; i++)
        l[i] = (i + n - 1) % n;
    D(ne, l);
    Pow(n + 1 - k);
    //return;
    string ans = s;
    for (int i = 0; i < n; i++)
        ans[(one[i] + n - k + 1) % n ] = s[i];
    s = ans;
cout << s << '\n';
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
cin.tie(0);
    string s;
    getline(cin, s);
    n = s.size();
    int m;
    cin >> m;
    int k[m];
    int d[m];
    for (int i = 0; i < m; i++)
    {
        cin >> k[i] >> d[i];
        solve(k[i], d[i], s);
    }
    return 0;
}