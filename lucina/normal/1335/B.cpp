#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int main () {
    int T;


    for (cin >> T ; T -- ; ) {
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);

        for (int i = 0 ; i < n ; ++ i) {
            printf("%c", (i % b) + 'a');
        }
        printf("\n");
    }
}