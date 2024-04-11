
#include <bits/stdc++.h>
using namespace std;
 
#define maxn 105
 
int a[maxn];
 
void work(void) {
    int n;
    cin >> n;
    for (register int i = 1; i <= n; i++) cin >> a[i];
    int answer = 0;
    for (register int i = 0; i < 31; i++) {
        bool check = true;
        for (register int j = 1; j <= n; j++)
            if (!(a[j] >> i & 1)) check = false;
        answer |= check << i;
    }
    cout << answer << endl;
    return;
}
 
int main() {
    ios::sync_with_stdio(false);
    int _;
    cin >> _;
    while (_--) work();
    return 0;
}