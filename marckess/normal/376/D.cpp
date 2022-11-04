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

int n, m;
char c;
vvi seg;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;

    seg = vvi(m);

    for (int i = 0; i < n; i++) {
        int ini = -1;

        for (int j = 0; j < m; j++) {
            cin >> c;
            if (ini == -1) {
                if (c == '1')
                    ini = j;
            } else {
                if (c == '0') {
                    for (int l = ini; l < j; l++)
                        seg[l].push_back(j-1);
                    ini = -1;
                }
            }
        }

        if (ini != -1)
            for (int l = ini; l < m; l++)
                seg[l].push_back(m-1);
    }

    for (int i = 0; i < m; i++) {
        sort (seg[i].begin(), seg[i].end(), greater<int>());
    }

    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < seg[i].size(); j++) {
            res = max(res, (j+1) * (seg[i][j] - i + 1));
        }
    }

    cout << res << endl;

    return 0;
}