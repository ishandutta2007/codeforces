#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

const int MX = 120000 * 30;

int go[MX][2];
int sz[MX];
int cc = 1;

void add(int x, int d) {
    int now = 0;
    for (int i = 26; i >= 0; --i) {
        sz[now] += d;
        int k = (x >> i) & 1;
        if (go[now][k])
            now = go[now][k];
        else
            now = go[now][k] = cc++;
    }
    sz[now] += d;
}

int get(int x, int l) {
    int ans = 0;
    int now = 0;
    for (int i = 26; i >= 0; --i) {
        int k = (x >> i) & 1;
        if ((l >> i) & 1) {
            if (go[now][k])
                ans += sz[go[now][k]];
            if (go[now][1 - k])
                now = go[now][1 - k];
            else
                break;
        }
        else {
            if (go[now][k])
                now = go[now][k];
            else
                break;
        }
    }
    return ans;
}


int main() {
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int t, x;
        scanf("%d%d", &t, &x);
        if (t == 1) {
            add(x, 1);
        }
        else if (t == 2) {
            add(x, -1);
        }
        else {
            int l;
            scanf("%d", &l);
            printf("%d\n", get(x, l));
        }
    }
    return 0;
}