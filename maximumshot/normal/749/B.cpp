#include <bits/stdc++.h>

#include <unordered_set>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    pii a[3];

    for(int i = 0;i < 3;i++) cin >> a[i].first >> a[i].second;

    sort(a, a + 3);

    set< pii > q;

    do{
        pii t = make_pair( a[0].first + a[2].first - a[1].first, a[0].second + a[2].second - a[1].second );
        q.insert( t );
    }while(next_permutation(a, a + 3));

    cout << (int)q.size() << "\n";

    for(pii x : q) cout << x.first << " " << x.second << "\n";

    return 0;
}