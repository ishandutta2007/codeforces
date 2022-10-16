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

    string s; cin >> s;

    vector<char> a, b;

    int x = 0, y = s.length();
    if (y & 1) y--;

    while (y - x > 2){

        bool found = false;
        for (int i = 0; i < 2 && !found; ++i)
            for (int j = 0; j < 2 && !found; ++j)
            {
                if (s[x + i] == s[y - j - 1]){
                    a.push_back(s[x + i]);
                    b.push_back(s[y - j - 1]);
                    found = true;
                }
            }

        assert(found);
        x += 2;
        y -= 2;
    }

    if (y - x == 2){
        a.push_back(s[x]);
    }

    for (auto u : a) cout << u;
    reverse(b.begin(), b.end());
    for (auto u : b) cout << u;
    cout << endl;

    return 0;
}