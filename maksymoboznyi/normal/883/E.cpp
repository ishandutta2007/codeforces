#include<bits/stdc++.h>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pb push_back
#define rall(x) x.rbegin(), x.rend()
#define lg2(x) __lg(x)
#define rem_dupl(x) sort(all(x)); x.erase(unique(all(x)), x.end())
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> ii;
#define x first
#define y second

//mt19937 rand32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rand64(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2000;

int n, m, used[N];
string s;
vector<string> t;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        if (s[i] != '*')
            used[s[i]] = 1;
    cin >> m;
    for (int j = 1; j <= m; j++) {
        string q;
        cin >> q;
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] != '*' && s[i] != q[i])
                ok = 0;
            if (s[i] == '*' && used[q[i]])
                ok = 0;
        }
        if (ok)
            t.pb(q);
    }
    int ans = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        int good = 0;
        for (auto &q : t) {
            bool ok = 0;
            for (int i = 0; i < n; i++)
                if (s[i] == '*' && q[i] == c)
                    ok = 1;
            if (ok)
                good++;
        }
        if (good == t.size())
            ans++;
    }
    cout << ans;
    return 0;
}