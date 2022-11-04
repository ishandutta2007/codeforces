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

int n, k;
char res[4][100];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = '.';

    cout << "YES" << endl;

    if (k & 1) {
        for (int i = 1; i < n / 2; i++)
            if (k >= 2) {
                res[1][i] = res[1][n-i-1] = '#';
                k -= 2;
            }
        
        if (k) {
            res[1][n/2] = '#';
            k--;
        }

        for (int i = 1; i < n / 2; i++)
            if (k >= 2) {
                res[2][i] = res[2][n-i-1] = '#';
                k -= 2;
            }

        if (k) {
            res[2][n/2] = '#';
            k--;
        }
    } else {
        for (int i = 1; i < n-1; i++)
            if (k >= 2) {
                res[1][i] = res[2][i] = '#';
                k -= 2;
            }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j];
        }
        cout << endl;
    }

    return 0;
}