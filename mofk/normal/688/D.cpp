#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, K;
int d[1000005];
int a[1000005];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie();
    cin >> N >> K;
    ff(i, 1, 1000000) d[i] = i;
    ff(i, 2, 1000) if (d[i] == i) ff(j, i, 1000000 / i) d[i*j] = i;
    int x;
    ff(i, 1, N) {
        cin >> x;
        while (x > 1) {
            int t = d[x], c = 0;
            while (x % t == 0) { x /= t; ++c; }
            a[t] = max(a[t], c);
        }
    }
    while (K > 1) {
        --a[d[K]]; K /= d[K];
    }
    ff(i, 1, 1000000) if (a[i] < 0) return cout << "No\n", 0;
    cout << "Yes\n";
    return 0;
}