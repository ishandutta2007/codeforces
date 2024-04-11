/**
 *  created: 12/04/2021, 10:47:28
**/

#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 111, inf = 1000111222;

vector<int> v[max_n];
int p[max_n];
vector<int> path;
vector<int> ans;
int lft;

void dfs2(int cur) {
    ans.push_back(cur);
    --lft;
    for (int to : v[cur]) {
        if (lft) {
            dfs2(to);
            ans.push_back(cur);
        }
    }
}

void dfs(int cur) {
    ans.push_back(cur);
    path.pop_back();
    for (int to : v[cur]) {
        if (!path.empty() && path.back() == to) {
            continue;
        }
        if (lft) {
            dfs2(to);
            ans.push_back(cur);
        }
    }
    if (!path.empty()) {
        dfs(path.back());
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            v[i].clear();
        }
        p[0] = -1;
        for (int i = 1; i < n; ++i) {
            int pr;
            cin >> pr;
            --pr;
            p[i] = pr;
            v[pr].PB(i);
        }
        if (k == 1) {
            cout << 0 << "\n";
            cout << 1 << "\n";
            continue;
        }
        vector<int> best;
        for (int fin = 1; fin < n; ++fin) {
            path.clear();
            int cur = fin;
            while (cur != -1) {
                path.PB(cur);
                cur = p[cur];
            }
            //reverse(path.begin(), path.end());
            if (path.size() > k) {
                continue;
            }
            ans.clear();
            lft = k - path.size();
            dfs(0);
            if (lft == 0) {
                if (best.empty() || ans.size() < best.size()) {
                    best = ans;
                }
            }
        }
        cout << best.size() - 1 << endl;
        for (int a : best) {
            printf("%d ", a + 1);
        }
        puts("");
    }
    return 0;
}