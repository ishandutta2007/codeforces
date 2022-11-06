#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
using namespace std;

const int N = 1e5 + 5;

int n, b[N], mo[N], cnt[N], ans = 1;
vector<int> a[N];
vector<int> d[N];

int get_comprime(int x) {
    int res = 0;
    for (auto del: d[x])
        res += mo[del] * cnt[del];
    return res;
}

void del(int x) {
    for (auto del: d[x])
        cnt[del]--;
}

void add(int x) {
    for (auto del: d[x])
        cnt[del]++;
}

void go(int g) {
    sort(all(a[g]));
    a[g].resize(unique(all(a[g])) - a[g].begin());
    sort(rall(a[g]));
    if (a[g].size() == 0)
        return;
    ans = max(ans, a[g][0] * g);
    if (a[g].size() == 1)
        return;
    stack<int> q;
    for (auto x: a[g]) {
        int c = get_comprime(x);
        while (c) {
            while (__gcd(q.top(), x) != 1)
                del(q.top()), q.pop();
            ans = max(ans, x * q.top() * g);
            c--;
            del(q.top());
            q.pop();
        }
        add(x);
        q.push(x);
    }
    while (q.size() > 0)
        del(q.top()), q.pop();
}



signed main()
{
    for (int i = 1; i < N; i++) {
        for (int j = 1; j * j <= i; j++)
            if (i % j == 0) {
                d[i].pb(j);
                if (j * j != i)
                    d[i].pb(i / j);
            }
        if (d[i].size() > 2)
            swap(d[i][2], d[i][1]);
        if (i == 1)
            mo[i] = 1;
        else if ((i / d[i][1]) % d[i][1] == 0)
            mo[i] = 0;
        else
            mo[i] = -mo[i / d[i][1]];
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        for (auto del: d[b[i]])
            a[del].pb(b[i] / del);
    }
    for (int i = 1; i < N; i++)
        go(i);
    cout << ans;
    return 0;
}