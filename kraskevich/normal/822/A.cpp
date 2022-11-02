#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    ll a, b;
    cin >> a >> b;
    ll res = 1;
    for (ll i = 1; i <= min(a, b); i++)
        res *= i;
    cout << res << "\n";
}