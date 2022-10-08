
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 2e5 + 5;
int n, a, last;

int main() {
    cin >> n;
    bool inc = true;
    last = 0;
    for(int i = 0; i < n; i++) {
        cin >> a;
        if(inc && a < last) {
            inc = false;
        }
        if(!inc && a > last) {
            cout << "NO" << endl;
            return 0;
        }
        last = a;
    }
    cout << "YES" << endl;
}