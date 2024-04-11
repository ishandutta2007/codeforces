#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 2e5;


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    set <int> st;
    vector <int> cnt(n);
    for(int i = 0;i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(a > b)
        {
            swap(a, b);
        }
        if(!cnt[a])
        {
            st.insert(a);
        }
        cnt[a]++;
    }
    int q;
    cin >> q;
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 3)
        {
            cout << n - sz(st) << "\n";
        }
        else if(t == 1)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            if(u > v)
            {
                swap(u, v);
            }
            if(!cnt[u])
            {
                st.insert(u);
            }
            cnt[u]++;
        }
        else
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            if(u > v)
            {
                swap(u, v);
            }
            if(cnt[u] == 1)
            {
                st.erase(u);
            }
            cnt[u]--;
        }
    }
    return 0;
}