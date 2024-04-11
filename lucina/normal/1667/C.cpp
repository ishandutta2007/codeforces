#include<bits/stdc++.h>
using namespace std;

int main() {
    
    /**
        Let's say we place k queens
        the number of rows and column unoccupied is 2(n - k) - 1
        as they're all distince x - y
        so, k >= 2(n - k) - 1 is lower bound
        but we can actually build it as lower_bound by just running in the first k / 2 rows 
        with odd index, last k / 2 rows with even index
    */
    int n;
    cin >> n;
    int k = 1; while (k < 2 * (n - k) - 1) k += 1;
    cout << k << '\n';
    for (int i = 1, j = 1 ; i <= k ; ++ i) {
        cout << i << ' ' << j << '\n';
        j += 2;
        if (j > k) j = 2;
    }
}