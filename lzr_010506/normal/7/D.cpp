#include <bits/stdc++.h>
#define ll long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 5000010;
int p[N << 1], dp[N], len;
char ch[N], st[N << 1];
void manacher()
{
    int i, id, mx = 0;
    rep(i, 1, len - 1)
    {
        p[i] = mx > i ? min(mx - i, p[2 * id - i]) : 1;
        while(st[i + p[i]] == st[i - p[i]]) p[i] ++;
        if(i + p[i] > mx) mx = i + p[i], id = i;
    }
}
int main()
{
    int i,ans,n;
    scanf("%s", ch);
    len = strlen(ch);
    n = len;
    st[0] = '$', st[1] = '#';
    rep(i, 0, len - 1)
        st[2 * i + 2] = ch[i], st[2 * i + 3] = '#';
    len = 2 * len + 2;
    ans = 0;
    manacher();
    ans = dp[0] = 1;
    rep(i, 1, n - 1)
    {
        if(p[i + 2] - 1 >= i + 1)
        {
            if(i & 1) dp[i] = dp[i / 2] + 1;
            else dp[i] = dp[i / 2 - 1] + 1;
        }
        ans += dp[i];
    }
    printf("%d\n",ans);

    return 0;
}