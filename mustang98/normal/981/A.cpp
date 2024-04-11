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

bool is_p(string s) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != s[s.size() - i - 1]) return 0;
    }
    return 1;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        for (int l = 1; l <= (int)s.size() - i; ++l) {
            string sub = s.substr(i, l);
            //cout << sub << endl;
            if (!is_p(sub)) {
                ans = max(ans, (int)sub.size());
            }
        }
    }
    cout << ans;
    return 0;
}