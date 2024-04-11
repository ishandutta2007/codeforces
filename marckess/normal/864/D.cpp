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

    int n, q = 0;

    cin >> n;
    vi a(n), cub(n+2), res(n);
    bitset<200005> bs;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cub[a[i]]++;
    }

    int j = 1;
    while (j <= n && cub[j] > 0)
        j++;

    for (int i = 0; i < n; i++) {
        if (cub[a[i]] == 1) {
            res[i] = a[i];
            bs[a[i]] = 1;
        } else {
            if (a[i] < j && !bs[a[i]]) {
                bs[a[i]] = 1;
                res[i] = a[i];
                continue;
            }
            res[i] = j;
            cub[j]++;
            while (j <= n && cub[j] > 0)
                j++;
            q++;
            cub[a[i]]--;
            bs[j] = 1;
        }
    }

    cout << q << endl;
    for (int x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}