#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;
typedef long double ld;
typedef pair <ld, llll> ldllll;

ll n;
int m;
map <ll, llll> M;
ll A, B;
priority_queue <ldllll> Q;

ll getVal(const map <ll, llll>::iterator &it)
{
    return (A + it->second.first) + (it->first - 1) * (B + it->second.second);
}

ll getVal(ll key)
{
    return getVal(M.find(key));
}

bool Expire(ll a, ll b)
{
    auto it = M.lower_bound(a);
    if (it == M.end() || it->first != a) return true;
    auto it2 = it;
    it2++;
    if (it2 == M.end() || it2->first != b) return true;
    ll val = getVal(it);
    bool one = false;
    while (it2 != M.end()) {
         ll val2 = getVal(it2);
         if (val <= val2) { one = true; M.erase(it2++); }
         else {
            ld in = ld(val - val2) / (it2->first - it->first) + ld(B);
            Q.push(ldllll(-in, llll(it->first, it2->first)));
            break;
         }
    }
    return one;
}

int main()
{
    scanf("%I64d %d", &n, &m);
    M.insert(make_pair(1, llll(-A, -B)));
    while (m--) {
        int typ, a, b; scanf("%d %d", &typ, &a);
        if (typ == 1) {
            M.clear();
            while (!Q.empty()) Q.pop();
            n += a;
            M.insert(make_pair(1, llll(-A, -B)));
        } else if (typ == 2) {
            ll old = M.rbegin()->first;
            ll nw = n + 1; n += a;
            M.insert(make_pair(nw, llll(-A, -B)));
            ll oldval = getVal(old), nwval = getVal(nw);
            if (oldval <= nwval) M.erase(nw);
            else {
                ld in = ld(oldval - nwval) / (nw - old) + ld(B);
                Q.push(ldllll(-in, llll(old, nw)));
            }
        } else {
            scanf("%d", &b);
            A += a; B += b;
            while (!Q.empty()) {
                llll p = Q.top().second;
                if (Expire(p.first, p.second)) Q.pop();
                else break;
            }
        }
        auto it = M.end(); it--;
        printf("%I64d %I64d\n", it->first, getVal(it));
    }
    return 0;
}