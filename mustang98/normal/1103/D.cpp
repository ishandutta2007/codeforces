#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111, max_pr = 11, inf = 1000111222;

ll a[max_n];
ll e[max_n];
ll n, k;
vector<pair<ll, ll>> allr;
vector<pair<ll, vector<char>>> r;
vector<int> cover[1 << max_pr];
ll pw[max_pr][60];
int cprime;

ll get_pmask(ll val, const vector<ll>& m) {
    ll pmask = 0;
    int sum = 0;
    for (ll pr : m) {
        while(val % pr == 0) {
            val /= pr;
            ++sum;
        }
        pmask |= (1LL << sum);
    }
    return pmask;
}

void prmask(int);

vector<char> mask_to_p(ll mask) {
    vector<char> p;
    int lst = 0;
    for (int i = 0; i < 60; ++i) {
        if (mask & (1LL << i)) {
            p.PB(i - lst);
            lst = i;
        }
    }
    return p;
}

int l[max_pr * max_pr];
int pr[max_pr];
vector<int> v[max_pr * max_pr];
bool vis[max_pr * max_pr];

bool try_kuhn(int cur) {
    if (vis[cur]) return 0;
    vis[cur] = 1;
    for (int to : v[cur]) {
        if (pr[to] == -1 || try_kuhn(pr[to])) {
            pr[to] = cur;
            return 1;
        }
    }
    return 0;
}

ll ANS = -1;

void process(vector<int> msk) {
    while(msk.back() == 0) {
        msk.pop_back();
    }
    int cl = 0;
    for (int m : msk) {
        for (int to : cover[m]) {
            l[cl++] = to;
        }
    }
    sort(l, l + cl);
    cl = unique(l, l + cl) - l;
    for (int i = 0; i < msk.size(); ++i) {
        pr[i] = -1;
    }
    for (int i = 0; i < cl; ++i) {
        v[i].clear();
    }
    for (int i = 0; i < msk.size(); ++i) {
        for (int to : cover[msk[i]]) {
            v[lower_bound(l, l + cl, to) - l].PB(i);
        }
    }
    memset(vis, 0, cl);
    ll sum = 0;
    for (int i = 0; i < cl; ++i) {
        if (try_kuhn(i)) {
            memset(vis, 0, cl);
            sum += r[l[i]].F;
        }
    }
    int taken = 0;
    for (int i = 0; i < msk.size(); ++i) {
        if (pr[i] != -1) {
            taken++;
        }
    }
    sum *= msk.size();
    if (taken == msk.size()) {
        if (ANS == -1) {
            ANS = sum;
        } else {
            ANS = min(ANS, sum);
        }
    }
}

void gener_sets(vector<int>& msk, int st) {
    if (st == cprime) {
        process(msk);
        return;
    }
    for (int i = 0; i < cprime; ++i) {
        msk[i] ^= (1 << st);
        gener_sets(msk, st + 1);
        msk[i] ^= (1 << st);
        if (msk[i] == 0) break;
    }
}

void prmask(int mask) {
    string ms;
    while(mask) {
        ms += ('0' + mask % 2);
        mask /= 2;
    }
    reverse(ms.begin(), ms.end());
    cout << ms << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", a + i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", e + i);
    }
    ll gc = a[0];
    for (int i = 1; i < n; ++i) {
        gc = __gcd(gc, a[i]);
    }
    if (gc == 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<ll> m;
    vector<char> p;
    for (ll i = 2; i * i <= gc; ++i) {
        int c = 0;
        while (gc % i == 0) {
            gc /= i;
            c++;
        }
        if (c) {
            m.PB(i);
            p.PB(c);
        }
    }
    if (gc != 1) {
        m.PB(gc);
        p.PB(1);
    }
    for (int i = 0; i < n; ++i) {
        allr.emplace_back(get_pmask(a[i], m), e[i]);
    }
    sort(allr.begin(), allr.end());
    cprime = m.size();
    int num;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || allr[i].F != allr[i - 1].F) {
            num = 0;
        } else {
            num++;
        }
        if (num < cprime) {
            r.emplace_back(allr[i].S, mask_to_p(allr[i].F));
        }
    }
    sort(r.begin(), r.end());
    for (int i = 0; i < cprime; ++i) {
        ll pr = m[i];
        pw[i][0] = 1;
        for (int j = 1; j < 60; ++j) {
            pw[i][j] = pw[i][j - 1] * pr;
        }
    }
    for (int mask = 1; mask < (1 << cprime); ++mask) {
        for (int i = 0; i < r.size(); ++i) {
            ll value = 1;
            for (int j = 0; j < cprime; ++j) {
                if (mask & (1 << j)) {
                    value *= pw[j][r[i].S[j]];
                }
            }
            if (value <= k) {
                cover[mask].push_back(i);
                if (cover[mask].size() == cprime) {
                    break;
                }
            }
        }
    }
    /////////////////////
    vector<int> msk(cprime, 0);
    gener_sets(msk, 0);
    cout << ANS << endl;
    return 0;
}

// think 2:09