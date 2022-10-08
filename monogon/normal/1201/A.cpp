
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 1005;
int n, m, a;
ll c[MAX_N][5];
string str;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < m; j++) {
            c[j][str[j] - 'A']++;
        }
    }
    ll sum = 0;
    for(int i = 0; i < m; i++) {
        cin >> a;
        for(int j = 0; j < 5; j++) {
            c[i][0] = max(c[i][0], c[i][j]);
        }
        sum += a * c[i][0];
    }
    cout << sum << endl;
}