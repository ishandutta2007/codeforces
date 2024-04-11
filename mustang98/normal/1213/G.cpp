#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

int pr[max_n];
int sz[max_n];
ll res = 0;

vector<pair<int, pair<int, int>>> ed;
int n, q;

ll ans[max_n];
vector<pair<int, int>> qr;

int get_pr(int a) {
    return pr[a] == a ? a : pr[a] = get_pr(pr[a]);
}

ll sum(ll a) {
    return a * (a - 1) / 2;
}

void un(int a, int b) {
    a = get_pr(a);
    b = get_pr(b);
    if (sz[a] > sz[b]) {
        swap(a, b);
    }
    res -= sum(sz[a]);
    res -= sum(sz[b]);
    pr[a] = b;
    sz[b] += sz[a];
    res += sum(sz[b]);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    for (int i = 0; i < max_n; ++i) {
        sz[i] = 1;
        pr[i] = i;
    }
    cin >> n >>q;
    for (int i = 0; i + 1 < n; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        --a, --b;
        ed.PB(MP(c, MP(a, b)));
    }
    sort(ed.begin(), ed.end());
    for (int i = 0; i < q; ++i) {
        int a;
        scanf("%d", &a);
        qr.emplace_back(a, i);
    }
    sort(qr.begin(), qr.end());
    reverse(ed.begin(), ed.end());
    for (int i = 0; i < qr.size(); ++i) {
        int mx = qr[i].F, ind = qr[i].S;
        while(!ed.empty() && ed.back().F <= mx) {
            int a = ed.back().S.F, b = ed.back().S.S;
            ed.pop_back();
            un(a, b);
        }
        ans[ind] = res;
    }
    for (int i =0 ; i < q; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}