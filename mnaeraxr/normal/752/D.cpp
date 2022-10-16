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

    int n, k;
    cin >> n >> k;

    map< string, vector<int> > P;
    map< string, vector<int> > N;
    map< string, vector<int> > PAL;

    int ans = 0;

    for (int i = 0; i < n; ++i){
        string s; int val;
        cin >> s >> val;
        string r = s;

        reverse(r.begin(), r.end());

        if (r == s) PAL[s].push_back( val );
        else{
            if (s < r) P[s].push_back(val);
            else N[r].push_back(val);
        }
    }

    for (auto &p : P){
        vector<int> &pos = p.second;
        vector<int> &neg = N[p.first];

        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());

        int a = (int)pos.size() - 1;
        int b = (int)neg.size() - 1;

        while (a >= 0 && b >= 0){
            int cv = pos[a] + neg[b];
            ans += max(cv, 0);
            if (cv <= 0) break;
            a--; b--;
        }
    }

    int best = 0;

    for (auto &p : PAL){
        vector<int> &v = p.second;
        sort(v.begin(), v.end());

        int a = (int)v.size() - 1;

        while (a >= 1){
            if (v[a] + v[a - 1] > 0)
                ans += v[a] + v[a - 1];
            else
                break;
            a -= 2;
        }

        if (a >= 0) best = max(best, v[a]);
        if (a + 1 < (int)v.size()) best = max(best, -v[a + 1]);
    }

    cout << ans + best << endl;

    return 0;
}