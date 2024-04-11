#include<bits/stdc++.h>
#define x first
#define y second
#define gg exit(0);
#define io ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define db printf("debug\n");
const int N = 1e5 + 10, mod = 998244353;
using namespace std;
typedef pair<int, int>PII;

int n, m, cnt[N][30];
string s[N];
void solve()
{
    cin >> n >> m;

    for(int i = 1; i <= m; i ++ ) for(int j = 0; j < 26; j ++ ) cnt[i][j] = 0;

    for(int i = 1; i <= n; i ++ )
    {
        cin >> s[i];
        s[i] = " " + s[i];
        for(int j = 1; j <= m; j ++ ) cnt[j][s[i][j] - 'a'] ++;
    }

    for(int i = 1; i <= n - 1; i ++ )
    {
        string t;
        cin >> t;
        t = " " + t;
        for(int j = 1; j <= m; j ++ ) cnt[j][t[j] - 'a'] --;
    }
            
    for(int i = 1; i <= m; i ++ )
        for(int j = 0; j < 26; j ++ ) if(cnt[i][j]) cout << (char)(j + 'a');
    cout << '\n';
}
signed main()
{
    // io;
    int T = 1;
    cin >> T;
    while(T -- )
    solve();
}