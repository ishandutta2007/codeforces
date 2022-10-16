#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N;
int ans[500005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int x1, y1, x2, y2;
    ff(i, 1, N) {
        cin >> x1 >> y1 >> x2 >> y2;
        ans[i] = (abs(x1) & 1) * 2 + (abs(y1) & 1) + 1;
    }
    cout << "YES" << endl;
    ff(i, 1, N) cout << ans[i] << "\n";
    return 0;
}