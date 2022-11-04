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

int n, l, a[55], b[55], c[55], d[55];

void izq (int a[]) {
    int temp = a[0];
    for (int i = 0; i < n - 1; i++)
        a[i] = a[i+1];
    a[n-1] = temp;

    for (int i = 1; i < n; i++)
        a[i] = MOD(a[i] - a[0], l);
    a[0] = 0;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> l;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 1; i < n; i++)
        a[i] -= a[0];
    a[0] = 0;

    for (int j = 1; j < n; j++)
        b[j] -= b[0];
    b[0] = 0;

    for (int i = 0; i < n; i++) {
        bool res = 1;
        for (int j = 0; j < n; j++) 
            res &= a[j] == b[j];
        if (res) {
            cout << "YES" << endl;
            return 0;
        }
        izq(b);
    }

    cout << "NO" << endl;

    return 0;
}