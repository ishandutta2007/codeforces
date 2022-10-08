
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 3e5 + 5;
int n, c[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int j = -1;
    int mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        if(i != 0) {
            if(c[i] != c[0]) {
                mx = max(mx, i);
            }else if(j != -1) {
                mx = max(mx, i - j);
            }
        }
        if(j == -1 && c[i] != c[0]) {
            j = i;
        }
    }
    cout << mx << endl;
}