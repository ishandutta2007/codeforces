#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, d, m;
    cin >> n >> d;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    cin >> m;
    if(m <= n){
        int ans = 0;
        for(int i = 0; i < m; i++){
            ans += a[i];
        }
        cout << ans << endl;
    } else {
        int ans = -d*(m-n);
        for(int i = 0; i < n; i++){
            ans += a[i];
        }
        cout << ans << endl;
    }
    
    
    return 0;
}