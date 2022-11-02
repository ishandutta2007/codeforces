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
#define MAX 100000

typedef long long ll;
typedef pair<int, int> pii;

int n, m, k, a[MAX], b[MAX], l[MAX];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i]; b[i]--;
    }

    for (int i = 0; i<n; i++) {
        l[a[i]] = i;
    }
    ll ret = m;
    for (int i = 0; i<m; i++) {
        int ind = l[b[i]];
        ret += ind / k;
        if (ind > 0) {
            swap(a[ind - 1], a[ind]);
            l[a[ind]] = ind;
            l[a[ind - 1]] = ind - 1;
        }

//        cerr << (ind / k) << ": ";
//        for (int j = 0; j < n; j++) {
//            cerr << (a[j]+1) << " ";
//        }
//        cerr << endl;
    }

    cout << ret << endl;


    return 0;
}