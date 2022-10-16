#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64 n, m, k;

    cin >> n >> m >> k;

    vector<int64> a(m);

    for (int i = 0; i < m; ++i)
        cin >> a[i];

    int64 p = 0, answer = 0, fin = k;

    while (p < m){
        int64 lo = -1, hi = 1;
        while (fin + k * hi < a[p])
            hi *= 2;
        while (lo + 1 < hi){
            int64 m = (lo + hi) / 2;
            if (fin + k * m < a[p])
                lo = m;
            else
                hi = m;
        }

        fin = fin + k * hi;
        int64 cor = 0;

        while (p < m && a[p] <= fin){
            p++;
            cor++;
        }

        fin += cor;
        answer++;
    }

    cout << answer << endl;

    return 0;
}