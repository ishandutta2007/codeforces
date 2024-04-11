#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N;
int totalChange;
int minPossible = -1000000000, maxPossible = 1000000000;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int x, d;
    ff(i, 1, N) {
        cin >> x >> d;
        if (d == 1) {
            minPossible = max(minPossible, 1900 - totalChange);
        }
        else {
            maxPossible = min(maxPossible, 1899 - totalChange);
        }
        totalChange += x;
    }
    if (minPossible > maxPossible) cout << "Impossible" << endl;
    else if (maxPossible == 1000000000) cout << "Infinity" << endl;
    else cout << maxPossible + totalChange << endl;
    return 0;
}