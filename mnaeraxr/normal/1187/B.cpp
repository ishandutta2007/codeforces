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

    string s; cin >> s;

    map<pair<int,int>,int> a;
    vi freq(26);

    for (int i = 1; i <= n; ++i){
        int u = s[i - 1] - 'a';
        freq[u]++;
        a[pii(u, freq[u])] = i;
    }

    int q; cin >> q;

    while (q-->0){
        string b; cin >> b;
        vi f(26);

        int answer = 0;

        for (auto c : b) {
            int u = c - 'a';
            f[u]++;
            answer = max(answer, a[pii(u, f[u])]);
        }

        cout << answer << endl;
    }

    return 0;
}