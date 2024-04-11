
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 13850;
int n, a[N], o[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i] / 2;
    }
    for(int i = 0; i < n; i++) {
        if(a[i] & 1) {
            if(sum > 0 && a[i] < 0) {
                cout << a[i] / 2 - 1 << endl;
                sum--;
            }else if(sum < 0 && a[i] > 0) {
                cout << a[i] / 2 + 1 << endl;
                sum++;
            }else {
                cout << a[i] / 2 << endl;
            }
        }else {
            cout << a[i] / 2 << endl;
        }
    }
}