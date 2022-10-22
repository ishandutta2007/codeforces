#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair <ld, ld> ldld;
typedef pair <int, int> ii;

const int Maxn = 115;
const ld eps = 1e-14l;

map <ld, ii> M;

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

vector <ldld> Construct(ld param, bool inv)
{
    vector <ldld> res;
    res.push_back(ldld(0, -1));
    for (int i = 0; i < Maxn; i += 2) {
        res.push_back(ldld(i, Maxn));
        res.push_back(ldld(i + 1 + param, Maxn));
        res.push_back(ldld(i + 1 + param, 0));
        res.push_back(ldld(i + 2, 0));
    }
    if (inv)
        for (int i = 0; i < res.size(); i++)
            swap(res[i].first, res[i].second);
    return res;
}

ld Ask(const vector <ldld> &V)
{
    printf("? %d\n", int(V.size()));
    for (int i = 0; i < V.size(); i++)
        cout << fixed << setprecision(15) << V[i].first << " " << fixed << setprecision(15) << V[i].second << "\n";
    fflush(stdout);
    ld res; cin >> res;
    return res;
}

ld Solve(bool inv)
{
    ld val = Ask(Construct(0, inv));
    ld mn = min(1.0l - val, val);
    ld val2 = Ask(Construct(mn, inv));
    if (val2 > val + eps) return -val;
    return -(1 - val);
}

void nextPrime(int &cur)
{
    cur++;
    while (!Prime(cur)) cur++;
}

int main()
{
    int n, m; cin >> n >> m;
    ld stx = Solve(false);
    ld sty = Solve(true);
    vector <ldld> tmp;
    tmp.push_back(ldld(stx + 0, sty - 1));
    int cur = 3 * Maxn;
    for (int i = 0; i < Maxn; i++) {
        nextPrime(cur);
        tmp.push_back(ldld(stx + i, sty));
        tmp.push_back(ldld(stx + i + 1, sty + cur));
        for (int j = 0; j < cur && j < Maxn; j++) {
            ld val = (cur - j + cur - j - 1) / 2.0l / ld(cur);
            M.insert(make_pair(val, ii(i, j)));
        }
        tmp.push_back(ldld(stx + i + 1, sty));
    }
    ld nd = Ask(tmp);
    auto it = M.lower_bound(nd);
    ii res;
    if (it != M.begin()) {
        auto prv = it; prv--;
        if (it != M.end())
            res = it->first - nd < nd - prv->first? it->second: prv->second;
        else res = prv->second;
    } else res = it->second;
    cout << "! " << fixed << setprecision(15) << res.first + stx << " " << fixed << setprecision(15) << res.second + sty << endl;
    fflush(stdout);
    return 0;
}