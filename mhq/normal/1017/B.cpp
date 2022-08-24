#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s[2];
ll a[2][2];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> s[0] >> s[1];
    for (int i = 0; i < n; i++) {
        a[s[0][i] - '0'][s[1][i] - '0']++;
    }
    cout << a[0][0] * a[1][1] + a[0][1] * a[1][0] + a[0][0] * a[1][0];
}