#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 211, inf = 1000111222;
const ll mod = 1000000007;

string s;
ll dp[max_n][max_n][max_n];
int n;

int pr[max_n];
int pf[max_n];

int pr_func(const string& s1) {
    memset(pf, 0, sizeof(pf));
    pf[0] = 0;
    for (int i = 1; i < s1.size(); ++i) {
        int k = pf[i - 1];
        while (k > 0) {
            if (s1[k] == s1[i]) {
                break;
            }
            k = pf[k - 1];
        }
        if (s1[k] == s1[i]) {
            pf[i] = k + 1;
        } else {
            pf[i] = 0;
        }
    }
    return pf[s1.size() - 1];
}

void findpr() {
    for (int i = 0; i + 1 < s.size(); ++i) {
        string s1 = s.substr(0, i + 1);
        if (s[i + 1] == '(') s1 += ')';
        else s1 += '(';
        pr[i] = pr_func(s1);
    }
}


int main()
{
   // freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> s;
    findpr();

    dp[0][0][0] = 1;
   /* for (int i = 0; i + 1 < s.size(); ++i) {
        cout << pr[i] << ' ' ;
    }
    cout << endl;
*/
    for (int i = 0; i < 2 * n; ++i) {
        for (int sum = 0; sum <= i; ++sum) {
            for (int p = 0; p <= s.size(); ++p) {
                dp[i][sum][p] %= mod;
                if (dp[i][sum][p] == 0) continue;
                if (p == s.size()) {
                    dp[i + 1][sum + 1][p] += dp[i][sum][p];
                    if (sum > 0) {
                        dp[i + 1][sum - 1][p] += dp[i][sum][p];
                    }
                    continue;
                }
                char nxt = s[p];
                int sign = (nxt == '(' ? 1 : -1);
                if (sum + sign >= 0) {
                    dp[i + 1][sum + sign][p + 1] += dp[i][sum][p];
                }

                if (sum - sign >= 0 && p) {
                    dp[i + 1][sum - sign][pr[p - 1]] += dp[i][sum][p];
                }
                if (sum - sign >= 0 && p == 0) {
                    dp[i + 1][sum - sign][0] += dp[i][sum][p];
                }
            }
        }
    }
    //cout << dp[1][1][1] << endl;
    cout << (dp[2 * n][0][s.size()] % mod) << endl;

    return 0;
}