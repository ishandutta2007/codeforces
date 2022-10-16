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
 
    int n, k;
    cin >> n >> k;
 
    string s; cin >> s;
    vector<bool> pe(n), se(n);
 
    vector<int> ones, zeros;
 
    for (int i = 0; i < n; ++i){
        if (s[i] == '0') zeros.push_back(i);
        if (s[i] == '1') ones.push_back(i);
    }
 
    if (zeros.empty() || ones.empty() || zeros.back() - zeros[0] < k ||
        ones.back() - ones[0] < k){
        cout << "tokitsukaze" << endl;
        return 0;
    }
 
    auto check = [&](int value, int pos){
        auto &p = (value == 0) ? ones : zeros;
 
        if (p[0] < pos){
            if (p.back() >= pos + k)
                return false;
 
            auto it = lower_bound(p.begin(), p.end(), pos);
            it--;
 
            return *it - p[0] < k;
        } else {
            assert(p.back() >= pos + k);
            return p.back() - *lower_bound(p.begin(), p.end(), pos + k) < k;
        }
    };
 
    bool ok = true;
 
    for (int i = 0; i < n - k + 1 && ok; ++i){
        if (!check(0, i) || !check(1, i))
            ok = false;
    }
 
    if (ok) cout << "quailty" << endl;
    else cout << "once again" << endl;
 
    return 0;
}