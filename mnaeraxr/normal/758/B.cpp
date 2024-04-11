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

    string s; cin >> s;
    int n = (int)s.length();

    vector<int> ans(4);
    string color = "RBYG";

    for (int j = 0; j < 4; ++j){
        char c = '!';
        int d = 0;

        for (int i = j; i < n; i += 4){
            if (s[i] == '!') d++;
            else c = s[i];
        }

        for (int i = 0; i < 4; ++i)
            if (color[i] == c)
                ans[i] = d;
    }

    for (int i = 0; i < 4; ++i)
        cout << ans[i] << " ";
    cout << endl;


    return 0;
}