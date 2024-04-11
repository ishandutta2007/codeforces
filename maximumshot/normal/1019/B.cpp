#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int ans(int i) {
    printf("! %d\n", i);
    fflush(stdout);
    exit(0);
}

int n;
int d[N];
int h[N];
int mem[N];
int tot = 60;

int ask(int i) {
    if(mem[i]) return h[i];
    if(!tot) ans(-1);
    mem[i] = 1;
    tot--;
    printf("? %d\n", i);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    h[i] = res;
    return res;
}

int get_d(int i) {
    assert(1 <= i && i <= n / 2 + 1);
    d[i] = ask(i + n / 2 <= n ? i + n / 2 : 1) - ask(i);
    return d[i];
}

int main() {

#ifdef debug
//    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    if((n/2) & 1) {
        ans(-1);
    }

    int bl = 1;
    int br = n / 2 + 1;
    int bm;
    int xle = get_d(bl);
    int xri = get_d(br);
    int xmd;

    if(!xle) ans(bl);
    if(!xri) ans(br);

    if(xle > 0 && xri > 0 || xle < 0 && xri < 0) ans(-1);

    while(br - bl > 1) {
        bm = (bl + br) / 2;
        xmd = get_d(bm);
        if(!xmd) ans(bm);
        if(xle < 0 && xmd > 0 || xle > 0 && xmd < 0) {
            br = bm;
        }else {
            bl = bm;
        }
    }

    if(!get_d(bl)) ans(bl);
    else if(!get_d(br)) ans(br);
    else ans(-1);

    return 0;
}