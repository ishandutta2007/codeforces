#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

int T;
ll a, b, c, d;
map <int, int> M;
vector <ii> seq;
bool don;

void Add(ll x)
{
    for (int i = 2; i * i <= x; i++)
        while (x % i == 0) {
            M[i]++;
            x /= i;
        }
    if (x > 1) M[x]++;
}

ll isIn(ll x, ll a, ll b)
{
    ll nxt = a / x * x + x;
    return nxt <= b? nxt: -1;
}

void Check(ll x)
{
    ll y = a * b / x;
    auto got1 = isIn(x, a, c);
    auto got2 = isIn(y, b, d);
    if (got1 > 0 && got2 > 0) {
        printf("%I64d %I64d\n", got1, got2);
        don = true;
    }
}

void Gen(int lvl, ll cur)
{
    if (lvl >= seq.size())
        Check(cur);
    else for (int i = 0; i <= seq[lvl].second && !don; i++) {
            Gen(lvl + 1, cur);
            cur *= seq[lvl].first;
        }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d);
        M.clear();
        Add(a);
        Add(b);
        seq.clear();
        for (auto p: M)
            seq.push_back(p);
        don = false;
        Gen(0, 1);
        if (!don) printf("-1 -1\n");
    }
    return 0;
}