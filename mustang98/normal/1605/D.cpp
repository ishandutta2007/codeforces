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

vector<int> v[max_n];
vector<int> a[2];

void dfs(int cur, int pr, int d) {
    a[d % 2].push_back(cur);
    for (int to : v[cur]) {
        if (to == pr) continue;
        dfs(to, cur, d + 1);
    }
}

int ans[max_n];
bool took[max_n];

int main()
{
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n + 2; ++i) {
            v[i].clear();
            took[i] = 0;
            ans[i] = 0;
        }
        a[0].clear();
        a[1].clear();

        for (int i = 0; i + 1 < n; ++i) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            v[a].PB(b);
            v[b].PB(a);
        }

        dfs(0, -1, 0);
        if (a[0].size() > a[1].size()) {
            a[0].swap(a[1]);
        }
        //cout << "% " << a[0].size() << ' ' << a[1].size() << endl;
        vector<pair<int, int>> pw;
        int c = a[0].size();
        int nn = n;
        int k = 0;
        for (int i = 1; nn; i *= 2) {
            pw.push_back(make_pair(k, min(i, nn)));
            nn -= min(i, nn);
            ++k;
        }
        for (pair<int, int> x : pw) {
            //cout << x.F << ' ' << x.S << endl;

        }
        //cout << endl;
        vector<int> use;
        for (int i = int(pw.size()) - 1; i >= 0; --i) {
            if (pw[i].S <= c) {
                //cout << "take " << pw[i].S << endl;
                c-= pw[i].S;
                int cur = (1 << pw[i].F);
                for (int j = cur; j < min(cur * 2, n + 1); ++j) {
                    if (a[0].empty()) exit(228);
                    ans[a[0].back()] = j;
                    took[j] = 1;
                    a[0].pop_back();
                }
            }
        }
        //cout << a[1].size() << endl;
        for (int i = 1; i <= n; ++i) {
            if (!took[i]) {
                if (a[1].empty()) exit(229);
                ans[a[1].back()] = i;
                a[1].pop_back();
            }
        }
        for (int i =0; i < n; ++i) {
            cout << ans[i] << ' ';
        }
        cout << "\n";
    }

    return 0;
}