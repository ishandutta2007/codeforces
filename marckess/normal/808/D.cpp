#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 100005;
int n, a[MX];
ll izq = 0, der = 0;
map<ll, int> mi, md;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        der += a[i];
        md[a[i]]++;
    }


    if (der % 2 == 0 && md[der / 2]) {
        cout << "YES" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        izq += a[i], der -= a[i];
        mi[a[i]]++, md[a[i]]--;

        if (izq == der) {
            cout << "YES" << endl;
            return 0;
        }

        map<ll, int> &m = izq > der ? mi : md;
        ll d = abs(izq - der);

        if (d % 2 == 0) {
            d /= 2;
            if (m[d]) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}