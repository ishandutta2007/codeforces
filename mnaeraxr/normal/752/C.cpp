#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
#endif

    int n; cin >> n;

    string s; cin >> s;

    int hor = 0, ver = 0;
    int ans = 0;

    for (auto c : s){
        if (c == 'R'){
            if (hor == -1){
                ver = 0;
                ans++;
            }
            hor = 1;
        }
        else if (c == 'L'){
            if (hor == 1){
                ver = 0;
                ans++;
            }
            hor = -1;
        }
        else if (c == 'U'){
            if (ver == -1){
                hor = 0;
                ans++;
            }
            ver = 1;
        }
        else{
            if (ver == 1){
                hor = 0;
                ans++;
            }
            ver = -1;
        }
    }

    cout << ans + 1 << endl;

    return 0;
}