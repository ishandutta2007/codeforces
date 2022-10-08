
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 1e5 + 5;
int n;
ll a[MAX_N];

// 0 1 2 3 ... (n - 1)
// is a losing position.

// if a position has all distinct numbers, it will simply be reduced to this position.
// if there is exactly one pair, the optimal first move is to split it as long as it
// does not create a new pair. If there are multiple pairs (or a triplet), the position
// is losing from the start.

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int pairs = 0;
    int csl = a[0] % 2;
    for(int i = 1; i < n; i++) {
        csl = (csl + a[i] + i) % 2;
        if(a[i] == a[i - 1]) {
            pairs++;
            if((i > 1 && a[i - 2] == a[i] -  1) || a[i] == 0) {
                // e.g. 2 3 3 is a losing position, because we cannot
                // remove the pair without creating another pair.
                pairs++;
            }
        }
    }
    if(pairs > 1 || csl == 0 || a[n - 1] == 0) {
        cout << "cslnb" << endl;
    }else {
        cout << "sjfnb" << endl;
    }
}