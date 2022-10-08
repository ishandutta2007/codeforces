
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n;
int t[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }
    int a = 0, b = 0, wa = 0, wb = 0;
    while(a + b < n) {
        if(wa <= wb) {
            wb -= wa;
            wa = t[a];
            a++;
        }else {
            wa -= wb;
            wb = t[n - b - 1];
            b++;
        }
    }
    cout << a << " " << b << endl;
}