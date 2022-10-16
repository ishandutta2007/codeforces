#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 22;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> value(n);
    vector<int> svalue(n);

    for (int i = 0; i < n; ++i){
        cin >> value[i];
        svalue[i] = value[i];
    }

    sort(svalue.begin(), svalue.end());

    for (int i = 0; i < n; ++i){
        int p = lower_bound(svalue.begin(), svalue.end(), value[i]) - svalue.begin();
        p = p == 0 ? n - 1 : p - 1;
        cout << svalue[p] << " ";
    }

    cout << endl;

    return 0;
}