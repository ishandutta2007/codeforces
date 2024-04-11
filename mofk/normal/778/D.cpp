#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;
typedef pair <int, int> ii;

int N, M;
int a[105][105];
int b[105][105];
vector <ii> ans;

void work(int r, int c) {
    if (a[r+1][c+1] == 0) {
        ans.pb(ii(r, c));
        swap(a[r][c+1], a[r+1][c]);
        return;
    }
    if (a[r+1][c]) work(r + 1, c);
    else work(r, c + 1);
    ans.pb(ii(r, c));
    swap(a[r][c+1], a[r+1][c]);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    string s;
    ff(i, 1, N) {
        cin >> s;
        ff(j, 1, M) if (s[j-1] == 'U' || s[j-1] == 'L') a[i][j] = 1;
    }
    ff(i, 1, N) {
        cin >> s;
        ff(j, 1, M) if (s[j-1] == 'U' || s[j-1] == 'L') b[i][j] = 1;
    }
    ff(sum, 2, N + M) {
        int L = max(1, sum - M), R = min(N, sum - 1);
        int ptr = R;
        fb(j, R, L) if (b[j][sum - j] == 1) {
            while (a[ptr][sum - ptr] == 0) --ptr;
            if (ptr == j) { --ptr; continue; }
            if (ptr < j) ff(i, ptr, j - 1) work(i, sum - i - 1);
            else fb(i, ptr, j + 1) work(i - 1, sum - i);
            ptr = j - 1;
        }
    }
    cout << ans.size() << endl;
    ff(i, 0, (int)ans.size() - 1) cout << ans[i].first << " " << ans[i].second << "\n";
    return 0;
}