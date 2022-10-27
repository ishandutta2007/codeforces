#include<bits/stdc++.h>
using namespace std;
int n;
int a[500];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        cin >> n;
        for (int i = 1 ; i <= n ; ++ i) {
            cin >> a[i];
        }
        cout << a[1] << '\n';
    }
}