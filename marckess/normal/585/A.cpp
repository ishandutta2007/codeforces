#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, v[4005], d[4005], p[4005];
bitset<4005> exi;
vi res;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i] >> d[i] >> p[i];

    exi.set();
    for (int i = 0; i < n; i++) {
        if (!exi[i])
            continue;

        res.push_back(i+1);
        
        stack<int> dead;
        int r = 0;
        for (int j = i+1; j < n; j++) {
            if (!exi[j] || r == v[i])
                continue;

            p[j] -= v[i] - r;
            if (p[j] < 0) {
                exi[j] = 0;
                dead.push(j);
            }

            r++;
        }

        while (dead.size()) {
            int u = dead.top();
            dead.pop();

            for (int j = u+1; j < n; j++) {
                if (!exi[j])
                    continue;

                p[j] -= d[u];
                if (p[j] < 0) {
                    exi[j] = 0;
                    dead.push(j);
                }
            }
        }
    }

    cout << res.size() << endl;
    for (int x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}