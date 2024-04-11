#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
#endif

    int n; cin >> n;

    vector<int> ans;

    for (int i = 1; i <= n; ++i){
        ans.push_back(i);
        n -= i;
    }

    ans.back() += n;

    cout << ans.size() << endl;

    for (auto a : ans)
        cout << a << " ";
    cout << endl;

    return 0;
}