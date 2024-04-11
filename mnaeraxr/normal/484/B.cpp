#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout << #x << "=" << x << endl
#define MP make_pair

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MOD = (int)1e9 + 7;
const double EPS = 1e-7;
const int oo = 1 << 30;
const int MAXN = (int)1e6 + 10;
//const int MAXN = 20;

int L[MAXN];
int R[MAXN];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;

    for (int i = 0; i < N; ++i){
        int v; cin >> v;
        R[i] = v;
        L[v] = v;
    }
    sort(R, R + N);
    int ans = 0;
    int SZ = unique(R, R + N) - R;

    for (int i = 1; i < MAXN; ++i){
        L[i] = max(L[i], L[i - 1]);
    }

    for (int i = 0; i < SZ; ++i){
        if (R[i] == 1) continue;
        ans = max(ans, L[MAXN - 1] % R[i]);
        for (int j = 2 * R[i]; j < MAXN; j += R[i]){
            if (L[j - 1] > R[i])
                ans = max(ans, L[j - 1] % R[i]);
        }
    }

    cout << ans << endl;

    return 0;
}