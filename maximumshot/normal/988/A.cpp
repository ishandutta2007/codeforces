#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
// #include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, k;

    cin >> n >> k;

    vec< int > a(105, -1);

    for(int x, i = 0;i < n;i++) {
        cin >> x;
        a[x] = i + 1;
    }

    vec< int > arr;

    for(int i = 0;i < 105;i++) {
        if(a[i] != -1) {
            arr.push_back(a[i]);
        }
    }

    if((int)arr.size() < k) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    for(int i = 0;i < k;i++) {
        cout << arr[i] << " \n"[i + 1 == k];
    }

    return 0;
}