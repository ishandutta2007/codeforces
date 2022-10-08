
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// ask on the first k elements
// let P be the position of the mth smallest number in this set
// There ask queries by replacing one of the first k elements with the k+1st element
// when replacing index P with k+1, does value increase?
// if so, a[k+1] > a[P]. Otherwise, a[k+1] < a[P]

// Suppose a[k + 1] < a[P]
// when replacing i with k+1, is answer still P? If so, a[i] < a[k + 1]. Else, a[i] > a[k + 1]

int a, b;
int n, k;

pair<int, int> query(vector<int> v) {
    cout << "? ";
    for(int x : v) {
        cout << x << " ";
    }
    cout << endl;
    cin >> a >> b;
    return {a, b};
}
void solve(int m) {
    cout << "! " << m << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    vector<int> v;
    for(int i = 1; i <= k; i++) v.push_back(i);
    auto [P, V] = query(v);
    bool b = false;
    int cnt = 0;
    for(int i = 0; i < k; i++) {
        v[i] = k + 1;
        auto [p, val] = query(v);
        if(i + 1 == P) {
            b = (val < V);
        }else {
            cnt += (p == P);
        }
        v[i] = i + 1;
    }
    solve(b ? cnt + 1 : k - cnt);
}