#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 111, inf = 1000111222;

int cnt[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    string nn = "ineteen";
    cin >> s;
    int ans = 0;
    for (int i = 0 ; i < s.size(); ++i) {
        cnt[s[i]]++;
    }
    if (cnt['n'] == 0) {
        cout << 0;
        return 0;
    }
    --cnt['n'];
    while(true) {
        for (int i = 0; i < nn.size(); ++i) {
            if (cnt[nn[i]] == 0) {
                cout << ans << endl;
                return 0;
            }
            --cnt[nn[i]];
        }
        ++ans;
    }
    return 0;
}