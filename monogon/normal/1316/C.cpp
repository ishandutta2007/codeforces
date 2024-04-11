
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, m;
ll p, a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> p;
    int t1 = 0, t2 = 0;
    for(int i = 0; i < n; i++) {
        cin >> a;
        if(a % p != 0) t1 = i;
    }
    for(int j = 0; j < m; j++) {
        cin >> a;
        if(a % p != 0) t2 = j;
    }
    cout << t1 + t2 << endl;
}