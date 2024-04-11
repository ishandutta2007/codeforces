#include <bits/stdc++.h>

using namespace std;
int A, B, n, l, t, m;
long long F(int x) {
    return (long long)A + (long long)(x - 1) * B;
}

long long aryt(int w) {
    return (F(1) + F(w)) * w / 2; 
}

long long suma(int a, int b) {
    return aryt(b) - aryt(a - 1);
}

long long ceil(long long n, long long k) {
    return (n + k - 1) / k;
}

int main() {
    scanf("%d %d %d", &A, &B, &n);
    while(n--) {
        scanf("%d %d %d", &l, &t, &m);
        if(F(l) > t) {
            printf("-1\n");
            continue;
        }
        int poc = l;
        int kon = l + 1000000;
        int ret = poc;
        while(poc <= kon) {
            int sr = (poc + kon) / 2;
            if(max(F(sr), ceil(suma(l, sr), min(m, sr - l + 1))) <= t) {
                ret = sr;
                poc = sr + 1;
            } else {
                kon = sr - 1;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}