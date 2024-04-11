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
#define MAX 500000

typedef long long ll;
typedef pair<int, int> pii;

string str;
bool v[MAX];
int st[MAX + 1], n;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> str;
    n = str.size();

    st[0] = 0;
    for (int i = 0; i < n; i++) {
        v[i] = (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'Y');
        st[i + 1] = st[i] + v[i];
    }

    cout.precision(10);
    cout << fixed;

//    if (st[n] == n) {
//        cout << (n * (n + 1) / 2) << endl;
//        return 0;
//    }

    double ret = 0;

#if 0
    double ret2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ret2 += ((double) st[j + 1] - st[i]) / (j - i + 1);
        }
    }
    cout << ret2 << endl;
#endif

    ll tot = st[n] - st[0];

    ret += tot;

    for (int i = 1; i < n; i++) {
        tot += st[n - i] - st[i];
        ret += ((double) tot) / (i + 1);
    }

    cout << ret << endl;
    return 0;
}