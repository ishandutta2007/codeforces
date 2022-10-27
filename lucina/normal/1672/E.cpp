#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;

int query(int x) {
    printf("? %d\n", x);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

int main() {
    scanf("%d", &n);
    /**
        for the maximum one
        equal to sum(l) + n - 1
        we want to break it to as many line as possible
        but anyway the answer is in range
        sum(l) to sum(l) + n - 1
        if we can get sum(l), it means that all values is equal
        so just divide 1, 2, ..., n should be enough?
    */
    int l = n, r = 2100 * 2100;
    int ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        int res = query(mid);
        if (res == 0) {
            l = mid + 1;
        } else if (res > 1) {
            l = mid + 1;
        } else if (res == 1) {
            ans = mid;
            r = mid - 1;
        }
    }
    int res = ans;
    /**
        this value exactly equal to
        sum(l) + (n - 1)
    */
    int sum = ans - (n - 1);
    for (int i = 2 ; i <= n ; ++ i) {
        int w = ans / i;
        int k = query(w);
        if (k > 0)
        {
            res = min(res, k * w);
        }
    }
    printf("! %d\n", res);
    fflush(stdout);
}
/**
    long time no rated round
*/