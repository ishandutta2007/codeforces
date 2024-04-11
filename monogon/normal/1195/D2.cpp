
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 1e5 + 5;
const int M = 998244353;
int n;
int freq[11];
ll num[11];
string a;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        int len = a.length();
        freq[len]++;
        for(int f = 1; f <= 10; f++) {
            ll pow10 = 1;
            for(int j = 0; j < f && j < len; j++) {
                num[f] += (a[len - 1 - j] - '0') * pow10;
                num[f] %= M;
                pow10 = (pow10 * 100) % M;
            }
            for(int j = f; j < len; j++) {
                num[f] += (a[len - 1 - j] - '0') * pow10;
                num[f] %= M;
                pow10 = (pow10 * 10) % M;
            }
            pow10 = 10;
            for(int j = 0; j < f - 1 && j < len; j++) {
                num[f] += (a[len - 1 - j] - '0') * pow10;
                num[f] %= M;
                pow10 = (pow10 * 100) % M;
            }
            for(int j = f - 1; j < len; j++) {
                num[f] += (a[len - 1 - j] - '0') * pow10;
                num[f] %= M;
                pow10 = (pow10 * 10) % M;
            }
        }
    }
    ll tot = 0;
    for(int f = 1; f <= 10; f++) {
        tot += freq[f] * num[f];
        tot %= M;
    }
    cout << tot << endl;
}