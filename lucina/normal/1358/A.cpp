#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;


int main () {
    int t;

    for (cin >> t ; t -- ; ) {
        int n, m;

        cin >> n >> m;
        n *= m;
        printf("%d\n", (n + 1) / 2);
    }
}
/*
    Long time no see...
        CF round
*/