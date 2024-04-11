#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int x = (1 << k) - 1;

    vector<int> v(n+1);
    map<int,int> freq;

    for (int i = 1; i <= n; ++i){
        int u; cin >> u;
        v[i] = v[i-1] ^ u;
        freq[min(v[i], v[i] ^ x)]++;
    }

    freq[0]++;

    int64 answer = 0;

    for (auto p : freq){
        int a = p.second / 2;
        int b = p.second - a;

        answer += 1LL * a * (a - 1) / 2 + 1LL * b * (b - 1) / 2;
    }

    int64 total = 1LL * n * (n + 1) / 2;

    cout << total - answer << endl;
}