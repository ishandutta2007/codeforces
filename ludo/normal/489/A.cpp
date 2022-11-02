#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MOD 1000000007
#define MAX 3000

typedef long long ll;
typedef pair<int, int> pii;

int n, a[MAX];
int nswaps = 0;
pii swaps[MAX];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        int min_ind = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_ind]) {
                min_ind = j;
            }
        }
        if (min_ind != i) {
            swaps[nswaps++] = make_pair(i, min_ind);
            a[min_ind] = a[i];
        }
    }

    cout << nswaps << endl;
    for (int i = 0; i < nswaps; i++) {
        cout << swaps[i].first << " " << swaps[i].second << endl;
    }
    return 0;
}