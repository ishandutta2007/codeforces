#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define INF 2147483647
#define MOD ((ll) (1e18+7))
#define MAX 300000
#define MAXL 600000

typedef long long ll;
typedef pair<int, int> pii;

int n, m, ch;
string s;

ll hashtable[MAX];

ll as[MAXL + 1];

ll gethash()
{
    unsigned int i = s.size();
    ll h = 0;
    while (i-- > 0) {
        h = (h + as[i] * (s[i] - 'a' + 1)) % MOD;
    }
    return h;
}

ll mod(ll a, ll m)
{
    return (a < 0) ? ((a % m) + m) : (a % m);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    as[0] = 1;
    for (int i = 1; i <= MAXL; i++) {
        as[i] = (as[i - 1] * 4) % MOD;
    }

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        hashtable[i] = gethash();
        cerr << hashtable[i] << endl;
    }
    sort(hashtable, hashtable + n);
    for (int i = 0; i < m; i++) {
        cin >> s;
        bool exists = false;
        ll curh = gethash();
        for (unsigned int j = 0; j < s.size(); j++) {

            ch = s[j] - 'a' + 1;
            ll curhash = mod(curh - ch * as[j], MOD);
            if (((ch != 1) & binary_search(hashtable, hashtable + n, curhash = (curhash + as[j]) % MOD)) ||
                ((ch != 2) & binary_search(hashtable, hashtable + n, curhash = (curhash + as[j]) % MOD)) ||
                ((ch != 3) & binary_search(hashtable, hashtable + n, curhash = (curhash + as[j]) % MOD))) {
                exists = true;
                break;
            }
        }
        cout << (exists ? "YES" : "NO") << endl;
    }

    return 0;
}