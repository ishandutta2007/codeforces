#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, m, k, res = 0;
char c[2005][2005];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> c[i];

    int acu = 0;
    for (int i = 0; i < n; i++) {
        acu = 0;
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '.')
                acu++;
            else
                acu = 0;
            if (acu >= k)
                res++;
        }
    }

    for (int j = 0; j < m; j++) {
        acu = 0;
        for (int i = 0; i < n; i++) {
            if (c[i][j] == '.')
                acu++;
            else
                acu = 0;
            if (acu >= k)
                res++;
        }
    }

    if (k > 1)
        cout << res << endl;
    else
        cout << res / 2 << endl;

    return 0;
}