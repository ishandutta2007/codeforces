#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, max_c = 27, inf = 1000111222;

char buf[max_n];

string read_str() {
    scanf("%s", buf);
    return buf;
}

int n, k;
int cnt[max_n][max_c];
int pr[max_c];
string s;
int need;
int lft;

bool check(int pos, int val) {
    for (int i = 0;i < max_c; ++i) {
        pr[i] = cnt[pos][i];
    }
    pr[s[pos] - 'a']--;
    pr[val]++;
    lft = (n - pos - 1);
    need = 0;
    for (int i = 0; i < max_c; ++i) {
        if (pr[i] % k == 0) continue;
        need += (k - (pr[i] % k));
    }
    return need <= lft;
}

string build(int pos, int val) {
    string res;
    for (int i = 0; i < pos; ++i) {
        res += s[i];
    }
    res += ('a' + val);
    string res2;
    for (int i = 0; i < max_c; ++i) {
        if (pr[i] % k == 0) continue;
        int need = (k - (pr[i] % k));
        for (int j = 0; j < need; ++j) {
            res2 += ('a' + i);
        }
    }
    while(res.size() + res2.size() < n) {
        res += 'a';
    }
    res += res2;
    return res;
}

string solve() {
    scanf("%d%d", &n, &k);
    s = read_str();
    if (n % k) {
        return string("-1");
    }
    for (int i = 0; i < max_c; ++i) {
        cnt[0][i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        if (i) {
            for (int j = 0; j < max_c; ++j) {
                cnt[i][j] = cnt[i - 1][j];
            }
        }
        cnt[i][s[i] - 'a']++;
    }
    bool ok = true;
    for (int i = 0; i < max_c; ++i) {
        if (cnt[n - 1][i] % k) {
            ok = false;
        }
    }
    if (ok) {
        return s;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (char c = s[i] + 1; c <= 'z'; ++c) {
            int j = c - 'a';
            if (check(i, j)) {
                return build(i, j);
            }
        }
    }
    return string("-1");
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while(T--) {
        printf("%s\n", solve().c_str());
    }
    return 0;
}