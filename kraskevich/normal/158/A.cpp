#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    --k;
    int a[n];
    for(int i = 0; i < n; ++i)
            cin >> a[i];
    int res = 0, mn = a[k];
    for(int i = 0; i < n; ++i)
            if(a[i] > 0 && a[i] >= mn)
                    ++res;
    cout << res;
    cin >> n;
    return 0;
}