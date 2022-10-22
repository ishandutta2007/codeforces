#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table; // the usage is the same as the unordered_map

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int mod = 998244353;
const int N = 16;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector< int > a(n);

    for(int i = 0;i < n;i++) {
        a[i] = s[i] - '0';
    }

    vector< vector< int > > cnt(n, vector< int >(3));

    for(int i = n - 1;i >= 0;i--) {
        if(i + 1 < n) cnt[i] = cnt[i + 1];
        cnt[i][ a[i] ]++;
    }

    int glob = 0;
    vector< int > need = {n / 3, n / 3, n / 3};

    for(int i = 0;i < 3;i++) {
        glob += abs(need[i] - cnt[0][i]);
    }

    glob /= 2;

    int already = 0;


    for(int i = 0;i < n;i++) {
        for(int x = 0;x < 3;x++) {
            if(!need[x]) continue;
            int cost = 0;
            vector< int > tneed = need;
            tneed[x]--;
            vector< int > have = i + 1 < n ? cnt[i + 1] : vector< int >(3, 0);
            for(int j = 0;j < 3;j++) {
                cost += abs(tneed[j] - have[j]);
            }
            cost = cost / 2 + (a[i] != x) + already;
            if(cost == glob) {
                already += (x != a[i]);
                need[x]--;
                a[i] = x;
                break;
            }
        }
    }

    for(int i = 0;i < n;i++) {
        cout << a[i];
    }
    cout << "\n";

    return 0;
}