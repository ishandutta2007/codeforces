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

void solve(string s) {
    for (int i = 0; i + 1 < s.size(); ++i) {
        if (s[i] == 'a' && s[i + 1] == 'a') {
            puts("2");
            return;
        }
    }
    for (int i = 0; i + 2 < s.size(); ++i) {
        if (s[i] == 'a' && s[i + 2] == 'a') {
            puts("3");
            return;
        }
    }
    for (int i = 0; i + 3 < s.size(); ++i) {
        if (s[i] == 'a' && s[i + 3] == 'a' && s[i + 1] != s[i + 2]) {
            puts("4");
            return;
        }
    }
    for (int i = 0; i + 6 < s.size(); ++i) {
        if (s[i] == 'a' &&
            s[i + 3] == 'a' &&
            s[i + 6] == 'a' &&
            s[i + 1] == s[i + 2] &&
            s[i + 4] == s[i + 5] &&
            s[i + 1] != s[i + 4]) {
                puts("7");
                return;
            }
    }
    puts("-1");
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        solve(s);
    }

    return 0;
}