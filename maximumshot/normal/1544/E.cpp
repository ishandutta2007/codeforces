#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

vector<int> get_pi(string s) {
    int n = (int) s.size();
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

string slow(string s) {
    int n = (int) s.size();
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        p[i] = i;
    int best_value = inf;
    string best = s;
    do {
        string tmp = s;
        for (int i = 0; i < n; i++)
            tmp[p[i]] = s[i];
        vector<int> pi = get_pi(tmp);
        int tmp_value = *max_element(pi.begin(), pi.end());
        if (tmp_value < best_value || (tmp_value == best_value && tmp < best))
            best_value = tmp_value, best = tmp;
    } while (next_permutation(p.begin(), p.end()));
    return best;
}

string fast(string s) {
    int n = (int) s.size();
    vector<int> cnt(26);
    for (char c : s)
        cnt[c - 'a']++;
    {
        for (int c = 0; c < 26; c++) {
            if (cnt[c] == 1) {
                string res;
                res.push_back(c + 'a');
                cnt[c]--;
                for (int i = 0; i < 26; i++)
                    for (int j = 0; j < cnt[i]; j++)
                        res.push_back(i + 'a');
                return res;
            }
        }
    }
    string A = s;
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    if ((int) A.size() == 1)
        return s;
    for (char y : A) {
        if (y == A.front() && cnt[A.front() - 'a'] == 1)
            continue;
        string res;
        res.push_back(A.front());
        res.push_back(y);
        vector<int> hlp = cnt;
        hlp[res[0] - 'a']--;
        hlp[res[1] - 'a']--;
        for (int i = 2; i < n; i++) {
            for (char c : A) {
                if (hlp[c - 'a'] == 0)
                    continue;
                hlp[c - 'a']--;
                int can = 1;
                if (can && res.back() == res[0] && c == res[1]) can = 0;
                if (can && c == res[0]) {
                    if (res[0] != res[1]) {
                        if (hlp[res[1] - 'a'] == 0) {}
                        else {
                            if (hlp[res[0] - 'a'] + hlp[res[1] - 'a'] < n - (i + 1)) {}
                            else can = 0;
                        }
                    } else {
                        if (i + 1 < n && hlp[res[0] - 'a'] == n - (i + 1))
                            can = 0;
                    }
                }
                if (can && res[0] == res[1] && hlp[res[0] - 'a'] == n - (i + 1) && i + 2 < n) can = 0;
                if (can) {
                    res.push_back(c);
                    break;
                } else {
                    hlp[c - 'a']++;
                }
            }
            if ((int) res.size() != i + 1)
                break;
        }
        if ((int) res.size() == n)
            return res;
    }
    return "(";
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string res = fast(s);
        cout << res << "\n";
    }
}

string gen_string(mt19937& rnd, int maxa, int maxn) {
    int n = rnd() % maxn + 1;
    string res(n, 'a');
    for (char& c : res)
        c = rnd() % maxa + 'a';
    return res;
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 8;
    const int MAXA = 26;
    while (1) {
        string s = gen_string(rnd, MAXA, MAXN);
        string fs = fast(s);
        string sl = slow(s);
        if (fs == sl) {
            cout << "OK(" << fs << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n";
            cout << "1\n" << s << "\n";
            break;
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}