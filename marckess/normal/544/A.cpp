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

int k, n;
string s;
bitset<256> bs;
int pr[256];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k >> s;
    n = s.size();

    for (int i = 0; i < n; i++) {
        if (!bs[s[i]]) {
            bs[s[i]] = 1;
            pr[s[i]] = i;
        }
    }

    if (bs.count() < k) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES";
    for (int i = 0; i < n; i++) {
        if (pr[s[i]] == i && k) {
            k--;
            cout << endl;
        }
        cout << s[i];
    }
    cout << endl;

    return 0;
}