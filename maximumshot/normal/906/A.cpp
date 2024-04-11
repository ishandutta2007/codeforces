#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef long double ld;

#define info(x) cerr << #x << " = " << x << endl
#define vec vector
#define ALL(x) (x).begin(), (x).end()

int const inf = 1e9;
ll const inf64 = 1e18;

const int A = 26;
const int N = 1e5 + 5;

char s[N];

bitset< A > bs;
bitset< A > all;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    all.set();
    bs.set();

    int n;

    scanf("%d", &n);

    int res = 0;

    vec< pii > arr;

    for(int iter = 0;iter + 1 < n;iter++) {
        char type;
        scanf(" %c %s", &type, s);
        int l = strlen(s);
        bitset< A > cur;
        for(int i = 0;i < l;i++) {
            cur[s[i] - 'a'] = 1;
        }
        if(type == '!') {
            if(bs.count() == 1) {
                res++;
            }
            bs &= cur;
        }else if(type == '.') {
            bs &= (cur ^ all);
        }else {
            if(bs.count() == 1) {
                res++;
            }
            bs &= (all ^ cur);
        }
    }

    printf("%d\n", res);

    return 0;
}