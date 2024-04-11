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

    string a, b;
    cin >> a >> b;

    int n = (int)a.length();

    map<char,set<char>> M;

    for (int i = 0; i < n; ++i){
        char aa = a[i], bb = b[i];

        M[aa].insert(bb);
        M[bb].insert(aa);
    }

    vector<pair<char,char>> ans;

    for (auto p : M){
        if (p.second.size() > 1){
            cout << -1 << endl;
            return 0;
        }

        char aa = p.first;
        char bb = *p.second.begin();

        if (aa < bb) ans.push_back({aa, bb});
    }

    cout << ans.size() << endl;
    for (auto p : ans)
        cout << p.first << " " << p.second << endl;

    return 0;
}