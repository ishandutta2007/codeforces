
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
ll c, sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while(n--) {
        cin >> c >> sum;
        ll a = sum % c;
        ll b = c - a;
        ll q1 = sum / c;
        ll q2 = (sum + c - 1) / c;
        cout << (q1 * q1 * b + q2 * q2 * a) << endl;
    }
}