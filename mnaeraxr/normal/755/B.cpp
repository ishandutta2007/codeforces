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

    int a, b;
    cin >> a >> b;


    set<string> S;

    for (int i = 0; i < a; ++i){
        string ss; cin >> ss;
        S.insert(ss);
    }

    int t = 0;

    for (int i = 0; i < b; ++i){
        string ss; cin >> ss;
        if (S.count(ss))
            t++;
    }

    a -= t;
    b -= t;

    t %= 2;
    a += t;

    cout << (a > b ? "YES" : "NO") << endl;

    return 0;
}