#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

int n, q;
ll m[max_n];
ll l;
int ans = 0;

void proc(int ind, int d) {
    if (m[ind] <= l && m[ind] + d <= l) {
        m[ind] += d;
        return;
    }
    if (m[ind] > l) {
        m[ind] += d;
        return;
    }
    m[ind] += d;
    if (n == 1) {
        ++ans;
        return;
    }
    if (ind == 0) {
        if (m[ind + 1] > l) {
            return;
        } else {
            ++ans;
            return;
        }
    }

    if (ind == n - 1) {
        if (m[ind - 1] > l) {
            return;
        } else {
            ans++;
            return;
        }
    }
    if (m[ind - 1] > l && m[ind + 1] > l) {
        --ans;
        return;
    }
    if (m[ind - 1] <= l && m[ind + 1] <= l) {
        ++ans;
        return;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> q >> l;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        //m[i] = a;
        proc(i, a);
    }
    while (q--) {
        int t, p, d;
        scanf("%d", &t);
        if (t == 0) {
            printf("%d\n", ans);
        } else {
            //cout << "A" << endl;
            scanf("%d%d", &p, &d);
            --p;
            proc(p, d);
        }
    }

    return 0;
}