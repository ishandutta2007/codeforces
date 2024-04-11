#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const int Maxn = 1000005;

int m, n;
llll my[Maxn];
ll BITS[Maxn], BITC[Maxn];
int nil = 500002;
ll res;
int ans[Maxn];
vector <int> seq;

void Insert(int x, ll sum, ll len)
{
    for (int i = x; i < Maxn; i += i & -i) {
        BITS[i] += sum;
        BITC[i] += len;
    }
}

llll Get(int x)
{
    llll sumlen = llll(0ll, 0ll);
    for (int i = x; i > 0; i -= i & -i) {
        sumlen.first += BITS[i];
        sumlen.second += BITC[i];
    }
    return sumlen;
}

ll Solve()
{
    llll all = Get(Maxn - 1);
    llll my = Get(nil);
    return (all.first - my.first - (all.second - my.second) * ll(nil)) +
           (my.second * ll(nil) - my.first);
}

int main()
{
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        my[i] = llll(a, i + 1);
    }
    for (int i = 0; i < n; i++) {
        int b; scanf("%d", &b);
        my[n + i] = llll(b, -(i + 1));
    }
    sort(my, my + 2 * n);
    for (int i = 0; i < 2 * n; i++)
        my[2 * n + i] = llll(my[i].first + m, my[i].second);
    my[4 * n] = llll(my[0].first + 2ll * ll(m), my[0].second);
    for (int i = 0; i < 2 * n; i++) {
        nil += my[i].second > 0? 1: -1;
        ll len = my[i + 1].first - my[i].first;
        Insert(nil, ll(nil) * len, len);
    }
    res = Solve();
    int bst = 0;
    for (int i = 0; i < 2 * n; i++) {
        nil += my[i].second > 0? 1: -1;
        ll cand = Solve();
        if (cand < res) { res = cand; bst = i + 1; }
    }
    cout << res << endl;
    for (int i = bst; i < bst + 2 * n; i++) {
        if (seq.empty()) seq.push_back(int(my[i].second));
        else if (seq.back() < 0 && my[i].second > 0) {
            ans[int(my[i].second)] = -seq.back();
            seq.pop_back();
        } else if (seq.back() > 0 && my[i].second < 0) {
            ans[seq.back()] = -int(my[i].second);
            seq.pop_back();
        } else seq.push_back(int(my[i].second));
    }
    for (int i = 1; i <= n; i++)
        printf("%d%c", ans[i], i + 1 <= n? ' ': '\n');
    return 0;
}