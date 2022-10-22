#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;
typedef pair <int, int> ii;
typedef pair <ll, ii> llii;

int n, k, m;
map <int, priority_queue <lli> > M;
priority_queue <llii> Q;

void addCar(int x, ll tim, int ind)
{
    auto it = M.find(x);
    if (it == M.end()) {
        priority_queue <lli> tmp;
        tmp.push(lli(-tim, -ind));
        M.insert(make_pair(x, tmp));
    } else it->second.push(lli(-tim, -ind));
}

void remCar(map <int, priority_queue <lli> >::iterator &it)
{
    it->second.pop();
    if (it->second.empty())
        M.erase(it);
}

lli getClose(int x, ll tim)
{
    auto it2 = M.lower_bound(x);
    auto it = it2;
    if (it != M.begin()) {
        it--;
        if (it2 != M.end())
            if (x - it->first < it2->first - x ||
                x - it->first == it2->first - x && it->second.top() > it2->second.top()) {
                lli res = lli(tim + x - it->first, -it->second.top().second);
                remCar(it);
                return res;
            } else {
                lli res = lli(tim + it2->first - x, -it2->second.top().second);
                remCar(it2);
                return res;
            }
        else {
            lli res = lli(tim + x - it->first, -it->second.top().second);
            remCar(it);
            return res;
        }
    } else {
        lli res = lli(tim + it2->first - x, -it2->second.top().second);
        remCar(it2);
        return res;
    }
}

int main()
{
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 1; i <= k; i++) {
        int x; scanf("%d", &x);
        addCar(x, 0, i);
    }
    ll gt = 0;
    for (int i = 1; i <= m; i++) {
        ll t; int a, b; scanf("%I64d %d %d", &t, &a, &b);
        while (!Q.empty() && -Q.top().first <= t) {
            llii p = Q.top(); Q.pop();
            addCar(p.second.first, -p.first, p.second.second);
        }
        gt = max(gt, t);
        lli res;
        if (!M.empty()) res = getClose(a, gt);
        else {
            gt = -Q.top().first;
            while (!Q.empty() && -Q.top().first == gt) {
                llii p = Q.top(); Q.pop();
                addCar(p.second.first, -p.first, p.second.second);
            }
            res = getClose(a, gt);
        }
        printf("%d %I64d\n", res.second, res.first - t);
        res.first += abs(a - b);
        Q.push(llii(-res.first, ii(b, res.second)));
    }
    return 0;
}