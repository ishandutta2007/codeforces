#include <set>
#include <map>
#include <cmath>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
#include <unordered_set>
#include <chrono>

#define F first
#define S second

using namespace std;
typedef long long ll;
typedef long double ld;

const ll max_n = 100011;

int n, a[max_n];
pair<int, int> mx[max_n];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        //a[i] = 0;
        //if (i + 1 == n) a[i] = n - 1;
        mx[i] = make_pair(a[i], i);
        if (i) {
            mx[i] = max(mx[i], mx[i - 1]);
        }
    }
    ll ans = 0, sum = mx[n - 1].F + 1;
    for (int i = mx[n - 1].S; i < n; ++i) {
        ans += sum - a[i] - 1;
    }
    //for (int i =0 ; i < n; ++i) {
    //    cout << mx[i].F << " " << mx[i].S << "    ";
    //} cout << endl;
    for (int i = mx[n - 1].S; i; ) {
        // cout << i << " " << ans << endl;
        int nxt = mx[i - 1].S;
        int s = mx[i - 1].F;
        for (int q = i - 1; q >= nxt; --q) {
            if (sum > s + 1) --sum;
            ans += sum - a[q] - 1;
        }
        i = nxt;
    }
    cout << ans << endl;
    return 0;
}