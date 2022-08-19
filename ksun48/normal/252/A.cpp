#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)cin >> a[i];
    int m = 0;
    for(int j = 0; j < n; j++){
        for(int k = j; k < n; k++){
            int b = 0;
            for(int i = j; i <= k; i++){
                b ^= a[i];
            }
            m = max(m, b);
        }
    }
    cout << m << endl;
    return 0;
}