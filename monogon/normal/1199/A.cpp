
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 1e5 + 5;

int n, x, y;
int a[MAX_N];

int main() {
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        bool b = false;
        for(int j = max(0, i - x); j < n && j <= i + y; j++) {
            if(a[j] < a[i]) {
                b = true;
                break;
            }
        }
        if(!b) {
            cout << (i + 1) << endl;
            return 0;
        }
    }
}