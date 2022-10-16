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

    int n; cin >> n;

    vector<int64> a(n), b(n);

    int64 answer = 0;

    set<int64> masks;
    map<int64,int> freq;

    for (int i = 0; i < n; ++i){
        cin >> a[i];

        if (++freq[a[i]] == 2)
            masks.insert(a[i]);
    }

    int total = 0;

    for (int i = 0; i < n; ++i){
        cin >> b[i];

        for (auto x : masks)
            if ((a[i] & x) == a[i]){
                total++;
                answer += b[i];
                break;
            }
    }

    cout << answer << endl;

    return 0;
}