
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// (1-indexing)
// The ith character appears in how many substrings?
// i * (n - i + 1)

// Longest substring of s is just s. So we know all the character counts.

// Ask the queries [1, n] and [2, n] to find the first character.
// substrings of length 2 will be the same, except [1, n] has an extra one
// for the first 2 characters. Similarly for all substrings of length k
// So we can build the whole string.

// How many substrings of [1, n]?
// 1 + 2 + 3 + ... + n = n * (n + 1) / 2

// of [2, n]?
// (n - 1) * n / 2

// both less than (n + 1)^2 / 2.

// subroutine: missing(a, b)
// assume |b| = |a| + 1. Find the character in b missing from a.

int n;
string s, t;
multiset<string> A;
int cnt[26];

char missing(const string &a, const string &b) {
    fill(cnt, cnt + 26, 0);
    for(char c : b) cnt[c - 'a']++;
    for(char c : a) cnt[c - 'a']--;
    for(int i = 0; i < 26; i++) {
        if(cnt[i] > 0) return (i + 'a');
    }
    return '\0';
}

bool cmp(const string &s, const string &t) {
    return s.size() < t.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cout << "? 1 " << n << endl;
    for(int i = 0; i < n * (n + 1) / 2; i++) {
        cin >> s;
        sort(s.begin(), s.end());
        A.insert(s);
    }
    if(n == 1) {
        cout << "! " << s << endl;
        return 0;
    }
    cout << "? 2 " << n << endl;
    for(int i = 0; i < (n - 1) * n / 2; i++) {
        cin >> s;
        sort(s.begin(), s.end());
        A.erase(A.find(s));
    }
    t = "";
    vector<string> v(A.begin(), A.end());
    sort(v.begin(), v.end(), cmp);
    for(string str : v) {
        t.push_back(missing(t, str));
    }
    cout << "! " << t << endl;
}