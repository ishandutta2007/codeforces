#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 300111, inf = 1000111222;

string s, t;
int cnt[100];
int n;
int I = 0;

string S[] = {
    "abc",
    "acb",
    "bac",
    "bca",
    "cba",
    "cab"
};

bool cmp(char a, char b) {
    if (cnt[a] < cnt[b]) {
        return true;
    }
    if (cnt[a] > cnt[b]) {
        return false;
    }
    int pa = -1, pb = -1;
    for (int i = 0; i < 3; ++i) {
        if (S[I][i] == a) {
            pa = i;
        }
        if (S[I][i] == b) {
            pb = i;
        }
    }
    return pa < pb;
}

string solve(char st) {
    memset(cnt, 0, sizeof(cnt));
    string res;
    res += st;
    cnt[st]++;
    for (int i = 1; i < 3 * n; ++i) {
        string abc = "abc";
        sort(abc.begin(), abc.end(), cmp);
        for (char c : abc) {
            if (cnt[c] == n) continue;
            if (c == s[1] && res.back() == s[0]) continue;
            if (c == t[1] && res.back() == t[0]) continue;
            abc.clear();
            res += c;
            cnt[c]++;
            break;
        }
        if (abc.size() != 0) {
            //cout << res << ' ' << abc << endl;
            return "";
        }
    }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> s;
    cin >> t;
    if (s[0] == t[0] && s[1] != s[0] && t[1] != t[0]) {
        set<int> st= {'a', 'b', 'c'};
        char mn = s[0];
        st.erase(mn);
        char a = *st.begin();
        st.erase(st.begin());
        char b = *st.begin();
        st.erase(st.begin());
        cout << "YES" << endl;
        string res;
        for (int i = 0; i < n; ++i) {
            res += a;
        }
        for (int i = 0; i < n; ++i) {
            res += b;
        }
        for (int i = 0; i < n; ++i) {
            res += mn;
        }
        cout << res << endl;
        return 0;
    }
    for (I = 0; I < 6; ++I) {
        string r1 = solve('a');
        string r2 = solve('b');
        string r3 = solve('c');
        if (!r1.empty()) {
            cout << "YES" << endl;
            cout << r1 << endl;
            return 0;
        }
        if (!r2.empty()) {
            cout << "YES" << endl;
            cout << r2 << endl;
            return 0;
        }
        if (!r3.empty()) {
            cout << "YES" << endl;
            cout << r3 << endl;
            return 0;
        }
    }
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    if (s[0] == t[0] && s[1] != s[0] && t[1] != t[0]) {
        set<int> st= {'a', 'b', 'c'};
        char mn = s[0];
        st.erase(mn);
        char a = *st.begin();
        st.erase(st.begin());
        char b = *st.begin();
        st.erase(st.begin());
        cout << "YES" << endl;
        string res;
        for (int i = 0; i < n; ++i) {
            res += a;
        }
        for (int i = 0; i < n; ++i) {
            res += b;
        }
        for (int i = 0; i < n; ++i) {
            res += mn;
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
        return 0;
    }
    for (I = 0; I < 6; ++I) {
        string r1 = solve('a');
        string r2 = solve('b');
        string r3 = solve('c');
        if (!r1.empty()) {
            cout << "YES" << endl;
            reverse(r1.begin(), r1.end());
            cout << r1 << endl;
            return 0;
        }
        if (!r2.empty()) {
            cout << "YES" << endl;
            reverse(r2.begin(), r2.end());
            cout << r2 << endl;
            return 0;
        }
        if (!r3.empty()) {
            cout << "YES" << endl;
            reverse(r3.begin(), r3.end());
            cout << r3 << endl;
            return 0;
        }
    }
    exit(228);
    cout << "NO" << endl;
    return 0;
}