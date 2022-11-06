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

int a, b, c, d;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> a >> b >> c >> d;

    cout << 50 << " " << 50 << endl;

    a--, b--;
    for (int i = 0; i < 25; i++) {
        if (i % 2) {
            for (int j = 0; j < 50; j++)
                cout << 'A';
            cout << endl;
        } else {
            for (int j = 0; j < 50; j++) {
                if (j % 2 || (!b && !c && !d))
                    cout << 'A';
                else if (b) {
                    cout << 'B';
                    b--;
                } else if (c) {
                    cout << 'C';
                    c--;
                } else if (d) {
                    cout << 'D';
                    d--;
                }
            }
            cout << endl;
        }
    }

    for (int i = 0; i < 25; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < 50; j++)
                cout << 'B';
            cout << endl;
        } else {
            for (int j = 0; j < 50; j++) {
                if (j % 2 || (!a && !c && !d))
                    cout << 'B';
                else if (a) {
                    cout << 'A';
                    a--;
                } else if (c) {
                    cout << 'C';
                    c--;
                } else if (d) {
                    cout << 'D';
                    d--;
                }
            }
            cout << endl;
        }
    }

    return 0;
}