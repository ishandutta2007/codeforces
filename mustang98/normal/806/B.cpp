#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 122, inf = 1000111222, maxp = 1000000007;

ll tv[6], tp[6];
ll cntpart = 0;
ll cntsolve[6];

bool lesse(ll a, ll b, ll c, ll d) {
    ll ch1 = a * d;
    ll ch2 = c * b;
    return ch1 <= ch2;
}

bool les(ll a, ll b, ll c, ll d) {
    ll ch1 = a * d;
    ll ch2 = c * b;
    return ch1 < ch2;
}

bool minpart[6][6];

bool can(ll curc, ll curz, ll fromc, ll fromz, ll toc, ll toz, ll p) {
    int ans = 0;
    for (int i = 0; i <= p; ++i) {
        if (les(fromc, fromz, curc + i, curz) && lesse(curc + i, curz, toc, toz)) {
            return true;
        }
    }
    return false;
}

bool cane(ll curc, ll curz, ll fromc, ll fromz, ll toc, ll toz, ll p) {
    int ans = 0;
    for (int i = 0; i <= p; ++i) {
        if (lesse(fromc, fromz, curc + i, curz) && lesse(curc + i, curz, toc, toz)) {
            return true;
        }
    }
    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, t;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        bool solve = 0;
        for (int j = 0; j < 5; ++j) {
            cin >> t;
            if (i == 0) {
                tv[j] = t;
            } else if (i == 1) {
                tp[j] = t;
            }
            if (t != -1) {
                solve = 1;
                cntsolve[j]++;
            }
        }
        if (solve) cntpart++;
    }

    for (int otv = 0;;++otv) {
        for (int task = 0; task < 5; ++task) {
            minpart[task][0] = can(cntsolve[task], cntpart + otv, 1, 2, 1, 1, tv[task] == -1 ? 0 : otv);
            minpart[task][1] = can(cntsolve[task], cntpart + otv, 1, 4, 1, 2, tv[task] == -1 ? 0 : otv);
            minpart[task][2] = can(cntsolve[task], cntpart + otv, 1, 8, 1, 4, tv[task] == -1 ? 0 : otv);
            minpart[task][3] = can(cntsolve[task], cntpart + otv, 1, 16, 1, 8, tv[task] == -1 ? 0 : otv);
            minpart[task][4] = can(cntsolve[task], cntpart + otv, 1, 32, 1, 16, tv[task] == -1 ? 0 : otv);
            minpart[task][5] = cane(cntsolve[task], cntpart + otv, 0, 1, 1, 32, tv[task] == -1 ? 0 : otv);
        }
       /* for (int i = 0; i < 6; ++i) {
            cout << minpart[4][i] << ' ';
        }
        cout << endl;*/
        int pts[6];
        for (pts[0] = 0; pts[0] < 6; pts[0]++) { if (minpart[0][pts[0]] == false) continue;
        for (pts[1] = 0; pts[1] < 6; pts[1]++) { if (minpart[1][pts[1]] == false) continue;
        for (pts[2] = 0; pts[2] < 6; pts[2]++) { if (minpart[2][pts[2]] == false) continue;
        for (pts[3] = 0; pts[3] < 6; pts[3]++) { if (minpart[3][pts[3]] == false) continue;
        for (pts[4] = 0; pts[4] < 6; pts[4]++) { if (minpart[4][pts[4]] == false) continue;
            int ansv = 0, ansp = 0;
            for (int i = 0; i < 5; ++i) {
                int cost = (pts[i] + 1) * 500;
                int sht = cost / 250;
                if (tv[i] != -1) {
                    ansv += (cost - tv[i] * sht);
                }
                if (tp[i] != -1) {
                    ansp += (cost - tp[i] * sht);
                }
            }
            if (ansv > ansp) {
              //  cout << ansv << ' ' << ansp << endl;
                cout << otv << endl;
              /*  for (int i = 0; i < 5; ++i) {
                    cout << (pts[i] + 1) * 500 <<' ';
                }*/
                return 0;
            }
        }}}}}
        if (otv > 10100) {
            cout << -1;
            return 0;
        }
    }

    return 0;
}