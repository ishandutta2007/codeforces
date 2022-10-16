#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, K;
int a[1000005], b[1000005];
int maxA[1000005][20], minB[1000005][20];
int val[1000005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    ff(i, 1, N) cin >> a[i], a[i] *= 100;
    ff(i, 1, N) cin >> b[i];
    ff(i, 1, N) maxA[i][0] = a[i];
    ff(j, 1, 19) ff(i, 1, N) maxA[i][j] = max(maxA[i][j-1], maxA[min(N, i + (1 << j - 1))][j-1]);
    ff(i, 1, N) minB[i][0] = b[i];
    ff(j, 1, 19) ff(i, 1, N) minB[i][j] = min(minB[i][j-1], minB[min(N, i + (1 << j - 1))][j-1]);
    ff(i, 1, N) {
        int x = i + 1, mxA = a[i], mnB = b[i];
        if (mxA >= mnB) { val[i] = mnB; continue; }
        fb(j, 19, 0) if (x <= N && max(mxA, maxA[x][j]) < min(mnB, minB[x][j])) {
            mxA = max(mxA, maxA[x][j]), mnB = min(mnB, minB[x][j]), x += (1 << j);
            if (x > N) x = N + 1;
        }
        val[i] = max(mxA, min(mnB, b[x]));
    }
    //ff(i, 1, N) cout << val[i] << endl;
    sort(val + 1, val + N + 1);
    double ans = 0;
    double mul = 1.0 * K / N;
    ff(i, 1, N - K + 1) {
        ans += mul * val[i];
        mul *= N - i - K + 1;
        mul /= N - i;
    }
    cout << setprecision(12) << fixed << ans << endl;
    return 0;
}