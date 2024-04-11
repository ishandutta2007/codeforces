#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n[3];
vector <int> a[3];
vector <int> all;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    vector <int> all;
    int64_t sum = 0;

    for (int j = 0 ; j < 3 ; ++ j)
        cin >> n[j], a[j].resize(n[j]);
    for (int j = 0 ; j < 3 ; ++ j)
        for (int i = 0 ; i < n[j] ; ++ i)
        cin >> a[j][i], sum += a[j][i];
    int64_t ans = 0;

    for (int j = 0 ; j < 3 ; ++ j)
        sort(a[j].begin(), a[j].end());
    int64_t mn_get = min({a[0][0] + a[1][0], a[0][0] + a[2][0], a[1][0] + a[2][0]});
    #define get_sum(j) accumulate(a[j].begin(), a[j].end(), 0LL)
    mn_get = min({mn_get, get_sum(0), get_sum(1), get_sum(2)});
    ans = max(ans, sum - 2LL * mn_get);


    cout << ans << '\n';
}
/**
if two smallest number is from different array
sm1 - - - - - -
sm2 - - - - - -
buf x x x x x x
we can sacrifice this two number and get sum


*/