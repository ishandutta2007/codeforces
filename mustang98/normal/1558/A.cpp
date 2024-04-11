#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = -1, inf = 1000111222;

int cnt(string a, string b) {
    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            ++ans;
        }
    }
    return ans;
}

set<int> st;

void proc(string a, string b) {
    int mn = cnt(a, b);
    reverse(b.begin(), b.end());
    int mx = cnt(a, b);
    if (mn > mx) {
        swap(mn, mx);
    }
    if (mn % 2 != mx % 2) {
        exit(228);
    }
    for (int i = mn; i <= mx; i += 2) {
        st.insert(i);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        st.clear();
        int a, b;
        cin >> a >> b;
        string sa, sb;
        int n = a + b;
        string s;
        for (int i = 0; i < a; ++i) {
            s += 'A';
        }
        for (int i = 0; i < b; ++i) {
            s += 'B';
        }
        for (int i = 0; i < n; ++i) {
            sa += "AB"[i % 2];
            sb += "BA"[i % 2];
        }
        sort(sa.begin(), sa.end());
        sort(sb.begin(), sb.end());
        proc(sa, s);
        proc(sb, s);
        cout << st.size() << "\n";
        for (int x : st) {
            cout << x << ' ';
        }
        cout << "\n";
    }

    return 0;
}