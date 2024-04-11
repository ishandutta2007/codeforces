#include <bits/stdc++.h>
using namespace std;

int n;
long long k;
int x;

int main()
{
    cin >> n;
    while (n--) {
        cin >> k >> x;
        long long res = (k - 1) * 9 + x;
        cout << res << endl;
    }
    return 0;
}