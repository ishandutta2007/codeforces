#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 4e5 + 1;

map<string, int> m;
int cur = 0;
int n, indeg[N], outdeg[N];
vector<int> ans, g[N];
string go[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        string q = "";
        q += s[0];
        q += s[1];
        if (m[q] == 0)
        {
            cur++;
            m[q] = cur;
            go[cur] = q;
        }
        string p = "";
        p += s[1];
        p += s[2];
        if (m[p] == 0)
        {
            cur ++;
            m[p] = cur;
            go[cur] = p;
        }
        g[m[q]].pb(m[p]);
        indeg[m[p]]++;
        outdeg[m[q]]++;
    }
    int start = 1;
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 1; i <= cur; i++)
    {
        if (abs(indeg[i] - outdeg[i]) >= 2)
        {
            cout << "NO";
            return 0;
        }
        if (indeg[i] == outdeg[i] - 1)
        {
            start = i;
            c1++;
        }
        if (indeg[i] == outdeg[i] + 1)
            c2++;
        if (indeg[i] == outdeg[i])
            c3++;
    }
    //cout << c1 << ' '  << c2 << ' ' << c3 << endl;
    if (c1 + c2 + c3 != cur)
    {
        cout << "NO";
        return 0;
    }
    if (!((c1 == 1 && c2 == 1) || (c1 == 0 && c2 == 0)))
    {
        cout << "NO";
        return 0;
    }
    stack<int> s;
    s.push(start);
    while (!s.empty())
    {
        int v = s.top();
        if (g[v].size() == 0)
        {
            ans.pb(v);
            s.pop();
            continue;
        }
        s.push(g[v].back());
        int t = g[v].back();
        g[v].pop_back();
        v = t;
    }
    if (ans.size() + 1 != n + 2)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << go[ans[i]][0];
    cout << go[ans.back()][1];
    return 0;
}