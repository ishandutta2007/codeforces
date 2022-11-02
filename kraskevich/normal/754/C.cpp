#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX_LEN = 11;
const int N = 111;

bool can[N][N];
bool dp[N][N];
vector<string> name;

bool good(char c) {
    return !isalpha(c) && !isdigit(c);
}

unordered_set<string> getSub(const string& s) {
    unordered_set<string> res;
    for (int l = 0; l < s.length(); l++) 
        for (int len = 1; l + len <= s.length(); len++) {
            if (l != 0 && !good(s[l - 1]))
                continue;
            if (l + len != s.length() && !good(s[l + len]))
                continue; 
            res.insert(s.substr(l, len));
        }
    return res;
}

vector<string> split(const string& s) {
    string cur;
    int p = 0;
    while (s[p] != ':') {
        cur += s[p];
        p++;
    }
    vector<string> res;
    res.push_back(cur);
    p++;
    cur = "";
    while (p < s.length()) {
        cur += s[p];
        p++;
    }
    res.push_back(cur);
    return res;
}

void solve() {
    int n, m;
    cin >> n;
    map<string, int> id;
    name.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> name[i];
        id[name[i]] = i;
    }
    cin >> m;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = false;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            can[i][j] = false;
    vector<vector<string>> txt(m);
    string s;
    getline(cin, s);
    for (int i = 0; i < m; i++) {
        getline(cin, s); 
        txt[i] = split(s);
    }
    for (int i = 0; i < m; i++) {
        if (txt[i][0] != "?") {
            can[i][id[txt[i][0]]] = true;
            continue;
        }  
        auto q = getSub(txt[i][1]); 
        for (int j = 0; j < n; j++)
            if (!q.count(name[j]))
                can[i][j] = true;       
    }
    for (int i = 0; i < n; i++)
        if (can[0][i])
            dp[0][i] = true;
    for (int pos = 1; pos < m; pos++)
        for (int old = 0; old < n; old++)
            for (int cur = 0; cur < n; cur++)
                if (cur != old && dp[pos - 1][old] && can[pos][cur])
                    dp[pos][cur] = true;
    int v = -1;
    for (int i = 0; i < n; i++)
        if (dp[m - 1][i])
            v = i;
    if (v == -1) {
        cout << "Impossible" << endl;
        return;
    }
    txt[m - 1][0] = name[v];
    for (int pos = m - 1; pos > 0; pos--) {
        for (int cur = 0; cur < n; cur++)
            if (dp[pos - 1][cur] && cur != v) {
                v = cur;
                break;
        }
        txt[pos - 1][0] = name[v];
    }    
    for (int i = 0; i < m; i++)
        cout << txt[i][0] << ":" << txt[i][1] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); 
    int t;
    cin >> t;
    while (t--) 
        solve();
}