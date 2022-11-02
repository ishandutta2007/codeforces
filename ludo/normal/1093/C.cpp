#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> b(n/2), a(n);
    for (int i = 0; i < n/2; i++) cin >> b[i];
    a[0] = 0;
    a[n - 1] = b[0];
    for (int i = 1; i < n/2; i++) {
        a[n - 1 - i] = min(b[i] - a[i - 1], a[n - i]);
        a[i] = b[i] - a[n - 1 - i];
    }
    
    for (int i = 0; i < n; i++) printf("%lld%c", a[i], " \n"[i==n-1]);
    return 0;
}