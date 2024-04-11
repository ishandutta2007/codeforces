#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N = 3000;

string F[N];
string S[N];
string ans[N];
set<string> was;

int main() {
#if FALSE
    freopen("input", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        string s1 = a.substr(0, 3);
        string s2 = a.substr(0, 2) + b[0];
        F[i] = s1;
        S[i] = s2;
    }
    map<string, vector<pair<string, int>>> q;
    for (int i = 0; i < n; i++)
        q[F[i]].push_back(make_pair(S[i], i));
    for (const auto& kv : q) {
        if (kv.second.size() == 1)
            continue;
        for (const auto& p : kv.second) {
            if (was.count(p.first)) {
                cout << "NO" << endl;
                return 0;
            }
            was.insert(p.first);
            ans[p.second] = p.first;
        }
    }
    vector<int> ones;
    for (const auto& kv : q) 
        if (kv.second.size() == 1)
            ones.push_back(kv.second.back().second);
    for (;;) {
        int v = -1;
        for (int x : ones) {
            if (ans[x] != "" || !was.count(F[x])) {
                continue;
            }
            v = x;
            break;
        }
        if (v == -1)
            break;
        if (was.count(S[v])) {
            cout << "NO" << endl;
            return 0;
        }
        was.insert(S[v]);
        ans[v] = S[v];
    }
    for (int x : ones)
        if (ans[x] == "")
            ans[x] = F[x];
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << ans[i] << "\n";
}