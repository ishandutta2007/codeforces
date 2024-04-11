#include <bits/stdc++.h>
using namespace std;
int a[6];
int main() {
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 6; i++) cin >> a[i];
    sort(a, a + 6);
    do  {
        if (a[0] + a[1] + a[2] == a[3] + a[4] + a[5]) {
            cout << "YES";
            return 0;
        }
    } while(next_permutation(a, a + 6));
    cout << "NO";
}