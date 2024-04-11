#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll MOD = 1000 * 1000 * 1000 + 7;

const int N = 1000 * 1000 + 10;
ll p2[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    p2[0] = 1;
    for (int i = 1; i < N; i++)
        p2[i] = p2[i - 1] * 2 % MOD;
    ll res = 0;
    string s;
    cin >> s;
    int cnta = 0;
    for (char c : s) {
        if (c == 'a')
            cnta++;
        else
            res = (res + p2[cnta] - 1 + MOD) % MOD;
    }
    cout << res << endl;
}