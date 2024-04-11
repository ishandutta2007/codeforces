# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

char a[100008];

long long f[100008][16];

int get_next(int i,int mask,char c) {
    int ret = 0;
    if(mask & 1) {
        if(a[i] == c) ret |= 1;
        if(a[i + 1] == c) ret |= 4;
        ret |= 2 | 8;
    }
    if(mask & 2) {
        if(a[i - 1] == c) ret |= 2 | 8;
    }
    if(mask & 4) {
        if(a[i + 1] == c) ret |= 4;
        ret |= 8;
    }
    if(mask & 8) {
        if(a[i] == c) ret |= 8;
    }
    return ret;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", a);
    f[0][1] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < (1<<4); ++j) if(f[i][j]) {
            for(char c = 'a'; c < 'a' + m; ++c) {
                int k = get_next(i, j, c);
                f[i + 1][k] += f[i][j];
            }
        }
    }

    long long ans = 0;
    for(int j = 8; j < 16; j += 2)
        ans += f[n][j];
    cout << ans << endl;
    return 0;
}