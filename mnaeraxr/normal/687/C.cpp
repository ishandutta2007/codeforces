#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 500 + 1;

bool dp[maxn][maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    dp[0][0]= true;

    for (int t = 0; t < n; ++t){
        int v; cin >> v;

        for (int i = k; i >= 0; --i)
            for (int j = k; j >= 0; --j){
                if (!dp[i][j]) continue;
                if (i + v <= k) dp[i + v][j] = true;
                if (j + v <= k) dp[i][j + v] = true;
            }
    }

    vector<int> ans;

    for (int i = 0; i <= k; ++i)
        if (dp[i][k - i]) ans.push_back(i);

    cout << ans.size() << endl;
    for (auto v : ans)
        cout << v << " ";
    cout << endl;

    return 0;
}