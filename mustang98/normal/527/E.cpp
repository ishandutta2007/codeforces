#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;
typedef long long ll;

const int max_n = 100111, max_m = 500111;

vector<pair<int, int> > v[max_n];
int n, m;
bool vise[max_m];
bool bad[max_n];

vector<int> ans;

void find_euler_cycle()
{
    stack<int> st;
    st.push(0);
    while(!st.empty())
    {
        int cur = st.top();
        if (v[cur].size() == 0)
        {
            ans.pb(cur);
            st.pop();
            continue;
        }

        pair<int, int> p = v[cur].back();
        v[cur].pop_back();
        if (vise[p.F]) continue;
        vise[p.F] = true;
        st.push(p.S);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    int a, b, cure = 0;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &a, &b);
        a--;
        b--;
        v[a].push_back(mp(cure, b));
        v[b].push_back(mp(cure, a));
        ++cure;
    }

    vector<int> odd;
    for (int i = 0; i < n; ++i) {
        if (v[i].size() % 2 == 1) {
            odd.pb(i);
        }
    }

    for (int i = 0; i < odd.size(); i += 2) {
        a = odd[i];
        b = odd[i + 1];
        v[a].push_back(mp(cure, b));
        v[b].push_back(mp(cure, a));
        ++cure;
    }

    int numnot4 = 0, lastnot4 = -1;
    for (int i = 0; i < n; ++i) {
        if (v[i].size() % 4 != 0) {
            numnot4++;
            bad[i] = true;
            lastnot4 = i;
        }
    }
    if (numnot4 % 2 == 1) {
        bad[lastnot4] = false;
        v[lastnot4].pb(mp(cure, lastnot4));
        v[lastnot4].pb(mp(cure, lastnot4));
    }

    find_euler_cycle();

    printf("%d\n", ans.size() - 1);

    bool isrev = false;
    for (int i = 0; i < ans.size() - 1; ++i) {
        //cout << ans[i] << ' ';
        int cur = ans[i];
        if (bad[cur]) {
            bad[cur] = false;
            isrev = !isrev;
        }
        if (isrev) {
            printf("%d %d\n", ans[i + 1] + 1, ans[i] + 1);
        }
        else {
            printf("%d %d\n", ans[i] + 1, ans[i + 1] + 1);
        }
    }
    return 0;
}