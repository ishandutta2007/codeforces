#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N; string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> s;
    int ans = 0;
    for (int i = 0; i < N; ++i) if (s[i] == '<') ++ans; else break;
    for (int i = N - 1; i >= 0; --i) if (s[i] == '>') ++ans; else break;
    cout << ans << endl;
    return 0;
}