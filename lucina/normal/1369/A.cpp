#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int main () {
    int T;

    cin >> T;

    for (; T -- ;) {
        int n;
        cin >> n;
        puts(n % 4 == 0 ? "YES" : "NO");
    }
}
/*4
3
4
12
1000000000

    Leon is the best girl in A17.
*/