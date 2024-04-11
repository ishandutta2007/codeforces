/*
    17.11.2018 0:13:21
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    vector< int > s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    vector< pair< int, int > > a;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || s[i] != s[i - 1]) {
            a.push_back({1, s[i]});
        } else {
            ++a.back().first;
        }
    }
    sort(a.begin(), a.end());
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int c = (l + r) / 2;
        vector< pair< int, int > > b = a;
        int sm = 0;
        for (int i = 0; i < b.size(); ++i) {
            b[i].first /= c;
            sm += b[i].first;
        }
        if (sm < k) {
            r = c;
        } else {
            l = c;
        }
    }
    vector< int > t;
    for (int i = 0; i < a.size(); ++i) {
        a[i].first /= l;
        for (int j = 0; j < a[i].first; ++j) {
            t.push_back(a[i].second);
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << t[i] << ' ';
    }
    cout << '\n';
    return 0;
}