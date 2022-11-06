#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define mp make_pair
#define MOD 1000000007
#define pii pair<ll, ll>
typedef long long ll;
int Abs(int x) {
    return x>0?x:-x;
}

ll n;

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        cout << 9*(x-1) + y << endl;
    }
    return 0;
}