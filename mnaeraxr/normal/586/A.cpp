#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 200;

int v[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        cin >> v[i];
    }

    for (int i = 1; i <= n; ++i)
        if (v[i] || (v[i - 1] && v[i + 1])) ++ans;

    cout << ans << endl;

    return 0;
}