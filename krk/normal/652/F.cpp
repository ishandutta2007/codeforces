#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 300005;

int n, m;
ll t;
int my[Maxn];
vector <ii> A, B;
vector <ii> bef;
vector <int> aft;
int asiz, bsiz;
int bst;

void Print()
{
    for (int i = 0; i < n; i++)
        printf("%d%c", my[i] + 1, i + 1 < n? ' ': '\n');
}

bool Mor(ll ind)
{
    ll aind = (ind + 1) / 2;
    ll bind = ind / 2;
    ll lft = 2 * t;
    if (aind / asiz > lft / m) return true;
    lft -= aind / ll(asiz) * ll(m);
    aind %= asiz;
    if (aind) {
        lft -= (A[0].first + m - A[asiz - aind].first);
        if (lft < 0) return true;
    }
    if (bind / bsiz > lft / m) return true;
    lft -= bind / ll(bsiz) * m;
    bind %= bsiz;
    int add = B[(bst + bind) % bsiz].first - B[bst].first;
    if (add < 0) add += m;
    lft -= add;
    if (lft < 0) return true;
    add = B[bst].first - A[0].first;
    if (add < 0) add += m;
    return add > lft;
}

ii Solve()
{
    asiz = A.size();
    bsiz = B.size();
    bst = lower_bound(B.begin(), B.end(), ii(A[0].first, 0)) - B.begin();
    if (bst == B.size()) bst = 0;
    ll lef = 0, rig = 2 * t + 2;
    while (lef <= rig) {
        ll mid = lef + rig >> 1ll;
        if (Mor(mid)) rig = mid - 1ll;
        else lef = mid + 1ll;
    }
    rig++;
    if (rig % 2 == 0) {
        ll aind = (rig + 1) / 2;
        aind %= asiz;
        if (aind == 0) aind = asiz;
        return ii(my[A[asiz - aind].second], 1);
    } else {
        ll bind = rig / 2;
        bind %= bsiz;
        return ii(my[B[(bst + bind) % bsiz].second], 0);
    }
}

int main()
{
    scanf("%d %d %I64d", &n, &m, &t);
    for (int i = 0; i < n; i++) {
        int s;
        char ch;
        scanf("%d %c", &s, &ch);
        s--;
        bef.push_back(ii(s, i));
        if (ch == 'R') {
            A.push_back(ii(s, i));
            my[i] = (ll(s) + t) % m;
        } else {
            B.push_back(ii(s, i));
            my[i] = (ll(s) - t % m + m) % m;
        }
        aft.push_back(my[i]);
    }
    if (A.empty() || B.empty()) {
        Print();
        return 0;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(bef.begin(), bef.end());
    sort(aft.begin(), aft.end());
    ii pos = Solve();
    int ind = 0;
    while (bef[ind].second != A[0].second) ind++;
    int ind2;
    if (pos.second) ind2 = upper_bound(aft.begin(), aft.end(), pos.first) - aft.begin() - 1;
    else ind2 = lower_bound(aft.begin(), aft.end(), pos.first) - aft.begin();
    for (int i = 0; i < n; i++)
        my[bef[(ind + i) % n].second] = aft[(ind2 + i) % n];
    Print();
    return 0;
}