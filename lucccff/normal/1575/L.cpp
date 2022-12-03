#include <iostream>
#include <cstring>
#include <cstdio>

const int N = 2e5 + 7;

using namespace std;

int n, cnt;
int a[N], mxa;
int ch[N * 200][2];
int mx[N * 200];

void update(int rt, int x, int y) {
    int l = 1, r = n;
    while (l < r) {
        mx[rt] = max(mx[rt], y);
        int mid = l + r >> 1;
        if (x <= mid) {
            if (!ch[rt][0]) ch[rt][0] = ++cnt;
            rt = ch[rt][0];
            r = mid;
        }
        else {
            if (!ch[rt][1]) ch[rt][1] = ++cnt;
            rt = ch[rt][1];
            l = mid + 1;
        }
    }
    mx[rt] = max(mx[rt], y);
}

int query(int rt, int x, int l = 1, int r = n) {
    if (!rt) return 0;
    if (r <= x) return mx[rt];
    int mid = l + r >> 1;
    if (x <= mid) return query(ch[rt][0], x, l, mid);
    return max(mx[ch[rt][0]], query(ch[rt][1], x, mid + 1, r));
}

void add(int x, int y, int z) {
    do update(x, y, z); while ((x += x & -x) <= mxa);
}

int Mx(int x, int y) {
    int ans = 0;
    do ans = max(ans, query(x, y)); while (x -= x & -x);
    return ans;
}

int main() {
    int ans = 0;
    cin >> n;
    cnt = n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        mxa = max(mxa, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        if (x > i) continue;
        int y = i - x + 1;
        int z = Mx(x - 1, y) + 1;
        add(x, y, z);
        ans = max(ans, z);
    }
    cout << ans << endl;

    return 0;
}