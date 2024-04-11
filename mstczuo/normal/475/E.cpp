# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>
# include <stack>

using namespace std;
const int N = 300010;

int low[N], dfn[N], DFS_cnt;
int v[N], d[N], cnt[N], tot[N];
vector<int> a[N], b[N];
stack<int> st;
int components = 0;

void tarjan(int x,int fa) {
    dfn[x] = low[x] = ++DFS_cnt;
    st.push(x);
    for(int i = 0; i <(int)a[x].size(); i++) {
        int y = a[x][i];
        if(y == fa) continue;
        if(dfn[y]) low[x] = min(low[x], dfn[y]);
        else {
            tarjan(y, x);
            low[x] = min(low[x], low[y]);
        }
    }

    if(dfn[x] != low[x]) return;

    components ++;
    while(true) {
        int y = st.top();
        st.pop();
        v[components] += 1;
        d[y] = components;
        if(x == y) break;
    }
}

void calc(int x,int fa) {
    tot[x] = v[x] * v[x];
    cnt[x] = v[x];
    for(int i = 0; i < (int)b[x].size(); ++i) {
        int y = b[x][i];
        if(y == fa) continue;
        calc(y, x);
        tot[x] += v[x] * cnt[y];
        tot[x] += tot[y];
        cnt[x] += cnt[y];
    }
}

int optima(vector<int> &a) {
    static bool f[N]; 
    int sum = 0;
    int n = a.size();
    for(int i = 0; i < n; ++i) sum += a[i];
    for(int j = 0; j <= sum; ++j) f[j] = 0;
    f[0] = 1;
    for(int i = 0; i < n; ++i)
        for(int j = sum; j >= a[i]; --j)
            f[j] |= f[j - a[i]];
    int ans = 0;
    for(int j = 0; j <= sum; ++j)
        if(f[j]) ans = max(ans, j * (sum - j));
    return ans;
}

int main() {
//    freopen("in","r",stdin);
    int n, m, x, y;
    cin >> n >> m;
    while(m--) {
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }

    for(int i = 1; i <= n; ++i)
        if(!d[i]) tarjan(i, 0);

    for(int x = 1; x <= n; ++x)
        for(int i = 0; i < (int)a[x].size(); ++i) {
            int y = a[x][i];
            if(d[x] >= d[y]) continue;
            b[d[x]].push_back(d[y]);
            b[d[y]].push_back(d[x]);
        }

    int ans = 0;
    for(int x = 1; x <= components; ++x) {
        int res = v[x] * v[x];
        vector<int> ss;
        for(int i = 0; i < (int)b[x].size(); ++i) {
            int y = b[x][i];
            calc(y, x);
            res += v[x] * cnt[y];
            res += tot[y];
            ss.push_back(cnt[y]);
        }
        res += optima(ss);
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}