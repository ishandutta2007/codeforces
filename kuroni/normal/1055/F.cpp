#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 5, LG = 62;

int n, p, cnt, opt[N], cur[N];
long long k, ans = 0, a[N];

struct trie {
    int mem, ch[2];
    
    trie(int l = 0, int r = 0) : mem(0) {
        ch[0] = l;
        ch[1] = r;
    }
} tr[2][N], *now = tr[0], *lst = tr[1];

int access(int cur, int u, bool f = false) {
    if (!f && lst[cur].ch[u] == 0) {
        lst[cur].ch[u] = cnt;
        now[cnt++] = trie();
    }
    return lst[cur].ch[u];
}

template<typename T>
void read(T &num) { 
    num = 0;
    for (char c = getchar(); c >= '0' && c <= '9'; c = getchar()) {
        num = num * 10 + c - '0';
    }
}

int main() {
    read(n); read(k); --k;
    fill(cur + 1, cur + n + 1, 1);
    fill(opt + 1, opt + n + 1, 1);
    for (int i = 2; i <= n; i++) {
        read(p); read(a[i]);
        a[i] ^= a[p];
    }
    for (int b = LG - 1; b >= 0; b--) {
        swap(now, lst);
        cnt = 0;
        now[cnt++] = trie();
        now[cnt++] = trie();
        for (int i = 1; i <= n; i++) {
            cur[i] = access(cur[i], a[i] >> b & 1);
            now[cur[i]].mem++;
        }
        long long nxt = 0;
        for (int i = 1; i <= n; i++) {
            nxt += now[access(opt[i], a[i] >> b & 1, true)].mem;
        }
        if (nxt <= k) {
            ans ^= (1LL << b);
            k -= nxt;
            for (int i = 1; i <= n; i++) {
                opt[i] = access(opt[i], (a[i] >> b & 1) ^ 1, true);
            }
        } else {
            for (int i = 1; i <= n; i++) {
                opt[i] = access(opt[i], a[i] >> b & 1, true);
            }
        }
    }
    cout << ans;
}