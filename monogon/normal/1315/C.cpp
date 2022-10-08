
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 105;
int n, t, a[2 * N], b[N], cnt[2 * N];

bool check() {
    int c = 0, b = 0;
    for(int i = 2 * n; i >= 1; i--) {
        c += (cnt[i] > 0);
        b += (cnt[i] == 0);
        if(c > b) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        bool flag = false;
        fill(cnt, cnt + 2 * N, 0);
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            a[2 * i] = b[i];
            if(b[i] < 1 || b[i] > 2 * n || cnt[b[i]] > 0) flag = true;
            else cnt[b[i]] = 1;
        }
        if(flag || !check()) {
            cout << -1 << endl;
            continue;
        }
        for(int i = 1; i < 2 * n; i += 2) {
            cnt[a[i - 1]] = -1;
            for(int j = a[i - 1] + 1; j <= 2 * n; j++) {
                if(cnt[j] == 0) {
                    cnt[j] = -1;
                    if(check()) {
                        a[i] = j;
                        break;
                    }
                    cnt[j] = 0;
                }
            }
            assert(a[i] != 0);
        }
        for(int i = 0; i < 2 * n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}