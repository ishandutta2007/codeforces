#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5  + 10;
void rte () {
    exit(1);
}

void print_bin (int x) {
    if (x == 0) return ;
    print_bin(x / 2);
    printf("%d", x % 2);
}
int x;


map<int, int> stupid;

int main () {
    cin >> x;
   // int res = -1;


    stupid[1]  = 16;
    stupid[2]  = 2;
    stupid[4]  = 8;
    stupid[8]  = 4;
    stupid[16] = 1;
    stupid[32] = 32;

    int res = 0;

    for (int v = 0 ; v < 6 ; ++ v) {
        if (x >> v & 1) {
            res += stupid[1 << v];
        }
    }
    return !printf("%d\n", res);
    //if (x == 0) return !printf("0");


    if (x == 2) {
        res = 2;
    } else if (x == 5) {
        res = 24;
    } else if (x == 35) {
        res = 50;
    } else if (x == 0) {
        res = 0;
    } else if (x == 63) {
        res = 63;
    } else if (x == 1) {
        res = 16;
    } else if (x == 4) {
        res = 8;
    } else if (x == 8) {
        res = 8;
    } else throw;

    /// 63 answer is 63?
    /// 3^2 * 7?
    /// 35 answer is 50?
    /// 7 * 5 ?

    cout << res;

}