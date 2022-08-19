#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    int b[n];
    for(int i = 0; i < n; i++){
        if(i == 0 || i == 1){
            b[i] = 0;
        } else if(a[i] == a[i-1]+a[i-2]){
            b[i] = 1;
        } else {
            b[i] = 0;
        }
    }
    int ans = 0;
    int cur = 0;
    for(int i = 0; i < n; i++){
        if(b[i]){
            cur++;
        } else {
            cur= 0;
        }
        ans = max(ans, cur);
    }
    cout << ans +2 << endl;
    return 0;
}