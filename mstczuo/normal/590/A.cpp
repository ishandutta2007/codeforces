# include <iostream>
# include <cstdio>
# include <cstring>
# include <set>

using namespace std;

int a[500000+10];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    a[0] = a[1];
    a[n + 1] = a[n];

    int l = 1, r, ans = 0;
    while(l <= n) {
        while(l <= n && a[l] == a[l+1]) ++l;
        r = l;
        while(r <= n && a[r] != a[r+1]) ++r;
        if(a[l] == a[r]) {
            for(int i = l; i <= r; ++i) a[i] = a[l];
        } else {
            for(int i = l; i <= (l + r) / 2; ++i) a[i] = a[l];
            for(int i = (l + r) / 2 + 1; i <= r; ++i) a[i] = a[r];
        }
        ans = max(ans, (r - l) / 2);
        l = r + 1;
    }
    cout << ans << endl;
    for(int i = 1; i <= n; ++i) cout << a[i] << ' '; 
    cout << endl;
}