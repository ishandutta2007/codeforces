#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;
const ll Inf = 1000000000000000000ll;
const int lim = 1000000000;

int n, s;
int L, R;
int X[Maxn];
set <ii> S;
ll sumS;
bool tk[Maxn];
vector <int> ans;

void Clear()
{
    S.clear();
    sumS = 0;
}

void Limit(int lim)
{
    while (S.size() > lim) {
        auto it = S.end(); it--;
        sumS -= it->first; S.erase(it);
    }
}

void Add(const ii &p)
{
    S.insert(p);
    sumS += p.first;
}

void Rem(const ii &p)
{
    auto it = S.find(p);
    if (it == S.end()) return;
    sumS -= it->first;
    S.erase(it);
}

void flipInput()
{
    s = n + 1 - s;
    swap(L, R);
    for (int i = 1; i <= n; i++)
        X[i] = lim - X[i];
    reverse(X + 1, X + n + 1);
}

ll toRight()
{
    ll res = X[s] - X[1] + X[n] - X[1];
    int nL = s - 1;
    int nR = n - s;
    while (R > nR) return res;
    int nd = L - nL;
    Clear();
    for (int i = s + 2; i <= n; i++)
        Add(ii(X[i] - X[i - 1], i));
    Limit(nd);
    ll add = 2ll * sumS;
    ll cur = 0;
    for (int i = n, t = 1; i >= s + 2 && t <= nd; i--, t++) {
        cur += X[i] - X[i - 1];
        Rem(ii(X[i] - X[i - 1], i));
        Limit(nd - t);
        add = min(add, 2ll * sumS + cur);
    }
    return res + add;
}

void Mark(int i)
{
    for (auto it: S)
        tk[it.second - 1] = true;
    for (int j = i; j <= n; j++)
        tk[j - 1] = true;
}

vector <int> printRight(ll got)
{
    vector <int> ans;
    ll res = X[s] - X[1] + X[n] - X[1];
    int nL = s - 1;
    int nR = n - s;
    while (R > nR) {
        for (int i = L; i >= 1; i--)
            ans.push_back(i);
        for (int i = L + 1; i <= n; i++) if (i != s)
            ans.push_back(i);
        return ans;
    }
    int nd = L - nL;
    Clear();
    for (int i = s + 2; i <= n; i++)
        Add(ii(X[i] - X[i - 1], i));
    Limit(nd);
    if (2ll * sumS + res == got) Mark(n + 1);
    else {
        ll cur = 0;
        for (int i = n, t = 1; i >= s + 2 && t <= nd; i--, t++) {
            cur += X[i] - X[i - 1];
            Rem(ii(X[i] - X[i - 1], i));
            Limit(nd - t);
            if (2ll * sumS + cur + res == got) {
                Mark(i);
                break;
            }
        }
    }
    for (int i = s - 1; i >= 1; i--)
        ans.push_back(i);
    int nxt = s + 1;
    for (int i = s + 1; i <= n; i++) if (!tk[i]) {
        for (int j = i; j >= nxt; j--)
            ans.push_back(j);
        nxt = i + 1;
    }
    return ans;
}

void flipOutput(vector <int> &res)
{
    for (int i = 0; i < res.size(); i++)
        res[i] = n + 1 - res[i];
}

int main()
{
    scanf("%d %d %d", &n, &L, &s);
    R = n - 1 - L;
    if (L == 0 && s > 1 || R == 0 && s < n) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &X[i]);
    ll res1 = s < n? toRight(): Inf;
    flipInput();
    ll res2 = s < n? toRight(): Inf;
    if (res2 < res1) {
        ans = printRight(res2);
        flipOutput(ans);
    } else {
        flipInput();
        ans = printRight(res1);
    }
    printf("%d\n", min(res1, res2));
    for (int i = 0; i < ans.size(); i++)
        printf("%d%c", ans[i], i + 1 < ans.size()? ' ': '\n');
    return 0;
}