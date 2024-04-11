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

#define INF 2147483647
#define MOD 1000000007

#define MAXN 6
#define MAXK 4

typedef long long ll;
typedef pair<int, int> pii;

//int factorials[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

int n, k, a[MAXN];

double ret = 0.0;

void try_things(int curk, int ways)
{
    if (curk == k) {
        int invs = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] > a[j]) {
                    invs++;
                }
            }
        }
//        cout << " = " << invs << ", " << ways << endl;
        ret += ((double)invs) / ways;
    } else {
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {

//                cout << "swap " << l << " with " << r << endl;
//                for (int i = 0; i < n; i++) cout << a[i] << ",";
//                cout << endl;

                for (int i = l; 2 * i < l + r; i++) {
                    int tmp = a[i];
                    a[i] = a[r + l - i];
                    a[r + l - i] = tmp;
                }

//                for (int i = 0; i < n; i++) cout << a[i] << ",";
//                cout << endl ;

                try_things(curk + 1, ways * n * (n + 1) / 2);
                for (int i = l; 2 * i < l + r; i++) {
                    int tmp = a[i];
                    a[i] = a[r + l - i];
                    a[r + l - i] = tmp;
                }
//                for (int i = 0; i < n; i++) cout << a[i] << ",";
//                cout << endl << endl;
            }
        }
    }
}



int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        a[i]--;
    }

    try_things(0, 1);

    cout.precision(12);
    cout << fixed << ret << endl;

    return 0;
}