#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MAXH 150000

typedef long long ll;
typedef pair<int, int> pii;

int h[MAXH];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++)cin>>h[i];

    int sum = 0;
    int besti = 0, bestv = 0;

    for (int i =0; i < k; i++) {
        sum += h[i];
    }
    bestv = sum;

//    cerr << "sum " << besti << " = " << bestv << endl;

    for (int i = 1; i + k <= n; i++) {
        sum = sum - h[i - 1] + h[i + k - 1];
        if (sum < bestv) {
            bestv = sum;
            besti = i;
        }
//        cerr << "sum " << i << " = " << sum << endl;
    }
    cout << (besti + 1) << endl;
    return 0;
}