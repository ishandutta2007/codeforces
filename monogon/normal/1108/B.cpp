
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 130;
int n, a[N];

bool check(int x, int y) {
    vector<int> v;
    for(int i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            v.push_back(i);
            if(i * i != x) {
                v.push_back(x / i);
            }
        }
    }
    for(int j = 1; j * j <= y; j++) {
        if(y % j == 0) {
            v.push_back(j);
            if(j * j != y) {
                v.push_back(y / j);
            }
        }
    }
    if((int) v.size() != n) return false;
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        if(v[i] != a[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(check(a[i], a[j])) {
                cout << a[i] << " " << a[j] << "\n";
                return 0;
            }
        }
    }
    assert(false);
}