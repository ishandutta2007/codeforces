# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

bool a[100010];
bool c[100010];

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x > 1) {
            if(a[x - 1]) c[x] = true;
        }
        a[x] = true;
    }
    int len = 1, ans = 1;
    for(int i = 2; i <= n; ++i) {
        if(c[i]) {
            ++len;
            if(len > ans) {
                ans = len;
            }
        } else len = 1;
    }
    cout << n - ans << endl;
}