#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

const ll INF = (ll)1e18;
const int N = 200 * 1000 + 100;

int my_abs(int a) {
    return a > 0 ? a : -a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    a--;
    b--;
    if (s[a] == s[b]) 
        cout << 0 << endl;
    else
        cout << 1 << endl;         
}