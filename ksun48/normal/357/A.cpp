#include <iostream>
using namespace std;

int main() {
    int n, x, y;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> x >> y;
    int sum = 0;
    for(int i = 0; i < n; i++) sum += a[i];
    int cur = 0;
    for(int i = 0; i < n; i++){
        if(cur >= x && cur <= y && sum-cur >= x && sum-cur <= y){
            cout << i + 1 << endl;
            return 0;
        }
        cur += a[i];
    }
    cout << 0 << endl;
    return 0;
}