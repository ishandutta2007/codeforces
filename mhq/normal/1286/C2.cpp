#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
bool cmp(vector < int >& a, vector < int >& b) {
    int sm = 0;
    for (int i = 0; i < 26; i++) {
        sm += b[i] - a[i];
    }
    return sm > 0;
}
multiset < vector < int > > need;
string get(int l, int r) {
    cout << "? " << l << " " << r << endl;
    multiset < vector < int > > all;
    char any;
    for (int i = l; i <= r; i++) {
        for (int j = i; j <= r; j++) {
            string s;
            cin >> s;
            vector < int > f(26);
            for (char& c : s) {
                f[c - 'a']++;
                any = c;
            }
            all.insert(f);
        }
    }
    need = all;
    string ans;
    if (r - l + 1 == 1) {
        ans += any;
        return ans;
    }
    cout << "? " << l + 1 << " " << r << endl;
    for (int i = l + 1; i <= r; i++) {
        for (int j = i; j <= r; j++) {
            string s;
            cin >> s;
            vector < int > f(26);
            for (char& c : s) {
                f[c - 'a']++;
            }
            all.erase(all.find(f));
        }
    }
    vector < vector < int > > gg;
    for (auto it : all) {
        gg.push_back(it);
    }
    sort(gg.begin(), gg.end(), cmp);
    vector < int > hs(26);
    for (int i = 0; i < gg.size(); i++) {
        for (int j = 0; j < 26; j++) {
            if (gg[i][j] > hs[j]) {
                ans += (char)(j + 'a');
                hs[j] = gg[i][j];
            }
        }
    }
    return ans;
}
int getLen(vector < int >& a) {
    int t = 0;
    for (int v : a) t += v;
    return t;
}
vector < int > cnt;
multiset < vector < int > > byLen[150];
char ps[150];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int cut = (n + 1) / 2;
    string f = get(1, cut);
    if (n == 1) {
        cout << "! " << f << endl;
        return 0;
    }
    cout << "? " << 1 << " " << n << endl;
    multiset < vector < int > > all;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            string s;
            cin >> s;
            vector < int > f(26);
            for (char& c : s) {
                f[c - 'a']++;
            }
            all.insert(f);
        }
    }
    for (auto& it : need) {
        all.erase(all.find(it));
    }
    for (auto it : all) {
        byLen[getLen(it)].insert(it);
    }
    vector < int > cnt(26);
    assert(byLen[n].size() == 1);
    for (int i = 0; i < 26; i++) {
        cnt[i] = (*byLen[n].begin())[i];
    }
    for (char c : f) {
        cnt[c - 'a']--;
    }
    for (int i = 0; i < f.size(); i++) ps[i + 1] = f[i];
    string rv;
    for (int len = 1; len < n - cut; len++) {
        int l = cut + 1;
        int r = n - len + 1;
        // don't know from l to r
        int have_len = n - len;
        for (int i = 1; i <= n - have_len + 1; i++) {
            int from = i;
            int to = i + have_len - 1;
            if (to < l) continue;
            if (from <= l && r <= to) {
                vector < int > gg = cnt;
                for (int j = from; j <= to; j++) {
                    if (j < l || j > r) {
                        gg[ps[j] - 'a']++;
                    }
                }
                byLen[have_len].erase(byLen[have_len].find(gg));
            }
        }
        assert(byLen[have_len].size() == 1);
        vector < int > who = *byLen[have_len].begin();
        for (int j = 1; j <= have_len; j++) {
            if (j < l || j > r) {
                who[ps[j] - 'a']--;
            }
        }
        for (int j = 0; j < 26; j++) {
            if (who[j] < cnt[j]) {
                ps[r] = (char)(j + 'a');
                rv += ps[r];
                cnt[j] = who[j];
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            rv += (char)(i + 'a');
            break;
        }
    }
    reverse(rv.begin(), rv.end());
    f += rv;
    cout << "! " << f << endl;
    return 0;
}