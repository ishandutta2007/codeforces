
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 5e5 + 5;
int n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int k = 2 * i; k <= n; k += i) {
            a[k] = i;
        }
    }
    sort(a, a + n + 1);
    for(int i = 2; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}