#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 50005;
bitset<1005> var[MX];
int res[MX], op[MX], a[MX], b[MX], n, m;
map<string, int> mp, fop;
string s, mx, mn;

int obtRes (int i) {
    int sum = 0;

    for (int j = 0; j <= n; j++) {
        if (!op[j])
            res[j] = int(var[j][i]);
        else if (op[j] == 1)
            res[j] = int(res[a[j]] && res[b[j]]);
        else if (op[j] == 2)
            res[j] = int(res[a[j]] || res[b[j]]);
        else
            res[j] = int(res[a[j]] ^ res[b[j]]);

        if (j)
            sum += res[j];
    }

    return sum;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    mp["?"] = 0;
    fop["AND"] = 1;
    fop["OR"] = 2;
    fop["XOR"] = 3;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        mp[s] = i;

        cin >> s >> s;
        if (s[0] == '0' || s[0] == '1') {
            for (int j = 0; j < m; j++)
                var[i][j] = s[j] == '1';
            op[i] = 0;
        } else {
            a[i] = mp[s];

            cin >> s;
            op[i] = fop[s];

            cin >> s;
            b[i] = mp[s];
        }
    }

    mx = mn = string(m, '0');

    for (int i = 0; i < m; i++) {
        int c, u;
        var[0][i] = 0;
        c = obtRes(i);
        var[0][i] = 1;
        u = obtRes(i);

        if (c < u)
            mx[i] = '1';
        if (c > u)
            mn[i] = '1';
    }

    cout << mn << endl << mx << endl;

    return 0;
}