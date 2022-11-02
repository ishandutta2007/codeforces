#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define F first
#define S second

const int INF = (int)1e9;

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = -INF;
    for (int l = 0; l < n; l++)
        for (int r = l; r < n; r++)
        {
            int len = r - l + 1;
            vector<int> in;
            vector<int> out;
            in.reserve(len);
            out.reserve(n - len);
            for (int i = 0; i < n; i++)
                if (i < l || i > r)
                    out.push_back(a[i]);
                else
                    in.push_back(a[i]);
            sort(in.begin(), in.end());
            sort(out.begin(), out.end());
            reverse(out.begin(), out.end());
            int cur = 0;
            for (int i = 0; i < len; i++)
                cur += in[i];
            res = max(res, cur);
            int sin = 0;
            int sout = 0;
            for (int i = 0; i < min(min(len, n - len), k); i++)
            {
                sin += in[i];
                sout += out[i];
                res = max(res, cur + sout - sin);
            }
        }
    cout << res;

    return 0;
}