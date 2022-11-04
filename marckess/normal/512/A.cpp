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

int n, cn = 0;
string s[105];
vi adj[255], res;
int num[105][105], bs[255];

bool dfs (int u) {
    bs[u] = 1;

    for (int v : adj[u]) {
        if (bs[v] == 1)
            return 0;
        if (bs[v] == 0)
            if (!dfs(v))
                return 0;
    }

    res.push_back(u);
    bs[u] = 2;
    return 1;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int j = 0; j < 100; j++) {
        for (int i = 0; i < n; i++)  {
            if (j >= s[i].size())
                continue;

            if (!i || j >= s[i-1].size() || (j && num[i][j-1] != num[i-1][j-1])) {
                cn++;
            } else if (s[i][j] != s[i-1][j]) {
                cn++;
                adj[s[i-1][j]].push_back(s[i][j]);
                //cout << s[i-1][j] << "->" << s[i][j] << endl;
            }

            num[i][j] = cn;
        }
    }

    for (int i = 1; i < n; i++) {
        if (s[i-1].size() > s[i].size()) {
            int d = s[i].size() - 1;
            //cout << i << " " << num[i-1][d] << " " << num[i][d] << endl;
            if (num[i-1][d] == num[i][d]) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    for (int i = 'a'; i <= 'z'; i++)
        if (!bs[i])
            if (!dfs(i)) {
                cout << "Impossible" << endl;
                return 0;
            }

    reverse(res.begin(), res.end());
    for (int x : res)
        cout << char(x);
    cout << endl;

    return 0;
}