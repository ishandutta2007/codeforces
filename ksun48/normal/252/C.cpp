#include <iostream>
using namespace std;
typedef long long LL;
int main() {
    LL n, d;
    cin >> n >> d;
    LL a[n+1];
    for(int i = 0; i < n; i++) cin >> a[i];
    a[n] = 10000000000;
    LL cur = 0;
    LL ans = 0;
    for(int i = 0; i < n; i++){
        while(a[cur+1]-a[i] <= d){
                cur++;
        }
        ans += max(0LL, (cur-i)*(cur-i-1)/2);
    }
    cout << ans << endl;
    return 0;
}