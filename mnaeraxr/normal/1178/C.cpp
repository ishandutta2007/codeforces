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

    int64 answer = 1;

    for (int i = 0; i < n + m; ++i){
        answer <<= 1;
        if (answer >= 998244353)
            answer -= 998244353;
    }

    cout << answer << endl;

    return 0;
}