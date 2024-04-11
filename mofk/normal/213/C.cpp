#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

const int INF = 1000000789;
int N;
int a[305][305];
vector <vi> now, nxt;

void mxm(int& a, int b) { if (a < b) a = b; }

int main(void) {
    cin >> N;
    ff(i, 0, N - 1) ff(j, 0, N - 1) cin >> a[i][j];
    now.assign(N, vi(N, -INF));
    now[0][0] = a[0][0];
    ff(rep, 0, 2 * N - 3) {
        nxt.assign(N, vi(N, -INF));
        ff(i, 0, N - 1) ff(j, 0, N - 1) if (now[i][j] > -INF) {
            //cout << rep << " " << i << " " << j << " " << now[i][j] << endl;
            ff(p, 0, 1) ff(q, 0, 1) {
                if (max(i + p, j + q) > min(N - 1, rep + 1)) continue;
                if (i + p == j + q) mxm(nxt[i+p][j+q], now[i][j] + a[i+p][rep+1-i-p]);
                else mxm(nxt[i+p][j+q], now[i][j] + a[i+p][rep+1-i-p] + a[j+q][rep+1-j-q]);
            }
        }
        nxt.swap(now);
    }
    cout << now[N-1][N-1] << endl;
    return 0;
}