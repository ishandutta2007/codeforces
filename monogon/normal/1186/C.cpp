
#include <bits/stdc++.h>

#define ll long long
using namespace std;

string a, b;
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin >> a >> b;
    n = a.length();
    m = b.length();
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        cnt += (b[i] == '1');
        cnt += (a[i] == '1');
    }
    int tot = 0;
    tot += (cnt % 2 == 0);
    for(int j = m; j < n; j++) {
        cnt += (a[j] == '1') - (a[j - m] == '1');
        tot += (cnt % 2 == 0);
    }
    cout << tot << endl;
}