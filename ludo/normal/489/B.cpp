#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#include <vector>
#include <utility>

using namespace std;

#define MAX 100

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int sn[MAX], sm[MAX];

bool match(int l, int r)
{
    return (r - l) <= 1 && (l - r) <= 1;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n;
    for (int i = 0; i < n; i++) cin >> sn[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> sm[i];

    sort(sn, sn + n);
    sort(sm, sm + m);

//    for (int i = 0; i < n; i++) cout << sn[i] << " ";
//    cout << endl;
//    for (int i = 0; i < m; i++) cout << sm[i] << " ";
//    cout << endl;

    int matches = 0;

    int lp = 0, rp = 0;
    while (lp < n && rp < m) {
        // cerr << lp << ", " << rp << endl;
        if (match(sn[lp], sm[rp])) {
            matches++;
            lp++;
            rp++;
        } else if (sn[lp] < sm[rp]) {
            while (lp < n && sn[lp] < sm[rp] - 1) {
                lp++;
            }
        } else {
            while (rp < m && sm[rp] < sn[lp] - 1) {
                rp++;
            }
        }
    }
    cout << matches << endl;
    return 0;
}