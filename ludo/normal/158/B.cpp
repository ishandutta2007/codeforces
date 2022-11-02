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

int n, totals[4] = {};

int ceil(int num, int div)
{
    if (num % div == 0) {
        return num / div;
    } else {
        return num / div + 1;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        totals[s - 1]++;
    }

//    for (int i = 0; i < 4; i++) {
//        cerr << totals[i] << " ";
//    }
//    cerr << endl;

    int ret = totals[3] + totals[2];
    if (totals[0] <= totals[2]) {
        ret += ceil(totals[1], 2);
    } else {
        // totals[0] > totals[2]
        totals[0] -= totals[2];

        if (totals[1] & 1) {
            ret += ceil(totals[1], 2);
            ret += totals[0] < 2 ? 0 : ceil(totals[0] - 2, 4);
        } else {
            ret += totals[1] / 2;
            ret += ceil(totals[0], 4);
        }
    }
    cout << ret << endl;
    return 0;
}