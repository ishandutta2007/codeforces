#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 1e3 + 5;

int q, q1, n, k, lstans;
int used[N];
vector<int> s[N];

bool check(int x) {
    vector<int> qq;
    for (int i = 1; i <= x; i++)
        for (auto t: s[i])
            qq.pb(t);
    cout << "? " << qq.size() << ' ';
    for (auto y: qq)
        cout << y << ' ' ;
    cout << endl;
    int res;
    cin >> res;
    lstans = max(lstans, res);
    return (res == q);
}

signed main()
{/*
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        lstans = 0;
        for (int i = 1; i <= k; i++) {
            int x;
            s[i].clear();
            cin >> x;
            s[i].resize(x);
            for (int j = 0; j < x; j++)
                cin >> s[i][j];
        }
        cout << "? " << n << ' ';
        for (int i = 1; i <= n; i++)
            cout << i << ' ';
        cout << endl;
        cin >> q;

        int l = 0, r = k;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (check(m))
                r = m;
            else
                l = m;
        }
        vector<int> p;
        for (int i = 1; i <= n; i++)
            used[i] = 0;
        for (auto x: s[r])
            used[x] = 1;
        for (int i = 1; i <= n; i++)
            if (!used[i])
                p.pb(i);
        if (p.size() == 0)
            q1 = 0;
        else {
            cout << "? " << p.size() << ' ';
            for (auto x: p)
                cout << x << ' ';
            cout << endl;
            cin >> q1;
        }

        cout << "! ";
        for (int i = 1; i <= k; i++)
            if (i != r)
                cout << q << ' ';
            else
                cout << q1 << ' ';
        cout << endl;
        string ttt;
        cin >> ttt;
        if (ttt == "Incorrect")
            return 0;
    }
    return 0;
}