#include <iostream>
#include <algorithm>
using namespace std;
int a[11][11];
template<class T>
bool go(int k, const T& func) {
    return k ? go(k - 1, func), func(k - 1), 0 : 0;
}
int main() {
    int n;
    cin >> n;
    go(n, [&](int i){
        go(n, [&](int j){
            cin >> a[i][j];
        });
    });
    int ans = 0;
    go(n, [&](int k){
        go(n, [&](int i){
            go(n, [&](int j){
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            });
        });
    });
    go(n, [&](int i){
        go(n, [&](int j){
            ans = max(ans, a[i][j]);
        });
    });
    cout << ans << endl;
    
    return 0;
}