#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

void bad() {
    cout << ":(" << endl;
    exit(0);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int na = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != 'a') {
            ++na;
        }
    }
    if (na == 0) {
        cout << s << endl;
        return 0;
    }
    if (na % 2 == 1) {
        bad();
    }
    string s1, s2;
    int c =0 ;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != 'a') {
            if (s1.size() < na / 2) {
                s1 += s[i];
            } else {
                s2 += s[i];
            }
        }
    }
    if (s1 != s2) {
        bad();
    }
    string ans = s.substr(0, s.size() - na / 2);
    string suf = s.substr(ans.size());
    if (suf != s2) {
        bad();
    }
    cout << ans << endl;
    return 0;
}