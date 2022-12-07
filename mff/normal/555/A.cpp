#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int b1 = 0;
    int s1 = 0;

    for (int i = 0; i < m; ++i){
        int mi; cin >> mi;
        int cc = 0;
        for (int j = 0; j < mi; ++j){
            int cur; cin >> cur;
            if (cur == 1){
                if (j == 0) b1 = 1;
                cc = 1;
                s1 = 1;
            }
            else{
                if (cc + 1 == cur)
                {
                    cc = s1 = cur;
                }
                else{
                    cc = -1;
                }
            }
        }
    }

    int ans = 2 * (n - s1) - m + b1;
    cout << ans << endl;

    return 0;
}