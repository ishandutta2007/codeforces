#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    int z = 0, d = 1;
    while (z < N) {
        ++d;
        int t = d;
        while (t % 5 == 0) ++z, t /= 5;
    }
    if (z > N) return cout << 0 << endl, 0;
    cout << 5 << endl;
    ff(rep, d, d + 4) cout << rep << " "; cout << endl;
    return 0;
}