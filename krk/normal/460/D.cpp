#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int Maxb = 42;

ll l, r, k;
ll res = 1ll << ll(Maxb);
vector <ll> best;
vector <ll> seq;

void Gen(ll lvl, ll cand)
{
    if (seq.size() > k) return;
    if (lvl > r) {
        if (seq.size() > 0 && cand < res) {
            res = cand; best = seq;
        }
    } else {
        Gen(lvl + 1, cand);
        seq.push_back(lvl);
        Gen(lvl + 1, lvl ^ cand);
        seq.pop_back();
    }
}

void getPair(ll r, ll b, ll &u, ll &v)
{
    u = v = 1ll << b; b--;
    for (; b >= 0; b--)
        if (r & 1ll << b) break;
    u |= 1ll << b; b--;
    for (; b >= 0; b--) v |= 1ll << b;
}

bool Check3()
{
    ll b = Maxb - 1;
    ll L = l, R = r;
    while (!(L & 1ll << b) && !(R & 1ll << b)) b--;
    for (; b >= 1; b--) {
        if ((L & 1ll << b) && (R & 1ll << b)) return false;
        ll u, v; getPair(R, b, u, v);
        if ((u ^ v) >= L) {
            res = 0; best.push_back(u ^ v); best.push_back(v); best.push_back(u);
            return true;
        }
        R = (1ll << b) - 1;
    }
    return false;
}

int main()
{
    scanf("%I64d %I64d %I64d", &l, &r, &k);
    if (r - l + 1 <= 8) Gen(l, 0);
    else if (k == 1) { res = l; best.push_back(l); }
    else if (k == 2) {
        if (l & 1) l++;
        res = 1; best.push_back(l); best.push_back(l + 1);
    } else if (k == 3) {
        if (Check3()) {
        } else {
            if (l & 1) l++;
            res = 1; best.push_back(l); best.push_back(l + 1);
        }
    } else {
        while (l & 3) l++;
        res = 0; best.push_back(l); best.push_back(l + 1); best.push_back(l + 2); best.push_back(l + 3);
    }
    printf("%I64d\n", res);
    printf("%d\n", best.size());
    for (int i = 0; i < best.size(); i++)
        printf("%I64d%c", best[i], i + 1 < best.size()? ' ': '\n');
    return 0;
}