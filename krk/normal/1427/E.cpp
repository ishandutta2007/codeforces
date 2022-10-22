#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxb = 62;
const ll Inf = 1000000000000000000ll;

int x;
vector <ll> res1, res2;
vector <char> resop;
ll my[Maxb];

ll Add(ll x, ll lim)
{
    for (int i = Maxb - 1; i >= 0; i--)
        if (x & 1ll << ll(i))
            if (my[i] == 0) {
                if (x < lim) return x;
                my[i] = x;
                return -1;
            }
            else x ^= my[i];
    return x;
}

void resAdd(ll a, ll b)
{
    res1.push_back(a);
    res2.push_back(b);
    resop.push_back('+');
}

void resXor(ll a, ll b)
{
    res1.push_back(a);
    res2.push_back(b);
    resop.push_back('^');
}

void printXor(ll cur)
{
    for (int i = Maxb - 1; i >= 0; i--)
        if (cur & 1ll << ll(i))
            if (my[i] == 0) break;
            else { resXor(cur, my[i]); cur ^= my[i]; }
}

void Solve(ll x)
{
    if (x == 1) return;
    if (x % 2 == 0) {
        ll cur = x;
        Add(cur, x);
        while (true) {
            resAdd(cur, cur);
            cur *= 2;
            ll got = Add(cur, x);
            if (got > 0) {
                printXor(cur);
                Solve(got);
                return;
            }
        }
    }
    fill(my, my + Maxb, 0ll);
    ll cur = x;
    Add(cur, x);
    while (true) {
        resAdd(cur, cur);
        cur *= 2;
        Add(cur, x);
        for (int i = 1; i <= 10; i++) {
            ll got = Add(cur + i * x, x);
            if (got > 0) {
                for (int z = 0; z < i; z++)
                    resAdd(cur + z * x, x);
                printXor(cur + i * x);
                Solve(got);
                return;
            }
        }
    }
}

int main()
{
    scanf("%d", &x);
    Solve(x);
    printf("%d\n", int(res1.size()));
    for (int i = 0; i < res1.size(); i++)
        printf("%I64d %c %I64d\n", res1[i], resop[i], res2[i]);
    return 0;
}