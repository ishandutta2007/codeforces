#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 501;
const int M = 998244353;
const int inf = 1e18 + 1;

int n, used[N], need[N];

vector<int> in[N];
vector<int> a[N];
vector<int> ans;

int kol[N], was[N];

bool check(vector<int> ans) {
    for (int i = 1; i <= n; i++)
        used[i] = 0, was[i] = 0;
    /*for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << endl;*/
    for (int i = 0; i < ans.size(); i++) {
        //cout << '*' << i  << endl;
        int pos = -1;
        for (auto id: in[ans[i]])
            if (!used[id]) {
                if (pos != -1)
                    return 0;
                pos = id;
            }
        vector<int> q1, q2;
        int kol = 0;
        used[pos] = 1;
        for (auto p: a[pos])
            if (!was[p])
                kol++, q1.pb(p);
        //cout << pos << endl;
        if (i + q1.size() > ans.size())
            return 0;
        for (int j = i; j < i + q1.size(); j++)
            q2.pb(ans[j]);
        sort(q1.begin(), q1.end());
        sort(q2.begin(), q2.end());
        /*for (int j = 0; j < q1.size(); j++)
            cout << q1[j] << ' ' << q2[j] << endl;
        */for (int j = 0; j < q1.size(); j++)
            if (q1[j] != q2[j])
                return 0;

        was[ans[i]] = 1;
    }
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ans.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
            a[i].clear(), in[i].clear(), kol[i] = 0;
        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;
            a[i].resize(x);
            for (int j = 0; j < x; j++)
                cin >> a[i][j], in[a[i][j]].pb(i), kol[a[i][j]]++;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                kol[j] = 0;
            kol[i] = 1e9;
            for (int j = 1; j < n; j++) {
                used[j] = 0;
                for (auto p: a[j])
                    kol[p]++;
            }
            bool can = 1;
            vector<int> ans;
            for (int k = 1; k < n; k++) {
                int pos = -1;
                for (int j = 1; j <= n; j++)
                    if (kol[j] == 1)  {
                        pos = j;
                        break;
                    }
                if (pos == -1) {
                    can = 0;
                    break;
                }
                kol[pos] = 0;
                for (auto id: in[pos])
                    if (!used[id]) {
                        used[id] = 1;
                        for (auto p: a[id])
                            kol[p]--;
                    }
                ans.pb(pos);
            }
            ans.pb(i);
            //cout << i << endl;
            if (can && check(ans)) {
                reverse(ans.begin(), ans.end());
                for (auto p: ans)
                    cout << p << ' ';
                cout << "\n";
                break;
            }
        }
    }
    return 0;
}