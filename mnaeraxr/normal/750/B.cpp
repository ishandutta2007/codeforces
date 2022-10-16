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
    int p = 0;


    for (int i = 0; i < n; ++i){
        int d; string s;
        cin >> d >> s;

        if (s[0] == 'E' || s[0] == 'W'){
            if (p == 0 || p == 20000){
                cout << "NO" << endl;
                return 0;
            }
            continue;
        }

        if (s[0] == 'N')
            p -= d;
        else
            p += d;

        if (p < 0 || p > 20000){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << (p == 0 ? "YES" : "NO") << endl;

    return 0;
}