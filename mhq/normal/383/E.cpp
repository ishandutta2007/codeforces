#include <bits/stdc++.h>

using namespace std;
const int maxN = 1 << 24;
int f[maxN];
bool s[24];
int bits[8];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    for (int i = 1; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            if (i & (1 << j)) {
                bits[i] = bits[i ^ (1 << j)] + 1;
                break;
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        vector < int > v;
        for (int j = 0; j < 3; j++) {
            char x;
            cin >> x;
            v.push_back((int)(x - 'a'));
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int mask = 1; mask < (1 << v.size()); mask++) {
            int nmask = 0;
            for (int j = 0; j < v.size(); j++) {
                if (mask & (1 << j)) nmask |= (1 << v[j]);
            }
            if (bits[mask] & 1) f[nmask]++;
            else f[nmask]--;
        }
    }
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < (1 << 24); j++) {
            if (j & (1 << i)) f[j] += f[j ^ (1 << i)];
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << 24); i++) {
        ans ^= (f[i] * f[i]);
    }
    cout << ans;
	return 0;
}