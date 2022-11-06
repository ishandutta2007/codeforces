#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

long long n;
int cnt[N];
bool ignored[N];

bool lower(long long w, int p) {
    if (w > n) {
        return false;
    }
    long long val = n;
    long long val2 = w;
    for (int i = 2; i <= p; i++) {
        if (val2 <= 1e9) {
            val2 *= w;
            
        } else {
            val /= w;
        }
        if (val < val2) {
            return false;
        }
    }
    return true;
}

int main() {
    
    int t;
    scanf("%d", &t);
    
    for (int i = 2; i <= 64; i++) {
        if (cnt[i] == 0) {
            for (int j = i; j <= 64; j += i) {
                cnt[j]++;
            }
        }
        int w = i * i;
        while (w <= 64) {
            ignored[w] = true;
            for (int j = 2 * w; j <= 64; j += w) {
                ignored[j] = true;
            }
            w *= i;
        }
    }
    
    while (t--) {
        scanf("%lld", &n);
        long long ans = 0;
        int last = 1e9;
        for (int j = 2; j <= 64; j++) {
            if (ignored[j]) continue;
            int low = 2;
            int high = last;
            int res = pow(n, 1.0/j);
            while (pow(res + 1, j) <= n) res++;
            while (pow(res, j) > n) res--;
//             while (low <= high) {
//                 int mid = (low + high) / 2;
//                 if (lower(mid, j)) {
//                     res = mid;
//                     low = mid + 1;
//                 } else {
//                     high = mid - 1;
//                 }
//             }
            last = res;
            if (cnt[j] % 2 == 0) {
                ans -= res - 1;
            } else {
                ans += res - 1;
            }
        }
        printf("%lld\n", n - ans - 1);
    }

    return 0;
}