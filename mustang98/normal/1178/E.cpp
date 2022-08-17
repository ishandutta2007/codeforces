#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111, inf = 1000111222;

char ccc[max_n];
string read_str() {
    scanf("%s", ccc);
    return string(ccc);
}

vector<string> pat = {"a", "b", "c", "ab", "ba", "ac", "ca", "bc", "cb"};//, "abc", "acb", "bac", "bca", "cab", "cba"};

string gett(const string& s, string p) {
    int i = 0;
    string res = "";
    for (char c : s) {
        if (c == p[i]) {
            res += c;
            i = (i + 1) % p.size();
        }
    }
    if (res.size() > 0 && res[0] != res.back()) {
        res.pop_back();
    }
    return res;
}

int nxtl[max_n][3];
int nxtr[max_n][3];

string get2(const string& s, int from) {
    nxtl[0][0] = nxtl[0][1] = nxtl[0][2] = -1;
    int n = s.size();
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            nxtl[i][j] = nxtl[i - 1][j];
            if (s[i - 1] == 'a' + j) {
                nxtl[i][j] = i - 1;
            }
        }
    }
    nxtr[n - 1][0] = nxtr[n - 1][1] = nxtr[n - 1][2] = inf;
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < 3; ++j) {
            nxtr[i][j] = nxtr[i + 1][j];
            if (s[i + 1] == 'a' + j) {
                nxtr[i][j] = i + 1;
            }
        }
    }
    string ans = "";
    int cur = from;
    int l = cur, r = cur;
    while (true) {
        int mxleft = -5, best = -1;
        for (int i = 0; i < 3; ++i) {
            if (nxtl[l][i] == -1 || nxtr[r][i] == inf) continue;
            int mxcur = min(nxtl[l][i], n - 1 - nxtr[r][i]);
            if (mxcur > mxleft) {
                mxleft = mxcur;
                best = i;
            }
        }
        if (best == -1) break;
        ans += ('a' + best);
        l = nxtl[l][best];
        r = nxtr[r][best];
    }
    string res = ans;
    reverse(ans.begin(), ans.end());
    return ans + s[cur] + res;
}


mt19937 gen(43247);

string solve(const string& s) {
    int need = s.size() / 2;
    int mx = -1;
    for (string p : pat) {
        string res = gett(s, p);
        mx = max(mx, int(res.size()));
        if (res.size() >= need) {
            return res;
        }
    }
    for (int cent = max(int(s.size()) / 2 - 5, 0); cent <= min(int(s.size()) / 2 + 5, (int)s.size() - 1); ++cent) {
        string res = get2(s, cent);
        mx = max(mx, int(res.size()));
        if (res.size() >= need) {
            return res;
        }
    }
    for (int i = 0; i < 100; ++i) {
        int cent = gen() % s.size();
        string res = get2(s, cent);
        mx = max(mx, int(res.size()));
        if (res.size() >= need) {
            return res;
        }
    }
    exit(228);
}

string gens(int n) {
    string s;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            s +=  "abc"[rand() % 3];
        } else {
            if (s[i - 1] == 'a') s += "bc"[rand() % 2];
            if (s[i - 1] == 'b') s += "ac"[rand() % 2];
            if (s[i - 1] == 'c') s += "ab"[rand() % 2];
        }
    }
    return s;
}

void stress() {
    int cnt = 0;
    while(true) {
        ++cnt;
        if (cnt % 1 == 0) {
            cout << cnt << endl;
        }
        int n = 1000000;//500 + rand() % 10;
        solve(gens(n));
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //stress();
    string s = read_str();
    cout << solve(s) << endl;
    return 0;
}