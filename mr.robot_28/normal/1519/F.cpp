#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
const int N = 10;
int n, m;
int a[N];
int b[N];
int c[N][N];
const int Z = 40 * int(1e6);
int dp[Z];
struct state{
    vector <int> need;
    int v2, v1, rem;
    state(){};
    state(vector <int> need, int v1, int v2, int rem):v1(v1), v2(v2), rem(rem), need(need){};
};
int get_code(vector <int> v){
    int ans = 0;
    for(int i = 0; i < sz(v); i++)
    {
        ans = ans * 5 + v[i];
    }
    return ans;
}
int get_code(state s)
{
    int code = get_code(s.need);
    code = code * 6 + s.v2;
    code = code * 6 + s.v1;
    code = code * 5 + s.rem;
    return code;
}
vector <int> get_vector(int code, int n)
{
    vector <int> res(n);
    for(int i = n - 1; i >= 0; i--)
    {
        res[i] = code % 5;
        code /= 5;
    }
    return res;
}
state get_state(int code)
{
    int rem = code % 5;
    code /= 5;
    int v1 = code % 6;
    code /= 6;
    int v2 = code % 6;
    code /= 6;
    vector <int> need = get_vector(code, n);
    return state(need, v1, v2, rem);
}

signed main()
{
  //  ifstream cin("input1.txt.4c");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> c[i][j];
        }
    }
    for(int i = 0; i < Z; i++)
    {
        dp[i] = 1e9;
    }
    state start(vector <int> (n, 0), 0, 0, 0);
    int ans = 1e9;
    dp[get_code(start)] = 0;
    for(int i = 0; i < Z; i++)
    {
        if(dp[i] == 1e9)
        {
            continue;
        }
        state cur = get_state(i);
        for(int f = 0; f <= 4; f++)
        {
            if(cur.need[cur.v1] + f > a[cur.v1] || cur.rem + f > b[cur.v2])
            {
                continue;
            }
            int add = (f == 0 ? 0 : c[cur.v1][cur.v2]);
            state new_ = cur;
            new_.need[new_.v1] += f;
            new_.rem += f;
            if(new_.v1 == n - 1)
            {
                new_.v2++;
                new_.v1 = 0;
                new_.rem = 0;
            }
            else
            {
                new_.v1++;
            }
            if(new_.need == vector <int>(a, a + n))
            {
                ans = min(ans, dp[i] + add);
            }
            if(new_.v2 < m)
            {
                int code = get_code(new_);
                dp[code] = min(dp[code], add + dp[i]);
            }
        }
    }
    if(ans == 1e9)
    {
        ans = -1;
    }
    cout << ans;
    return 0;
}