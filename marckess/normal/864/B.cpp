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

    int n, acu = 0, res = 0;
    char c;

    bitset<255> bs;

    cin >> n;
    while (n--) {
        cin >> c;
        if ('a' <= c && c <= 'z') {
            if (!bs[c]) {
                bs[c] = 1;
                acu ++;
            }
        } else {
            acu = 0;
            bs.reset();
        }

        res = max(res, acu);
    }

    cout << res << endl;

    return 0;
}