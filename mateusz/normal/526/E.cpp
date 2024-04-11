#include <bits/stdc++.h>

using namespace std;
const int N = 1000005;
int tab[N];
int edge[N];
bool odw[N];
int n, q;
int query(long long w) {
    long long p = tab[n];
    int last = n;
    for(int i = 1; i <= n; i++) {
        odw[i] = false;
    }
    bool przeskok = false;
    for(int i = 1; i < n; i++) {
        if(p + tab[i] <= w) {
            przeskok = true;
            last = i;
            p += tab[i];
        } else {
            break;
        }
    }
    edge[n] = last + 1;
    if(edge[n] > n) {
        edge[n] -= n;
    }
    for(int i = n - 1; i >= 1; i--) {
        while(last + (przeskok * n) - n >= i || p + tab[i] > w) {
            p -= tab[last];
            last--;
            if(last == 0) {
                przeskok = false;
                last = n;
            }
        }
        p += tab[i];
        edge[i] = last + 1;
        if(edge[i] > n) {
            edge[i] -= n;
        }
    }
    int v = 1;
    while(odw[v] == false) {
        odw[v] = true;
        v = edge[v];
    }
    int ret = 0;
    w = v;
    przeskok = false;
    int pp = 0;
    while(w + pp * n < v + n) {
        ret++;
        if(edge[w] <= w) {
            pp++;
        }
        w = edge[w];
    }
    return ret;
}

int main() {
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }
    while(q--) {
        long long x;
        scanf("%I64d", &x);
        printf("%d\n", query(x));
    }
    return 0;
}