#include <iostream>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    long long res = 0, cur = 0, a[n];
    for(int i = 0; i < n; ++i)
            cin >> a[i];
    for(int i = 0; i < n; ++i) {
            cur++;
            if(i == n - 1 || a[i] != a[i + 1]) {
                 res += cur * (cur + 1) / 2;
                 cur = 0;
            }
    }
    cout << res;
    cin >> n;
    return 0;
}