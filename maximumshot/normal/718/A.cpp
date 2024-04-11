#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 200005;


bool solve() {

    int n, t;
    char s[N];

    scanf("%d %d %s", &n, &t, s);

    int ptr;

    for(int i = 0;i < n;i++) {
        if(s[i] == '.') ptr = i;
    }

    for(int j = ptr + 1;j < n;j++) {
        if(s[j] >= '5') {
            int it = j - 1;
            while(it > ptr && s[it] == '4' && --t > 0) it--;
            if(it > ptr) {
                s[it]++;
                for(int iter = 0;iter <= it;iter++)
                    printf("%c", s[iter]);
                printf("\n");
                return true;
            }else {
                if(t > 0) {
                    it = ptr - 1;
                    while (it >= 0 && s[it] == '9') s[it--] = '0';
                    if (it >= 0) {
                        s[it]++;
                    } else {
                        printf("1");
                    }
                }
                for(int iter = 0;iter < ptr;iter++) printf("%c", s[iter]);
                printf("\n");
                return true;
            }
        }
    }

    printf("%s\n", s);

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}