#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) (((n % k) + k ) % k)



int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, a;
    vi cub(105);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        cub[a]++;
    }

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (i != j && cub[i] == cub[j] && cub[i] == n / 2) {
                cout << "YES" << endl;
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}