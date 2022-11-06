#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, x[N];

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
    }

    sort(x + 1, x + 1 + n);

    int low = 1;
    int high = x[n] - x[1];
    int res = high;
    while (low <= high) {
        int mid = ((long long)low + high) / 2;
        cerr << mid << endl;
        int beg = 1;
        bool good = false;
        for (int i = 2; i <= n; i++) {
            while (beg <= i - 1 && x[i] - x[beg] > mid) {
                beg++;
            }
            if (beg - 1 + (n - i) <= i - beg) {
                good = true;
                break;
            }
        }
        if (good) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", res);
    return 0;
}