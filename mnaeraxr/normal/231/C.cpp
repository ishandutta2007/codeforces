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
 
    int n;
    int64 k;
    cin >> n >> k;

    vector<int64> v(n);

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());
    vector<int64> acc(n);

    acc[0] = v[0];
    for (int i = 1; i < n; ++i)
        acc[i] = acc[i - 1] + v[i];

    int best = 0, freq = 0;

    for (int i = 0; i < n; ++i){
        int l = i, h = n;

        while (l + 1 < h){
            int m = (l + h) >> 1;

            int64 A = acc[m] - (i ? acc[i - 1] : 0);
            int64 C = v[m] * (m - i + 1) - A;
            if (C <= k) l = m;
            else h = m;
        }

        if (l - i + 1 > freq){
            freq = l - i + 1;
            best = v[l];
        }
    }

    cout << freq << " " << best << endl;
    
    return 0;
}