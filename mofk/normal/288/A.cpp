#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, K;
string ans;
bool h[26];
int cnt;

bool canPut(int c, int left) {
    if (!h[c]) ++left;
    if (left + cnt < K) return 0;
    return 1;
}

int main(void) {
    cin >> N >> K;
    if (N < K) return cout << -1 << "\n", 0;
    if (N > 1 && K == 1) return cout << -1 << "\n", 0;
    ff(i, 0, N - 1) ff(j, 0, 25) if (i == 0 || j != ans[i-1] - 'a') if (canPut(j, N - i - 1)) { ans += j + 'a'; if (!h[j]) ++cnt; h[j] = 1; break; }
    cout << ans << endl;
    return 0;
}