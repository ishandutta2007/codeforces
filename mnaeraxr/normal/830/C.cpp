#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif

    int n;
    int64 k;
    cin >> n >> k;

    vector<int64> value(n);

    set<int64> div;

    for (int i = 0; i < n; ++i){
        cin >> value[i];

        for (int j = 1; j * j <= value[i]; ++j){
            // div.insert(j);
            div.insert( (value[i] + j - 1) / j );
        }
    }

    auto calc = [&](int64 d){
        int64 ans = 0;

        for (auto u : value)
            ans += ((u + d - 1) / d) * d - u;

        return ans;
    };

    vector<int64> answer( div.begin(), div.end() );
    answer.push_back( 100000000000LL + 1000000000 + 10 );

    // cout << answer.back() << endl;
    // for (auto u : answer)
    //     cout << u << " ";
    // cout << endl;

    int t = (int)answer.size();

    for (int i = t - 2; i >= 0; --i){
        // cout << i << " " << answer[i] << endl;
        if (calc( answer[i] ) > k)
            continue;

        int64 lo = answer[i], hi = answer[i + 1];

        while (lo + 1 < hi){
            int64 mid = (lo + hi) >> 1;

            if (calc(mid) <= k)
                lo = mid;
            else
                hi = mid;
        }

        cout << lo << endl;
        exit(0);
    }

    for (int i = answer[0] - 1; ;--i)
        if (calc(i) <= k){
            cout << i << endl;
            exit(0);
        }

    assert( false );

    return 0;
}