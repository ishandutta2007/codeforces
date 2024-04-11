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

    string s; cin >> s;

    int n = s.length();

    s += s;

    int best = 1, cur = 1;

    for (int i = 1; i < 2 * n; ++i){
        if (s[i] != s[i - 1])
            cur++;
        else
            cur = 1;

        best = max(best, cur);
    }

    cout << min(best, n) << endl;
}