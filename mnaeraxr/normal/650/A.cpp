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

    map<int,int> H, V;
    map<pii,int> P;

    for (int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;

        H[x]++;
        V[y]++;
        P[make_pair(x, y)]++;
    }

    int64 answer = 0;

    for (auto a : H)
        answer += 1LL * a.second * (a.second -1) / 2;
    for (auto a : V)
        answer += 1LL * a.second * (a.second - 1) / 2;

    for (auto a : P)
        answer -= 1LL * a.second * (a.second - 1) / 2;

    cout << answer << endl;

    return 0;
}