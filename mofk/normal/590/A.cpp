#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

const int MAX = 5e5 + 5, INF = 1e9;

int N;
bool b[MAX];
bool a[MAX];

int main(void) {
    cin >> N;
    ff(i, 1, N) cin >> b[i];
    b[0] = b[1]; b[N+1] = b[N];
    int mx = 0, cur = 1;
    ff(i, 1, N + 1) if (b[i] != b[i-1]) ++cur; else { mx = max(mx, (cur - 1) / 2); cur = 1; }
    cout << mx << "\n";
    int l = 1;
    a[1] = b[1];
    ff(i, 2, N + 1) if (b[i] == b[i-1]) {
        if (i - l & 1) ff(j, l, i - 1) a[j] = b[l];
        else {
            ff(j, l, (l + i - 1) / 2) a[j] = b[l];
            ff(j, (l + i - 1) / 2 + 1, i - 1) a[j] = b[i-1];
        }
        l = i;
    }
    ff(i, 1, N) cout << a[i] << " ";
    return 0;
}