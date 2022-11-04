#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, k;
char res[105][105];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i % 2 == j % 2 && k) {
                k--;
                res[i][j] = 'L';
            } else
                res[i][j] = 'S';

    if (!k) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << res[i][j];
            cout << endl;
        }
    } else { 
        cout << "NO" << endl;
    }
    
    return 0;
}