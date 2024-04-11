#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 7e6 + 5;

struct node {
    int nxt[2];
    int sum;
};

node a[N];
int sz = 2;

void add(int x, int val) {
    int cur = 1;
    a[cur].sum += val;
    for (int i = 30; i >= 0; i--) {
        int bit = (x >> i) & 1;
        if (a[cur].nxt[bit] == 0) {
            a[cur].nxt[bit] = sz;
            sz++;
        }
        cur = a[cur].nxt[bit];
        a[cur].sum += val;
    }
}

int get(int x) {
    int res = 0, cur = 1;
    for (int i = 30; i >= 0; i--) {
        int bit = (x >> i) & 1;
        if (a[cur].nxt[!bit] != 0 && a[a[cur].nxt[!bit]].sum > 0)
            cur = a[cur].nxt[!bit], res += (1 << i);
        else
            cur = a[cur].nxt[bit];
    }
    return res;
}



signed main()
{
    add(0, 1);
    int q;
    cin >> q;
    while (q--) {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+')
            add(x, 1);
        if (c == '-')
            add(x, -1);
        if (c == '?')
            cout << get(x) << "\n";
    }
    return 0;
}