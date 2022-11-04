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

int n, m, k, s[1000005], q[1000005], x;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    vi ac(10000005, k), v;

    while (n--) {
        cin >> x;
        ac[x]--;
    }

    for (int i = 0; i < m; i++) {
        cin >> s[i];
        q[i] = i;
    }
    sort(q, q+m, [](int a, int b) {return s[a] < s[b];});

    int j = 0, res = 0;
    for (int i = 0; i <= 10000000; i++) {
        while (j < m && s[q[j]] < i)
            j++;

        if (ac[i] < 0) {
            cout << -1 << endl;
            return 0; 
        }

        while (j < m && ac[i] > 0) {
            v.push_back(q[j]);
            res++;
            ac[i]--;
            j++;
        }
    }

    cout << res << endl;
    for (int i = 0; i < res; i++)
        cout << v[i] + 1 << " ";
    cout << endl;

    return 0;
}