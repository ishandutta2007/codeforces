#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m, l, hair[N];
int type, pos, d;
int ans;

int main() {

    scanf("%d %d %d", &n, &m, &l);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &hair[i]);
        if (hair[i] > l) {
            ans++;
            if (hair[i - 1] > l) {
                ans--;
            }
        }
    }
    
    for (int i = 1; i <= m; i++) {
        scanf("%d", &type);
        if (type == 0) {
            printf("%d\n", ans);
        } else {
            scanf("%d %d", &pos, &d);
            if (hair[pos] > l) continue;
            hair[pos] += d;
            if (hair[pos] > l) {
                ans++;
                if (hair[pos - 1] > l) {
                    ans--;
                }
                if (hair[pos + 1] > l) {
                    ans--;
                }
            }
        }
    }
    
    return 0;
}