#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ll> ill;
typedef pair <ii, ll> iill;

const int Maxn = 1000006;
const ll Inf = 2000000000000000000ll;

int n;
iill srt[Maxn];
deque <ill> L;
deque <ll> Y;
ll res;

ll Eval(const ill &lin, ll y)
{
    return y * lin.first + lin.second;
}

ll getY(const ill &lin1, const ill &lin2)
{
    return (lin1.second - lin2.second) / (lin2.first - lin1.first);
}

void addLine(const ill &lin)
{
    if (!L.empty() && Eval(L.back(), 0) >= Eval(lin, 0)) return;
    while (L.size() >= 2) {
        ll myY = getY(lin, L.back());
        if (myY >= Y.back()) {
            L.pop_back();
            Y.pop_back();
        } else break;
    }
    if (L.empty()) Y.push_back(Inf);
    else Y.push_back(getY(lin, L.back()));
    L.push_back(lin);
}

ll Get(ll y)
{
    while (Y.size() >= 2 && y <= Y[1]) {
        L.pop_front();
        Y.pop_front();
    }
    return Eval(L[0], y);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d %I64d", &srt[i].first.first, &srt[i].first.second, &srt[i].second);
    sort(srt, srt + n);
    addLine(ill(0, 0));
    for (int i = 0; i < n; i++) {
        ll cand = Get(srt[i].first.second) +
                  ll(srt[i].first.first) * ll(srt[i].first.second) - srt[i].second;
        res = max(res, cand);
        addLine(ill(-srt[i].first.first, cand));
    }
    cout << res << endl;
    return 0;
}