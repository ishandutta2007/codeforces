#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;

string s, t;
int pref[N];
bool eq[N];
bool can[N];
int dp[N];
int best[N];

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    cin >> s >> t;

    if((int)s.size() < (int)t.size()) {
        cout << "0\n";
        return 0;
    }

    for(int i = 1;i < (int)t.size();i++) {
        int j = pref[i - 1];
        while(j > 0 && t[i] != t[j]) j = pref[j - 1];
        if(t[i] == t[j]) j++;
        pref[i] = j;
    }

    for(int i = (int)t.size() - 1;i >= 0;i = pref[i] - 1) {
        eq[i + 1] = 1;
    }

    for(int j = (int)t.size() - 1;j < (int)s.size();j++) {
        // j - (int)t.size() + 1 .. j
        can[j] = 1;
        for(int iter = 0;iter < (int)t.size();iter++) {
            char x = s[j - (int)t.size() + 1 + iter];
            char y = t[iter];
            if(x != '?' && x != y) {
                can[j] = 0;
                break;
            }
        }
    }

    int res = 0;

    for(int i = (int)t.size() - 1;i < (int)s.size();i++) {
        if(!can[i]) {
            if(i > 0)
                best[i] = best[i - 1];
            continue;
        }
        for(int j = i - 1;j >= i - (int)t.size() + 1;j--) {
            if(can[j] && eq[j - (i - (int)t.size() + 1) + 1]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int last = i - (int)t.size() + 1;
        if(last == 0) {
            dp[i] = max(dp[i], 1);
        }else {
            dp[i] = max(best[last - 1] + 1, dp[i]);
        }
        best[i] = max(i > 0 ? best[i - 1] : 0, dp[i]);
    }

    cout << best[(int)s.size() - 1] << "\n";

    return 0;
}