#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 1<<30;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

int W[MAXN];
int O[MAXN];

int R[MAXN];
int TW[MAXN];
int POS[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i){
        cin >> W[i];
        POS[i] = -1;
    }

    for (int i = 0, t = 0; i < m; ++i){
        cin >> O[i];
        O[i]--;
        if (POS[ O[i] ] == -1){
            POS[ O[i] ] = 1;
            R[t++] = O[i];
        }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i){
        int j = 0;

        int cur_sum = 0;

        for ( ; R[j] != O[i]; ++j){
            cur_sum += W[ R[j] ];
        }
        ans += cur_sum;
        int cur = O[i];
        for (;j != 0 ; --j){
            R[j] = R[j - 1];
        }
        R[0] = cur;
    }
    cout << ans << endl;

    return 0;
}