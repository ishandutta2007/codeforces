
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int a1, a2, k1, k2, n;

int main() {
    ios::sync_with_stdio(false);
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    int num1 = 0, num2 = 0;
    if(k1 > k2) {
        swap(k1, k2);
        swap(a1, a2);
    }
    // min players
    num1 = max(0, n - (k1 - 1) * a1 - (k2 - 1) * a2);

    // max players
    while(n > 0 && a1 > 0) {
        if(n >= k1) {
            n -= k1;
            a1--;
            num2++;
        }else {
            n = 0;
        }
    }
    while(n > 0 && a2 > 0) {
        if(n >= k2) {
            n -= k2;
            a2--;
            num2++;
        }else {
            n = 0;
        }
    }
    cout << num1 << " " << num2 << endl;
}