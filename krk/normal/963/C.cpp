#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const int Maxn = 200005;

int n;
map <ll, map <ll, ll> > M;
map <ll, ll> byrow, bycol;
int res;

ll gcd(ll a, ll b) { return a? gcd(b % a, a): b; }

llll Rat(ll a, ll b)
{
    ll g = gcd(a, b);
    return llll(a / g, b / g);
}

void Update(map <ll, ll> &M, ll key, ll val)
{
    auto it = M.find(key);
    if (it == M.end()) M.insert(make_pair(key, val));
    else it->second = min(it->second, val);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ll a, b, c; scanf("%I64d %I64d %I64d", &a, &b, &c);
        M[a][b] = c;
    }
    auto st = M.begin();
    auto it = M.begin();
    for (it++; it != M.end(); it++) {
        if (it->second.size() != st->second.size()) {
            printf("0\n"); return 0;
        }
        auto stit = st->second.begin();
        auto itit = it->second.begin();
        if (stit->first != itit->first) {
            printf("0\n"); return 0;
        }
        llll p = Rat(stit->second, itit->second);
        for (stit++, itit++; stit != st->second.end(); stit++, itit++)
            if (stit->first != itit->first) {
                printf("0\n"); return 0;
            } else {
                llll u = Rat(stit->second, itit->second);
                if (u != p) { printf("0\n"); return 0; }
            }
    }
    ll g = 0;
    for (auto it = M.begin(); it != M.end(); it++)
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
            g = gcd(g, it2->second);
    for (ll i = 1; i * i <= g; i++) if (g % i == 0) {
        res++;
        if (g / i != i) res++;
    }
    printf("%d\n", res);
    return 0;
}