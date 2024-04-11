#include <iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<string.h>

using namespace std;

typedef long long ll;

ll X(ll y, ll b, ll m){
    return (b - y) * m;
}

ll count(ll x, ll y, ll b, ll m){
    ll sum = (x * (x + 1)) / 2;
    sum *= (y + 1);
    ll add = x + 1;
    add *= (y * (y + 1) / 2);
    return sum + add;
}


int main() {
    ll m, b;
    cin >> m >> b;
    ll max = 0;
    for (ll y = 0; y <= b; ++y) {
        if (count(X(y, b, m), y, b, m) > max) {
            max = count(X(y, b, m), y, b, m);
//            cout << max << " "<<y << X(y, b, m) << "\n";
        }
    }
    cout << max << endl;
    return 0;
}