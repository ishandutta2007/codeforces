#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

string s, t;
int N, M;
int p[200005];

bool check(int k) {
    vector <bool> v(N, 1);
    ff(i, 1, k) v[p[i]] = 0;
    int ptr = 0;
    ff(i, 0, N - 1) {
        if (v[i] && s[i] == t[ptr]) ++ptr;
        if (ptr == M) return 1;
    }
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s >> t;
    N = s.size(), M = t.size();
    ff(i, 1, N) cin >> p[i], --p[i];
    int L = 0, R = N - M;
    while (L < R) {
        int m = L + R + 1 >> 1;
        if (check(m)) L = m;
        else R = m - 1;
    }
    cout << L << endl;
    return 0;
}