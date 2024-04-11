#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;
int cnt[150];
int n;
string sss;

bool can(char c1, char c2) {
    if (c1 != c2) {
        if (cnt[c1] == 0 || cnt[c2] == 0) {
            return false;
        }
        return true;
    }
    char c = c1;
    if (cnt[c] < 2) {
        return false;
    }
    int need = cnt[c] - 2;
    int have = n - cnt[c];
    return have >= need;
}

string solve() {
    sort(sss.begin(), sss.end());
    if (sss[0] == sss.back()) {
        return sss;
    }
    for (char c :  sss) {
        cnt[c]++;
    }
    int diff = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (cnt[c]) {
            ++diff;
        }
    }
    char fst = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (cnt[c] == 1) {
            fst = c;
            --cnt[c];
            break;
        }
    }
    if (fst != 0) {
        string ans = "";
        ans += fst;
        for (char c = 'a'; c <= 'z'; ++c) {
            while(cnt[c]) {
                ans += c;
                --cnt[c];
            }
        }
        return ans;
    }
    string ans;
    bool fnd = false;
    for (char c1 = 'a'; c1 <= 'z'; ++c1) {
        for (char c2 = 'a'; c2 <= 'z'; ++c2) {
            if (can(c1, c2)) {
                ans += c1;
                ans += c2;
                --cnt[c1];
                --cnt[c2];
                break;
            }
        }
        if (!ans.empty()) {
            break;
        }
    }
    char c1 = ans[0], c2 = ans[1];
    if (c1 == c2) {
        vector<char> other;
        int cnta = cnt[c1];
        cnt[c1] = 0;
        for (char c  = 'a'; c <= 'z'; ++c) {
            for (int i = 0; i < cnt[c]; ++i) {
                other.PB(c);
            }
        }
        reverse(other.begin(), other.end());
        for (int i = 2; i < n; ++i) {
            if (ans.back() == c1 || cnta == 0) {
                ans += other.back();
                other.pop_back();
            } else {
                ans += c1;
                --cnta;
            }
        }
        return ans;
    }
    int ca = cnt[c1], cb = cnt[c2];
    cnt[c1] = 0;
    cnt[c2] = 0;
    if (diff == 2) {
        for (int i = 0; i < cb; ++i) {
            ans += c2;
        }
        for (int i = 0; i < ca; ++i) {
            ans += c1;
        }
        return ans;
    }
    for (int i = 0; i < ca; ++i) {
        ans += c1;
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        if (cnt[c]) {
            ans += c;
            --cnt[c];
            break;
        }
    }
    for (int i = 0; i < cb; ++i) {
        ans += c2;
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        while(cnt[c]) {
            ans += c;
            --cnt[c];
        }
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        memset(cnt, 0, sizeof(cnt));
        cin >> sss;

        n = sss.size();
        cout << solve() << "\n";
    }

    return 0;
}