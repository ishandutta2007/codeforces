
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// for a pair a[i], a[n - i + 1]
// costs one operation if x != a[i] + a[n - i + 1]
// costs another operation if x < min(a[i], a[n - i + 1]) + 1 or x > max(a[i], a[n - i + 1]) + k
// increase subarray by value
// try each x from 2 to 2k

const int N = 2e5 + 5, K = 2e5 + 5;
int t, n, k, a[N];
int tree[2 * K];

int getSum(int i) {
    int s = 0;
    while(i >= 1) {
        s += tree[i];
        i -= i & -i;
    }
    return s;
}
void add(int i, int x) {
    while(i < 2 * k + 5) {
        tree[i] += x;
        i += i & -i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        fill(tree, tree + 2 * k + 5, 0);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        // 1 2 1 2
        //  1 2 3 4 5 6
        // [2 0 0 0 2 2]
        map<int, int> ma;
        for(int i = 0; i < n / 2; i++) {
            int A = a[i], B = a[n - i - 1];
            ma[A + B]++;
            if(A > B) swap(A, B);
            add(1, 1);
            add(A + 1, -1);
            add(B + k + 1, 1);
        }
        int ans = n;
        for(int x = 2; x <= 2 * k; x++) {
            ans = min(ans, getSum(x) + (n / 2) - ma[x]);
        }
        cout << ans << endl;
    }
}