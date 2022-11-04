#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
 
const int MX = (1 << 22);
int n, m, u, v, res = 0, mk;
bitset<MX+5> ex;
bitset<2*MX+5> bs;

void dfs (int u) {
    bs[u] = 1;
    
    if (u < MX) {
        if (!bs[u+MX])
            dfs(u+MX);
    } else {
        u -= MX;
        for (int j = 1, l = 0; l < n; l++, j *= 2)
            if (!bs[(u|j)+MX])
                dfs((u|j)+MX);

        int c = (~u & mk);
        if (ex[c] && !bs[c])
            dfs(c);
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    mk = (1 << n) - 1;

    while (m--) {
        cin >> u;
        ex[u] = 1;
    }

    for (int i = 0; i < (1 << n); i++)
        if (ex[i] && !bs[i]) {
            dfs(i);
            res++;
        }

    cout << res << endl;

    return 0;
}