#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, a[N];
char ch[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> ch;
        int k = 0, cnt = 0;
        for(int i = 0; i < n; i++) a[i] = 0;
        for(int i = 0; i < 2 * n; i++) {
            if (ch[i] == '(') {
                if (!a[k]) {
                    cnt++;
                    a[k] = 1;
                }
                k++;
            }
            else {
                a[k] = 0;
                k--;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}