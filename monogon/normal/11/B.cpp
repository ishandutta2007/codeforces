
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> x;
    x = abs(x);
    ll sum = 0;
    int i = 0;
    while(sum < x) sum += ++i;
    if((sum - x) % 2 == 0) {
        cout << i << endl;
    }else if(i % 2 == 0) {
        cout << i + 1 << endl;
    }else {
        cout << i + 2 << endl;
    }
}