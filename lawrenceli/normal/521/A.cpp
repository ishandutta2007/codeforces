#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n, freq[4];
string s;

int pw(int b, int e) {
    if (!e) return 1;
    return (long long)(b)*pw(b, e-1)%MOD;
}

int main() {
    cin >> n >> s;
    for (int i=0; i<n; i++)
        if (s[i] == 'A') freq[0]++;
        else if (s[i] == 'C') freq[1]++;
        else if (s[i] == 'G') freq[2]++;
        else freq[3]++;
    int ma = max(max(freq[0], freq[1]), max(freq[2], freq[3]));
    int cnt = 0;
    for (int i=0; i<4; i++) if (freq[i] == ma) cnt++;
    cout << pw(cnt, n) << '\n';
}