#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 3e5 + 5;
const int LOG = 30;

int n;
int a[N];
int p[N];
int nxt[N * LOG][2];
int cnt[N * LOG];
int sz = 1;

void add_value(int x) {
    int v = 0;
    cnt[v]++;
    for(int i = LOG - 1;i >= 0;i--) {
        int k = (x >> i) & 1;
        if(nxt[v][k] == -1) {
            nxt[v][k] = sz++;
        }
        v = nxt[v][k];
        cnt[v]++;
    }
}

void del_value(int x) {
    int v = 0;
    cnt[v]--;
    for(int i = LOG - 1;i >= 0;i--) {
        int k = (x >> i) & 1;
        v = nxt[v][k];
        cnt[v]--;
    }
}

int get_min(int x) {
    int v = 0;
    int res = 0;
    for(int i = LOG - 1;i >= 0;i--) {
        int k = (x >> i) & 1;
        if(nxt[v][k] != -1 && cnt[nxt[v][k]] > 0) {
            v = nxt[v][k];
        }else {
            v = nxt[v][k ^ 1];
            res |= (1 << i);
        }
    }
    return res;
}

int main() {

    fill((int*)nxt, (int*)nxt + N * LOG * 2, -1);

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &p[i]);
    }

    for(int i = 1;i <= n;i++) {
        add_value(p[i]);
    }

    for(int i = 1;i <= n;i++) {
        int x = get_min(a[i]);
        printf("%d ", x);
        del_value(a[i] ^ x);
    }

    printf("\n");

    return 0;
}