#include<bits/stdc++.h>
using namespace std;


int main () {
    int T;

    for (scanf("%d", &T) ; T -- ; ) {
        int a, b;
        scanf("%d %d", &a, &b);

        int ret = a % b;
        printf("%d\n", (b - ret) % b);

    }
}