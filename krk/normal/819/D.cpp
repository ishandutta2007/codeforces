#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 200005;

int T, n;
int a[Maxn];
map <int, int> M;
int res[Maxn];
map <int, vector <ii> > my;
int g, slen;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

void addMap(int key, int val)
{
    if (M.find(key) == M.end())
        M.insert(make_pair(key, val));
}

void Print()
{
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
}

void gcd(int a, int &x, int b, int &y, int &g)
{
    if (a == 0) { x = 0; y = 1; g = b; }
    else {
        int xx, yy; gcd(b % a, xx, a, yy, g);
        x = yy - b / a * xx;
        y = xx;
    }
}

int Solve(int a, int b, int c)
{
    int x, y;
    int cur;
    gcd(a, x, b, y, cur);
    assert(c % cur == 0);
    x = ll(x) * (c / cur) % b;
    if (x < 0) x += b;
    return x % slen;
}

int main()
{
    scanf("%d %d", &T, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    addMap(0, 1);
    int sum = 0;
    for (int i = 2; i <= n; i++) {
        sum = (sum + a[i]) % T;
        addMap(sum, i);
    }
    sum = (sum + a[1]) % T;
    if (sum == 0) {
        for (auto p: M)
            res[p.second] = 1;
        Print();
        return 0;
    }
    g = gcd(sum, T);
    slen = T / g;
    for (auto p: M) {
        int key = p.first % g;
        ii val = ii(Solve(sum, T, p.first - key), p.second);
        my[key].push_back(val);
    }
    for (auto p: my) {
        sort(p.second.begin(), p.second.end());
        for (int j = 0; j + 1 < p.second.size(); j++)
            res[p.second[j].second] = p.second[j + 1].first - p.second[j].first;
        res[p.second.back().second] = slen + p.second[0].first - p.second.back().first;
    }
    Print();
    return 0;
}