#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 1.5e5 + 10;
struct fwt {
    ll s[N];
    void add(int x, int v) {
        for(; x < N; x += x & (-x)) s[x] += v;
    }
    ll ask(int x) {
        int sum = 0;
        for(; x > 0; x -= x & (-x)) sum += s[x];
        return sum;
    }
}t1, t2;
int n, a[N], id[N], ord[N];
ll sum[N];
int stk1[N], stk2[N];
void divide(int l, int r) {
    if(l == r) {
        id[l] = l;
        return;
    }
    int mid = (l + r) / 2;
    divide(l, mid), divide(mid + 1, r);
    merge(id + l, id + mid + 1, id + mid + 1, id + r + 1, ord + l, [&](int x, int y) {
        return a[x] > a[y]; 
    });
    for(int i = l; i <= r; i++) id[i] = ord[i];
    for(int i = l; i <= mid; i++) t2.add(i, 1);
    int top1 = 0, top2 = 0;
    for(int i = l; i <= r; i++) {
        int x = id[i];
        if(x > mid) {
            while(top2 > 0 && stk2[top2] > x) top2--;
            int up = n + 1;
            if(top2) up = a[stk2[top2]];
            stk2[++top2] = x;
            int p = lower_bound(stk1 + 1, stk1 + top1 + 1, up, [&](int x, int y) {return a[x] >= y; }) - stk1;
            t1.add(p, 1);
            int lst = p <= top1 ? stk1[p] : l - 1;
            sum[up] -= t2.ask(mid) - t2.ask(lst);
        } else {
            int lst = l - 1;
            while(top1 > 0 && stk1[top1] < x) {
                sum[a[stk1[top1]]] -= (t2.ask(stk1[top1]) - t2.ask(lst)) * t1.ask(top1);
                lst = stk1[top1];
                top1--;
            }
            if(top1 > 0) sum[a[stk1[top1]]] -= (t2.ask(x) - t2.ask(lst)) * t1.ask(top1);
            top1++;
            t1.add(top1, -t1.ask(top1));
            t2.add(x, -1);
            stk1[top1] = x;
        }
    }
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) sum[i] = i;
    divide(1, n);
    reverse(a + 1, a + n + 1);
    divide(1, n);
    for(int i = 1; i <= n; i++) sum[i] += sum[i - 1];
    for(int i = 1; i <= n; i++) cout << sum[i] << endl;
    return 0;
}