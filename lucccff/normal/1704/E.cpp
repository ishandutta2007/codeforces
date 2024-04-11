#include <bits/stdc++.h>
#include <quadmath.h>
#include <math.h> 
using namespace std;

const int N = 1e3 + 10;
const int P = 998244353;

int n, m;
int a[N], b[N];
vector <int> edge[N];
int pre[N], nxt[N];
int st[N];
int ans[N];
__float128 la[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            edge[i].clear();
            pre[i] = 0;
            cin >> a[i];
            ans[i] = a[i];
            la[i] = a[i];
            b[i] = 0;
        }
        int k, l;
        for(int i = 0; i < m; i++) {
            cin >> k >> l;
            pre[l]++;
            edge[k].push_back(l);
        }
        int x = 0, y = 0;
        for(int i = 1; i <= n; i++) {
            if (!pre[i]) {
                st[y++] = i;
            }
        }
        int key = 0;
        while (x < y) {
            key++;
            int z = y;
            for(int i = x; i < y; i++) {
                for(auto q : edge[st[i]]) {
                    ans[q] += ans[st[i]];
                    la[q] += la[st[i]];
                    ans[q] %= P;
                    pre[q]--;
                    if (!pre[q]) {
                        st[z++] = q;
                    }
                }
            }
            x = y;
            y = z;
        }
        for(int i = 0; i < n; i++) {
            for(int j = n - 1; j >= 0; j--) {
                int k = st[j];
                if (!a[k]) {
                    if (!(la[k] < 1e5 && ans[k] + b[k] <= i)) b[k]++;
                }
                else {
                    a[k]--;
                    for(auto q : edge[k]) {
                        a[q]++;
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            ans[i] += b[i];
            ans[i] %= P;
            la[i] += b[i];
        }
        __float128 mx = 0;
        k = -1;
        for(int i = 1; i <= n; i++) {
            if (mx < la[i]) {
                mx = la[i];
                k = i;
            }
        }
        cout << ans[k] << endl;
    }
    return 0;
}