#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5  + 10;
void rte () {
    exit(1);
}

int main () {
    int x;
    cin >> x;
    for (int j = 2 ; j <= x ; ++ j) {
        if (x % j == 0) {
            return !printf("%d%d\n", j, x / j);
        }
    }

    throw;
}