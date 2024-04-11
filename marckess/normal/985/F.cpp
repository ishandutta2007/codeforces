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

const int MX = 200005, MH = 3;

struct Hash {
    int mod, b[MX], h[MX], sz;

    void init (ll _mod, ll _b) {
        mod = _mod;
        sz = 1;
        b[0] = 1;
        h[0] = 0;
        for (int i = 1; i < MX; i++)
            b[i] = b[i-1] * _b % mod;
    }

    void insert (int x) {
        h[sz] = (ll(h[sz-1]) * b[1] + x) % mod;
        sz++;
    }

    int get (int l, int r) {
        int res = h[r] - ll(h[l-1]) * b[r-l+1] % mod;
        if (res < 0)
            res += mod;
        return res;
    }
};

Hash h[26][MH];
char s[MX];
int n, q, x, y, len, sig[MX][26];

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 26; i++) {
        h[i][0].init(1e9+7, 37);
        h[i][1].init(1e9+9, 43);
        h[i][2].init(1e9+21, 47);
    }

    scanf("%d%d %s ", &n, &q, s);

    for (int i = 0; i < 26; i++)
        sig[n][i] = -1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 26; j++)
            for (int k = 0; k < MH; k++)
                h[j][k].insert(s[i] - 'a' == j);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++)
            sig[i][j] = sig[i+1][j];
        sig[i][s[i]-'a'] = i;
    }

    while (q--) {
        scanf("%d%d%d", &x, &y, &len);
        x--, y--;

        bool res = 1;
        for (int i = 0; i < 26; i++)
            if (sig[x][i] != -1 && sig[x][i] < x + len)
                for (int j = 0; j < MH; j++)
                    res &= h[i][j].get(x+1, x+len) == h[s[sig[x][i] - x + y] - 'a'][j].get(y+1, y+len);

        if (res)
            printf("YES\n");
        else
            printf("NO\n");
    }

	return 0;
}