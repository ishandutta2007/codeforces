# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;
typedef long long ll;

char word[64][32];

inline int __count(ll k) {
    int ret = 0;
    while(k) k&=k-1, ++ret;
    return ret;
}

double f[(1<<20)+20];
ll a[(1<<20)+20];

int main() {
    int m; scanf("%d", &m);
    for(int i = 0; i < m; ++i) 
        scanf("%s", word[i]);
    int n = strlen(word[0]);
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < i; ++j) {
            ll diff = 0;
            for(int k = 0; k < n; ++k)
                if(word[i][k] == word[j][k])
                    diff |= (1<<k);
            a[diff] |= (1ll<<i) | (1ll<<j);
        }
    }
    for(int i = (1<<n) - 1; i>=0; --i) {
        f[i] = 0;
        int cnt = 0;
        for(int j = 0; j < n; ++j)
            if(i & (1<<j)) {
                a[i^(1<<j)] |= a[i];
            } else {
                f[i] += f[i^(1<<j)];
                cnt += 1;
            }
        if(cnt) f[i] /= cnt;
        f[i] += (double)__count(a[i]) / m;
    }
    printf("%.12lf\n", f[0]);
}