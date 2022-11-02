#include <bits/stdc++.h>

using namespace std;

int n;
set<int> s1, s2;

int main() {
    cin >> n;
    string s; cin >> s;
    for (int i = 0; i < n; i++)
        if (s[i] == 'D') s1.insert(i);
        else s2.insert(i);

    int p = 0;
    while (!s1.empty() && !s2.empty()) {
        auto a = s1.lower_bound(p);
        auto b = s2.lower_bound(p);
        if (a == s1.end() && b == s2.end()) p = min(*s1.begin(), *s2.begin());
        else if (a == s1.end()) p = *b;
        else if (b == s2.end()) p = *a;
        else p = min(*a, *b);

        if (s[p] == 'D') {
            auto i = s2.lower_bound(p);
            if (i == s2.end()) s2.erase(s2.begin());
            else s2.erase(i);
        } else {
            auto i = s1.lower_bound(p);
            if (i == s1.end()) s1.erase(s1.begin());
            else s1.erase(i);
        }
        p++;
    }

    if (!s1.empty()) cout << "D";
    else cout << "R";
}