#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) (((n % k) + k ) % k)

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string a, b, c;

    cin >> a >> b >> c;

    vi ca(255), cb(255), cc(255);
    for (char x : a)
        ca[x]++;
    for (char x : b)
        cb[x]++;
    for (char x : c)
        cc[x]++;

    int x = 1e5, y;
    for (int i = 'a'; i <= 'z'; i++) {
        if (cb[i] == 0)
            continue;
        x = min(x, ca[i]/cb[i]);
    }

    int resx = 0, resy = 0;
    for (x; x >= 0; x--) {
        y = 1e5;

        for (int j = 'a'; j <= 'z'; j++) {
            if (cc[j] == 0)
                continue;
            y = min(y, (ca[j] - x * cb[j]) / cc[j]);
        }

        if (x + y > resx + resy) {
            resx = x;
            resy = y;
        }
    }

    for (int i = 'a'; i <= 'z'; i++)
        for (int j = ca[i] - resx * cb[i] - resy * cc[i]; j > 0; j--)
            cout << char(i);

    for (resx; resx > 0; resx--)
        cout << b;
    for (resx; resy > 0; resy--)
        cout << c;

    cout << endl;

    return 0;
}