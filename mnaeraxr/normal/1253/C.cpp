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

    int n, m;
    cin >> n >> m;

    int64 answer = 0;

    vector<int64> a(n);
    vector<int64> s(m);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i){
        s[i % m] += a[i];
        answer += s[i % m];
        cout << answer << " ";
    }

    return 0;
}