#include <bits/stdc++.h>
#define sz(a) int((a).size())
using namespace std;
typedef long long ll;
void solveone() {

}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    int cnt = 240 - k, ans = 0;
    for(int i = 1; i <= n; i++) {
        if(i * 5 <= cnt) {
            cnt -= i * 5;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}