#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    ll t = 0;
    ll k = 1;
    while (k <= n)  {
        k *= 2;
        t++;
    }
    cout << t;
    return 0;
}