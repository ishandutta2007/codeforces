#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 50005;

int n, start, x;
int Next[N];
int Value[N];

void ask(int i) {
    printf("? %d\n", i);
    fflush(stdout);
    scanf("%d %d", &Value[i], &Next[i]);
}

inline int NextRand() {
    return ((rand() << 16) | rand());
}

int main() {

#ifdef debug
//    freopen("input.txt", "r", stdin);
#endif

    srand(time(0));

    scanf("%d %d %d", &n, &start, &x);

    int best = start;
    int bvalue = -1;

    for(int i = 1;i <= 1000;i++) {
        int j = NextRand();
        j = (j % n + n) % n + 1;
        printf("? %d\n", j);
        fflush(stdout);
        int jvalue;
        scanf("%d %d", &jvalue, &j);
        if(jvalue < x && jvalue >= bvalue) {
            bvalue = jvalue;
            best = j;
        }
    }

    while(bvalue < x) {
        if(best < 0) {
            printf("! -1\n");
            fflush(stdout);
            return 0;
        }
        printf("? %d\n", best);
        fflush(stdout);
        scanf("%d %d", &bvalue, &best);
    }

    printf("! %d\n", bvalue);

    fflush(stdout);

    return 0;
}