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

    if (k > n){
        cout << "NO" << endl;
        return 0;
    }

    if (k < __builtin_popcount(n)){
        cout << "NO" << endl;
        return 0;
    }

    multiset<int> s;

    for (int i = 1; i <= n; i *= 2){
        if (n & i){
            s.insert(i);
        }
    }

    while ((int)s.size() < k){
        int a = *s.rbegin();
        s.erase(s.find(a));
        s.insert(a / 2);
        s.insert(a / 2);
    }

    cout << "YES" << endl;
    for (auto x : s)
        cout << x << " ";
    cout << endl;

    return 0;
}