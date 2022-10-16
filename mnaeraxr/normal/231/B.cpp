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

    int n, d, l;

    cin >> n >> d >> l;

    vector<int> ans(n);

    for (int i = 0; i < n; ++i){
        ans[i] = 1;
    }

    if (n & 1) d--;

    for (int i = 0; i < n && d != 0; ++i){
        if (d < 0 && (i & 1)){
            ans[i] = min(l, -d + 1);
            d += ans[i] - 1;
        }
        else if (d > 0 && i % 2 == 0){
            ans[i] = min(d + 1, l);
            d -= ans[i] - 1;
        }
    }

    if (d != 0) cout << -1 << endl;
    else{
        for (int i = 0; i < n; ++i)
            cout << ans[i] << " ";
        cout << endl;
    }
    
    
    return 0;
}