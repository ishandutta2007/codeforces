#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int m, K;
bool ok[1005][2005];
int N;
int a[1005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> K;
    int x;
    ff(i, 1, K) cin >> x, ok[x][1] = 1;
    ff(i, 0, 1000) if (ok[i][1]) a[++N] = i - m;
    if (a[1] > 0 || a[N] < 0) return cout << -1 << endl, 0;
    int step = 1;
    while (!ok[m][step]) {
        ++step;
        ff(i, 0, 1000) if (ok[i][step-1]) ff(j, 1, N) if (i + a[j] >= 0 && i + a[j] <= 1000) ok[i + a[j]][step] = 1;
    }
    cout << step << endl;
    return 0;
}