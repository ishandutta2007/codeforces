#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout << #x << "=" << x << endl
#define MP make_pair

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MAXN = (int)1e5 + 10;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-7;
const int oo = 1 << 30;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;

    while (N--){
        int64 a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        int64 ans = a;
        for (int i = 0; (ans | (1LL << i)) <= b; ++i)
            ans |= (1LL << i);
        cout << ans << endl;
    }

    return 0;
}