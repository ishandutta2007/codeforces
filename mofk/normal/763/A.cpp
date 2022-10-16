#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N;
int a[100005];
int U[100005], V[100005];
int can[2];
bool found;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ff(i, 1, N - 1) cin >> U[i] >> V[i];
    ff(i, 1, N) cin >> a[i];
    can[0] = 1, can[1] = 2;
    ff(i, 1, N - 1) if (a[U[i]] != a[V[i]]) {
        if (!found) can[0] = U[i], can[1] = V[i];
        found = 1;
        ff(t, 0, 1) if (can[t] != U[i] && can[t] != V[i]) can[t] = 0;
    }
    if (!can[0] && !can[1]) cout << "NO" << endl;
    else if (can[0]) cout << "YES" << endl << can[0] << endl;
    else cout << "YES" << endl << can[1] << endl;
    return 0;
}