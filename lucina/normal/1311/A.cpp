#include<bits/stdc++.h>
using namespace std;

int main () {
    int T;
    for (scanf("%d", &T) ; T -- ;) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a == b) {
            puts("0");
        }
        else if (a < b) {
            puts( ((a ^ b) & 1) ? "1" : "2");
        }
        else {
            puts( ((a ^ b) & 1) ? "2" : "1");
        }
    }
}