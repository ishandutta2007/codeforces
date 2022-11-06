#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>

#define pii pair<ll,ll>
#define MOD 1000000007
#define mp make_pair
#define X first
#define Y second
typedef int ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x;
ll a[100500], p[200500];
vector<ll> g[1005];
char s[1005][1005];
ll used[2005];
vector<ll> f;
ll compsz;
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < m; i++) {
        f.push_back(1);
    }
    for (int i = 0; i < n; i++) {
        ll mx = -MOD, mn = MOD, eq = -1;
        for (int j = 0; j < m; j++) {
                if (s[i][j] == '>') {
                    mx = max(mx, f[j]);
                } else if (s[i][j] == '<') {
                    mn = min(mn, f[j]);
                } else {
                    if (eq == -1 || eq == f[j]) {
                        eq = f[j];
                    } else {
                        cout << "No" << endl;
                        return 0;
                    }
                }
        }
        if (eq == -1) {
            if (mx > mn) {
                cout << "No" << endl;
                return 0;
            }
            if (mx == -MOD) {
                if (mn == 1) {
                    for (int j = 0; j < m; j++) {
                        f[j]++;
                    }
                }
            } else if (mn == MOD) {

            } else {
                if (mx == mn || mx + 1 == mn) {
                    for (int j = 0; j < m; j++)
                        if (s[i][j] == '<') {
                            f[j] += 2 - (mn-mx);
                        }
                }
            }
        } else {
            if (mx > eq || eq > mn) {
                cout << "No" << endl;
                return 0;
            }
            if (mx == eq && mx == mn) {
                for (int j = 0; j < m; j++) {
                    if (s[i][j] == '=') {
                        f[j]++;
                    }
                    if (s[i][j] == '<')
                        f[j] += 2;
                }
            }
            if (mx == eq && mx < mn) {
                for (int j = 0; j < m; j++)
                    if (s[i][j] != '>')
                        f[j]++;
            }
            if (mx < eq && eq == mn) {
                for (int j = 0; j < m; j++)
                    if (s[i][j] == '<')
                        f[j]++;
            }
        }
    }
    /*for (int j = 0; j < m; j++)
        cout << f[j] << " ";
    cout << endl;*/
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
        int mx = 0, mn = MOD, eq = -1;
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '>') {
                mx = max(mx, f[j]);
            } else if (s[i][j] == '<') {
                mn = min(mn, f[j]);
            } else {
                if (eq == -1 || eq == f[j]) {
                    eq = f[j];
                } else {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
        if (eq != -1) {
            cout << eq << " ";
            continue;
        }
        cout << mx+1 << " ";
    }
    cout << endl;
    for (int j = 0; j < m; j++) {
        cout << f[j] << " ";
    }
    return 0;
}