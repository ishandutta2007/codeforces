
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

using hist = array<int, 26>;

hist makehist(const string &s) {
    hist h{0};
    for(char c : s) h[c - 'a']++;
    return h;
}

vector<hist> ask(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int num = (r - l + 1) * (r - l + 2) / 2;
    vector<hist> ve;
    rep(i, 0, num) {
        string s;
        cin >> s;
        ve.push_back(makehist(s));
    }
    return ve;
}

int len(const hist &a) {
    int s = 0;
    rep(i, 0, 26) s += a[i];
    return s;
}

bool cmp_len(const hist &a, const hist &b) {
    return len(a) < len(b);
}

hist operator-(const hist &a, const hist &b) {
    hist x = a;
    rep(i, 0, 26) x[i] -= b[i];
    return x;
}

hist operator-(const hist &a, char c) {
    hist x = a;
    x[c - 'a']--;
    return x;
}

int getone(const hist &a) {
    rep(i, 0, 26) if(a[i] > 0) return i;
    assert(false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if(n <= 3) {
        string ans(n, '.');
        rep(i, 1, n + 1) {
            hist h = ask(i, i)[0];
            ans[i - 1] = 'a' + getone(h);
        }
        cout << "! " << ans << endl;
        return 0;
    }
    int n2 = (n + 1) / 2;
    vector<hist> smol = ask(1, n2 - 1);
    vector<hist> med = ask(1, n2);
    string ans(n + 1, '.');
    multiset<hist> ms(all(med));
    for(hist &h : smol) {
        ms.erase(ms.find(h));
    }
    med.clear();
    med.assign(all(ms));
    sort(all(med), cmp_len);
    for(int i = sz(med) - 1; i > 0; i--) {
        med[i] = med[i] - med[i - 1];
    }
    rep(i, 0, sz(med)) {
        ans[n2 - i] = 'a' + getone(med[i]);
    }

    vector<hist> big = ask(1, n);
    vector<vector<hist>> bad(n + 1);
    for(hist &h : big) bad[len(h)].push_back(h);
    hist everyone = bad[n][0];
    hist stuff{0};

    for(int p = n; p > n2; p--) {
        int k = n - p + 1;
        int len = p - 1;
        hist drool = stuff;
        for(int l = 1; l <= k; l++) {
            drool[ans[l] - 'a']++;
            auto it = find(all(bad[len]), everyone - drool);
            assert(it != bad[len].end());
            bad[len].erase(it);
            if(l < k) drool[ans[p + l] - 'a']--;
        }
        assert(sz(bad[len]) == 1);
        int ch = getone(everyone - stuff - bad[len][0]);
        stuff[ch]++;
        ans[p] = 'a' + ch;
    }

    cout << "! " << ans.substr(1) << endl;
}