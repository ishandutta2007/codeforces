#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n, k;

    cin >> n >> k;

    vec< int > arr;

    for(int x = 2;x * x <= n;x++) {
        if(n % x) continue;
        arr.push_back(x);
        n /= x;
        x--;
    }

    if(n > 1) {
        arr.push_back(n);
    }

    if((int)arr.size() < k) {
        cout << "-1\n";
        return 0;
    }

    while(k > 1) {
        cout << arr.back() << " ";
        arr.pop_back();
        k--;
    }

    int vl = 1;

    for(int x : arr) vl *= x;

    cout << vl << "\n";

    return 0;
}