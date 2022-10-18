#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

const int maxn = 400000 + 1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> freq(3);

    for (int i = 0; i < n; ++i){
        int v; cin >> v;
        freq[v]++;
    }

    if (freq[2] && freq[1]){
        cout << 2 << " " << 1 << " ";
        freq[2]--;
        freq[1]--;
    }

    for (int i = 0; i < freq[2]; ++i)
        cout << 2 << " ";

    for (int i = 0; i < freq[1]; ++i)
        cout << 1 << " ";

    cout << endl;

    return 0;
}