#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;
typedef bitset <501> Bs;

int N, K;

int main(void) {
    cin >> N >> K;
    vector <Bs> now(K + 1, Bs()), next(K + 1, Bs());
    now[0].set(0);
    int x;
    ff(i, 1, N) {
        cin >> x;
        ff(j, 0, K) {
            next[j] = now[j];
            if (j >= x) {
                next[j] |= now[j-x];
                next[j] |= (now[j-x] << x);
            }
        }
        now.swap(next);
    }
    vi v;
    ff(i, 0, K) if (now[K].test(i)) v.pb(i);
    cout << v.size() << "\n";
    ff(i, 0, (int)v.size() - 1) cout << v[i] << " "; cout << endl;
    return 0;
}