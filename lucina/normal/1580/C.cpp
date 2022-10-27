#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
const int B = 64;
int n, m;
int cnt[512][512];
int x[nax];
int y[nax];
int ans[nax];
int lst[nax];
int to_add[nax];
int f[B];

void process(unsigned l, unsigned r, unsigned a, unsigned b) {
    while (l < r) {
        to_add[l] += 1;
        to_add[min(l + a, r)] -= 1;
        l += a + b;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> x[i] >> y[i];
    }

    int carry = 0;
    int cnt_train = 0;

    for (int l = 1; l <= m ; ++ l) {
        int op, id;
        cin >> op >> id;
        int a = x[id], b = y[id];
        if (op == 1) lst[id] = l;
        cnt_train += (op == 1) ? 1 : -1;
        ans[l] -= cnt_train;
        int c = a + b;
        if (c >= B) {
            if (op == 2) process(lst[id], l, a, b), lst[id] = m + 1;
            goto FOO;
        }

        if (op == 1) {
            cnt[c][l % c] += 1;
            cnt[c][(l + a) % c] -= 1;
        } else {
            cnt[c][lst[id] % c] -= 1;
            cnt[c][(lst[id] + a) % c] += 1;
        }

        if (op == 2 && ((l - lst[id] - 1) % c < a)) carry -= 1;

        FOO:;
        for (int i = 2 ; i < B ; ++ i) {
            f[i] = f[i] + 1 == i ? 0 : f[i] + 1;
            carry += cnt[i][f[i]];
        }
        ans[l] += carry;
    }

    for (int i = 1 ; i <= n ; ++ i) 
        if (lst[i] && lst[i] != m + 1 && x[i] + y[i] >= B) 
            process(lst[i], m + 1, x[i], y[i]);
    
    for (int i = 1 ; i <= m ; ++ i) {
        to_add[i] += to_add[i - 1];
        ans[i] += to_add[i];
        cout << -ans[i] << '\n';
    }
}
/*
    Good Luck
        -Lucina
*/