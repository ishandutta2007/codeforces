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

    vector<int> a(n), b(n);

    vector<int> inv(n);

    for (int i = 0; i < n; ++i){
        cin >> a[i];
        a[i]--;
    }

    reverse(a.begin(), a.end());

    for (int i = 0; i < n; ++i){
        cin >> b[i];
        b[i]--;
    }
    reverse(b.begin(), b.end());

    for (int i = 0; i < n; ++i)
        inv[b[i]] = i;

    int answer = 0;

    for (int i = n - 1, p = n - 1; i >= 0; --i){
        if (inv[a[i]] <= p){
            // cout << i << " " << a[i] << " " << inv[a[i]] << " " << p << endl;
            answer += p - inv[a[i]];
            p = inv[a[i]] - 1;
        }
    }

    cout << answer << endl;

    return 0;
}