#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
long long ans = 0, a[N], pre[N], suf[N];

struct trie {
    int cnt;
    trie *ch[2];
    
    trie() {
        cnt = 0;
        ch[0] = ch[1] = nullptr;
    }
} *rt = new trie();

void add(long long u, int v) {
    trie *cur = rt;
    for (int i = 60; i >= 0; i--) {
        int b = u >> i & 1;
        if (cur->ch[b] == nullptr) {
            cur->ch[b] = new trie();
        }
        cur = cur->ch[b];
        cur->cnt += v;
    }
}

long long get(long long u) {
    trie *cur = rt;
    long long ans = 0;
    for (int i = 60; i >= 0; i--) {
        int b = (u >> i & 1) ^ 1;
        if (cur->ch[b] == nullptr || cur->ch[b]->cnt == 0) {
            cur = cur->ch[b ^ 1];
        } else {
            cur = cur->ch[b];
            ans ^= (1LL << i);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
    }
    for (int i = 0; i <= n; i++) {
        add(pre[i], 1);
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] ^ a[i];
    }
    for (int i = n + 1; i >= 1; i--) {
        ans = max(ans, get(suf[i]));
        add(pre[i - 1], -1);
    }
    cout << ans;
}