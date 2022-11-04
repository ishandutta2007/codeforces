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

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, a[3];
    cin >> n >> m;
    vi res(n+1, 0);

    while (m--) {
        for (int i = 0; i < 3; i++)
            cin >> a[i];

        bitset<5> bs;
        for (int i = 0; i < 3; i++)
            bs[res[a[i]]] = 1;

        int j = 1;
        for (int i = 0; i < 3; i++) {
            if (!res[a[i]]) {
                while (bs[j])
                    j++;
                bs[j] = 1;
                res[a[i]] = j;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}