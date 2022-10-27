#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n;
int a[nax];
int main() {
    int T;
    
    for (cin >> T ; T -- ;) {
        cin >> n;
        for (int i = 1 ; i <= n ; ++ i)
            cin >> a[i];
        sort(a + 1, a + 1 + n);
        cout << a[n] + a[n - 1] << '\n';
    }
}